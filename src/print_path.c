#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>

#include "t3-strace.h"

static const long	long_size = sizeof(long);

void	print_path(pid_t pid, long addr)
{
  int	i;
  long	c;
  char	str[1024] = {0};
  char	*laddr;

  if (addr <= 0)
    return;
  laddr = str;
  for (i = 0;; i++, laddr += long_size)
    {
      if ((c = ptrace(PTRACE_PEEKDATA, pid, addr + i * 4, NULL)) == -1)
	{
	  perror("peekdata: ptrace(PTRACE_PEEKDATA, ...): Operation not permitted");
	  exit(-1);
	}
      memcpy(laddr, &c, long_size);
      if (memchr(laddr, 0, long_size) != NULL)
	break;
    }
  str[i * 4] = '\0';
  for (i = 0; str[i] != 0; i++)
    print_char(str[i]);
}
