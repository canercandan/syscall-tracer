#include <ctype.h>
#include <stdio.h>

#include "t3-strace.h"

void	print_char(char c)
{
  if (c == '\n')
    printf("\\n");
  else if (!isprint(c))
    printf("\\%o", c);
  else
    putchar(c);
}
