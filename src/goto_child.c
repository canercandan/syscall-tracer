#include <unistd.h>
#include <stdio.h>
#include <sys/ptrace.h>

#include "t3-strace.h"

void	goto_child(int ac, char **av)
{
  if (ac < 1)
    return;
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    {
      perror("traceme: ptrace(PTRACE_TRACEME, ...): Operation not permitted");
      exit(-1);
    }
  if (execvp(*av, av) == -1)
    perror("execvp");
}
