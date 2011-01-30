#include <stdio.h>

#include "t3-strace.h"

void	print_access(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)syscall_id;
  putchar('"');
  print_path(pid, regs->ebx); // path
  printf("\", ");
  printf("%ld", regs->ecx); // flags
}
