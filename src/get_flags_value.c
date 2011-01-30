#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "t3-strace.h"

//! get flags value and return the next aguments position
int	get_flags_value(int ac, char **av)
{
  int	c;

  opterr = 0;
  while ((c = getopt(ac, av, OPTIONS)) != -1)
    {
      if (c == '?')
	{
	  if (optopt == 'p' || optopt == 'e')
	    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
	  else if (isprint(optopt))
	    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
	  else
	    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
	  exit(-1);
	}
      g_flags[c] = (optarg == NULL) ? (void*)1 : optarg;
    }
  return (optind);
}
