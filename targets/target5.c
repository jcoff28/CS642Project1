#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char *arg)
{
  char buf[400];

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x.%08x|%s|\n");

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x.%08x|%s|\n");

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x.%08x|%s|\n");
  
  // printf ("\xb4\xfe\xff\xbf_%08x.%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x.%08x|%s|\n");

  // printf ("\xb4\xfe\xff\xbf_%08x.%08x|%s|\n");
  // printf ("g\xb4\xfe\xff\xbf_%08x.%08x|%s|\n");
  // printf ("gg\xb4\xfe\xff\xbf_%08x.%08x|%s|\n");
  // printf ("ggg\xb4\xfe\xff\xbf_%08x.%08x|%s|\n");


  snprintf(buf, sizeof buf, arg);
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf(stderr, "target5: argc != 2\n");
      exit(EXIT_FAILURE);
    }
  foo(argv[1]);

  return 0;
}
