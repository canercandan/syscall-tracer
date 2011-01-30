#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>

#include "t3-strace.h"

static const long	long_size = sizeof(long);

static void	print_str(char *str, long len)
{
  int		i;
  int		toolong;

  putchar('"');
  toolong = 0;
  for (i = 0; i < len; i++)
    {
      if (i == 32)
	{
	  toolong = 1;
	  printf("\"...");
	  break;
	}
      print_char(str[i]);
    }
  if (toolong == 0)
    putchar('"');
}

void	print_buf(pid_t pid, long addr, long len)
{
  int	i;
  int	j;
  long	c;
  char	*str;
  char	*laddr;

  str = (char*)malloc((len + 1) * sizeof(*str));
  laddr = str;
  for (i = 0, j = len / long_size + 1; i < j; i++, laddr += long_size)
    {
      if ((c = ptrace(PTRACE_PEEKDATA, pid, addr + i * 4, NULL)) == -1)
	{
	  perror("peekdata: ptrace(PTRACE_PEEKDATA, ...): Operation not permitted");
	  exit(-1);
	}
      memcpy(laddr, &c, long_size);
    }
  str[len] = '\0';
  print_str(str, len);
  free(str);
}
