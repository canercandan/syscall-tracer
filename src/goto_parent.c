#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "t3-strace.h"

static void	loop_it(pid_t pid, int *toggle, long *syscall_id)
{
  int		status;
  t_urs		regs;

  wait(&status);
  if (WIFEXITED(status))
    exit(0);
  if (*toggle == 0)
    {
      ptrace(PTRACE_GETREGS, pid, NULL, &regs);
      *syscall_id = regs.orig_eax;
      if (*syscall_id >= 0)
	{
	  print_syscall(pid, *syscall_id, &regs);
	  *toggle = 1;
	}
    }
  else
    *toggle = 0;
  if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
    {
      perror("singlestep: ptrace(PTRACE_SINGLESTEP, ...): Operation not permitted");
      exit(-1);
    }
}

void	goto_parent(pid_t pid)
{
  long	syscall_id;
  int	toggle;

  toggle = 0;
  while(1)
    loop_it(pid, &toggle, &syscall_id);
}
