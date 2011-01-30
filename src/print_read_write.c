#include <stdio.h>

#include "t3-strace.h"

void	print_read_write(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)syscall_id;
  printf("%ld", regs->ebx); // fd
  printf(", ");
  print_buf(pid, regs->ecx, regs->edx); // buf
  printf(", ");
  printf("%ld", regs->edx); // count
}
