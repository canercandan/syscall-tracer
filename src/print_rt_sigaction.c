#include <signal.h>
#include <stdio.h>

#include "t3-strace.h"

static t_flag	flags[] = {
/*   {SIGRTMIN, "SIGRTMIN"}, */
/*   {SIGRTMAX, "SIGRTMAX"}, */
  {-1, NULL}
};

void	print_rt_sigaction(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  print_flags(flags, regs->ebx);
  printf(", %ld, %ld", regs->ecx, regs->edx);
}
