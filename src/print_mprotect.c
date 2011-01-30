#include <sys/mman.h>
#include <stdio.h>

#include "t3-strace.h"

static t_flag	flags[] = {
  {PROT_NONE, "PROT_NONE"},
  {PROT_READ, "PROT_READ"},
  {PROT_WRITE, "PROT_WRITE"},
  {PROT_EXEC, "PROT_EXEC"},
  {-1, NULL}
};

void	print_mprotect(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  printf("0x%06lx, %ld, ",
	 regs->ebx, regs->ecx);
  print_flags(flags, regs->edx);
}
