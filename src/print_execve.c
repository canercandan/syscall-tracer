#include <stdio.h>

#include "t3-strace.h"

void	print_execve(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  if (regs->ebx > 0)
    {
      putchar('"');
      print_path(pid, regs->ebx);
      putchar('"');
    }
}
