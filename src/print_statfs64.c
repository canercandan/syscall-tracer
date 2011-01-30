#include <stdio.h>

#include "t3-strace.h"

void	print_statfs64(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  printf("%ld", regs->ebx);
}
