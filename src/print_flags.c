#include <stdio.h>

#include "t3-strace.h"

void	print_flags(t_flag *flags, long addr)
{
  int	i;
  int	found;

  for (i = 0, found = 0; flags[i].mask >= 0; i++)
    {
      if ((addr & flags[i].mask) != flags[i].mask)
	continue;
      if (found == 1)
	putchar('|');
      else
	found = 1;
      printf("%s", flags[i].string);
    }
}
