#include <stdio.h>

#include "t3-strace.h"

void	usage(char *appname)
{
  if (g_flags['h'] == NULL)
    return;
  printf("Usage: %s [-h] [-v] {[-p pid] | [-e cmd]}\n", appname);
  exit(0);
}
