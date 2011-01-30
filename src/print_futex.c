#include <linux/futex.h>
#include <stdio.h>

#include "t3-strace.h"

static t_flag	flags[] = {
  {FUTEX_WAIT, "FUTEX_WAIT"},
  {FUTEX_WAKE, "FUTEX_WAKE"},
  {FUTEX_FD, "FUTEX_FD"},
  {FUTEX_REQUEUE, "FUTEX_REQUEUE"},
  {FUTEX_CMP_REQUEUE, "FUTEX_CMP_REQUEUE"},
  {FUTEX_WAKE_OP, "FUTEX_WAKE_OP"},
  {FUTEX_LOCK_PI, "FUTEX_LOCK_PI"},
  {FUTEX_UNLOCK_PI, "FUTEX_UNLOCK_PI"},
  {FUTEX_TRYLOCK_PI, "FUTEX_TRYLOCK_PI"},
#ifdef FUTEX_WAIT_BITSET
  {FUTEX_WAIT_BITSET, "FUTEX_WAIT_BITSET"},
#endif //!FUTEX_WAIT_BITSET
#ifdef FUTEX_WAKE_BITSET
  {FUTEX_WAKE_BITSET, "FUTEX_WAKE_BITSET"},
#endif //!FUTEX_WAKE_BITSET
#ifdef FUTEX_WAIT_REQUEUE_PI
  {FUTEX_WAIT_REQUEUE_PI, "FUTEX_WAIT_REQUEUE_PI"},
#endif //!FUTEX_WAIT_REQUEUE_PI
#ifdef FUTEX_CMP_REQUEUE_PI
  {FUTEX_CMP_REQUEUE_PI, "FUTEX_CMP_REQUEUE_PI"},
#endif //!FUTEX_CMP_REQUEUE_PI
  {FUTEX_PRIVATE_FLAG, "FUTEX_PRIVATE_FLAG"},
#ifdef FUTEX_CLOCK_REALTIME
  {FUTEX_CLOCK_REALTIME, "FUTEX_CLOCK_REALTIME"},
#endif //!FUTEX_CLOCK_REALTIME
  {FUTEX_CMD_MASK, "FUTEX_CMD_MASK"},
  {FUTEX_WAIT_PRIVATE, "FUTEX_WAIT_PRIVATE"},
  {FUTEX_WAKE_PRIVATE, "FUTEX_WAKE_PRIVATE"},
  {FUTEX_REQUEUE_PRIVATE, "FUTEX_REQUEUE_PRIVATE"},
  {FUTEX_CMP_REQUEUE_PRIVATE, "FUTEX_CMP_REQUEUE_PRIVATE"},
  {FUTEX_WAKE_OP_PRIVATE, "FUTEX_WAKE_OP_PRIVATE"},
  {FUTEX_LOCK_PI_PRIVATE, "FUTEX_LOCK_PI_PRIVATE"},
  {FUTEX_UNLOCK_PI_PRIVATE, "FUTEX_UNLOCK_PI_PRIVATE"},
  {FUTEX_TRYLOCK_PI_PRIVATE, "FUTEX_TRYLOCK_PI_PRIVATE"},
#ifdef FUTEX_WAKE_BITS
  {FUTEX_WAIT_BITSET_PRIVATE, "FUTEX_WAIT_BITSET_PRIVATE"},
  {FUTEX_WAKE_BITSET_PRIVATE, "FUTEX_WAKE_BITSET_PRIVATE"},
#endif //!FUTEX_WAKE_BITS
#ifdef FUTEX_WAIT_REQUEUE_PI_PRIVATE
  {FUTEX_WAIT_REQUEUE_PI_PRIVATE, "FUTEX_WAIT_REQUEUE_PI_PRIVATE"},
#endif //!FUTEX_WAIT_REQUEUE_PI_PRIVATE
#ifdef FUTEX_CMP_REQUEUE_PI_PRIVATE
  {FUTEX_CMP_REQUEUE_PI_PRIVATE, "FUTEX_CMP_REQUEUE_PI_PRIVATE"},
#endif //!FUTEX_CMP_REQUEUE_PI_PRIVATE
  {-1, NULL}
};

void	print_futex(pid_t pid, long syscall_id, t_urs *regs)
{
  (void)pid;
  (void)syscall_id;
  printf("0x%06lx, ", regs->ebx);
  print_flags(flags, regs->ecx);
  printf(", %ld", regs->edx);
}
