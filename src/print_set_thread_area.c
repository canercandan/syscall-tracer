#include <stdio.h>

#include "t3-strace.h"

void	print_set_thread_area(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  printf("0x%06lx, 0x%lx", regs->ebx, regs->ecx);
}
