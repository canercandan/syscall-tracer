#include <signal.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/ptrace.h>

#include "t3-strace.h"

void		print_syscall(pid_t pid, long syscall_id, t_urs *regs)
{
  t_syscall	*sys;

  if (!(syscall_id >= 0 && syscall_id < MAX_SYSCALLS))
    {
      printf("error");
      return;
    }
  sys = &g_syscalls[syscall_id];
  printf("%s(", sys->name);
  if (sys->print_args == NULL)
    {
      printf("0x%06lx, 0x%06lx, 0x%06lx",
	     regs->ebx, regs->ecx, regs->edx);
    }
  else
    sys->print_args(pid, syscall_id, regs);
  printf(")\t= ");
  printf((sys->print_retval == 1) ? "0x%06lx" : "%ld", regs->eax);
  if (regs->eax == -1 || regs->eax == -2)
    {
/*       siginfo_t	siginfo; */
/*       ptrace(PTRACE_GETSIGINFO, pid, 0, &siginfo); */
/*       printf("errno: [%d] ", siginfo.si_errno); */
/*       printf("signo: [%d] ", siginfo.si_signo); */
/*       printf("sigcode: [%d] ", siginfo.si_code); */
      printf(" ENOENT");
    }
  printf("\n");
}
