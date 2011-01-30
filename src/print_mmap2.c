#include <sys/mman.h>
#include <stdio.h>

#include "t3-strace.h"

static t_flag	prot_flags[] = {
  {PROT_READ, "PROT_READ"},
  {PROT_WRITE, "PROT_WRITE"},
  {PROT_EXEC, "PROT_EXEC"},
  {PROT_NONE, "PROT_NONE"},
  {PROT_GROWSDOWN, "PROT_GROWSDOWN"},
  {PROT_GROWSUP, "PROT_GROWSUP"},
  {-1, NULL}
};

static t_flag	map_flags[] = {
  {MAP_SHARED, "MAP_SHARED"},
  {MAP_PRIVATE, "MAP_PRIVATE"},
#ifdef __USE_MISC
  {MAP_TYPE, "MAP_TYPE"},
#endif //!__USE_MISC
  {MAP_FIXED, "MAP_FIXED"},
#ifdef __USE_MISC
  {MAP_FILE, "MAP_FILE"},
  {MAP_ANONYMOUS, "MAP_ANONYMOUS"},
  {MAP_ANON, "MAP_ANON"},
# ifdef MAP_32BIT
  {MAP_32BIT, "MAP_32BIT"},
# endif //!MAP_32BIT
#endif //!__USE_MISC
#ifdef __USE_MISC
  {MAP_GROWSDOWN, "MAP_GROWSDOWN"},
  {MAP_DENYWRITE, "MAP_DENYWRITE"},
  {MAP_EXECUTABLE, "MAP_EXECUTABLE"},
  {MAP_LOCKED, "MAP_LOCKED"},
  {MAP_NORESERVE, "MAP_NORESERVE"},
  {MAP_POPULATE, "MAP_POPULATE"},
  {MAP_NONBLOCK, "MAP_NONBLOCK"},
#ifdef MAP_STACK
  {MAP_STACK, "MAP_STACK"},
#endif //!MAP_STACK
  {-1, NULL}
#endif //!__USE_MISC
};

void	print_mmap2(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  printf("%08lx, %ld, ", regs->ebx, regs->ecx);
  print_flags(prot_flags, regs->edx); // prot flags
  printf(", ");
  print_flags(map_flags, regs->edx); // map flags
  printf(", %ld, %ld", regs->esi, regs->edi);
}
