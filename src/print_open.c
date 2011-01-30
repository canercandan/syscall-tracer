#include <fcntl.h>
#include <stdio.h>

#include "t3-strace.h"

static t_flag	flags[] = {
  {O_ACCMODE, "O_ACCMODE"},
  {O_RDONLY, "O_RDONLY"},
  {O_WRONLY, "O_WRONLY"},
  {O_RDWR, "O_RDWR"},
  {O_CREAT, "O_CREAT"},
  {O_EXCL, "O_EXCL"},
  {O_NOCTTY, "O_NOCTTY"},
  {O_TRUNC, "O_TRUNC"},
  {O_APPEND, "O_APPEND"},
  {O_NONBLOCK, "O_NONBLOCK"},
  {O_NDELAY, "O_NDELAY"},
  {O_SYNC, "O_SYNC"},
  {O_FSYNC, "O_FSYNC"},
  {O_ASYNC, "O_ASYNC"},
#ifdef __USE_GNU
  {O_DIRECT, "O_DIRECT"},
  {O_DIRECTORY, "O_DIRECTORY"},
  {O_NOFOLLOW, "O_NOFOLLOW"},
  {O_NOATIME, "O_NOATIME"},
  {O_CLOEXEC, "O_CLOEXEC"},
#endif //!__USE_GNU
  {O_DSYNC, "O_DSYNC"},
  {O_RSYNC, "O_RSYNC"},
#ifdef __USE_LARGEFILE64
  {O_LARGEFILE, "O_LARGEFILE"},
#endif //!__USE_LARGEFILE64
  {-1, NULL}
};

void	print_open(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)syscall_id;
  putchar('"');
  print_path(pid, regs->ebx); // path
  printf("\", ");
  print_flags(flags, regs->ecx); // flags
  if (regs->edx > 0777)
    return;
  printf(", ");
  printf("0%lo", regs->edx); // mode
}
