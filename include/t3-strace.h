#ifndef __STRACE_H__
# define __STRACE_H__

# include <sys/user.h>
# include <sys/reg.h>
# include <stdlib.h>

//! defines
# define OPTIONS	"hvp:e:"
# define MAX_SYSCALLS	337

//! typedefs
typedef struct user_regs_struct	t_urs;
typedef void (*t_callback)(pid_t, long, t_urs*);

//! structures
typedef struct	s_syscall
{
  char		*name;
  t_callback	print_args;
  int		print_retval;
}		t_syscall;

typedef struct	s_flag
{
  long		mask;
  char		*string;
}		t_flag;

//! globals
extern t_syscall	g_syscalls[];
extern void		*g_flags[255];

//! functions
void	goto_child(int ac, char **av);
void	goto_parent(pid_t);
void	print_syscall(pid_t, long, t_urs*);
int	get_flags_value(int ac, char **av);
void	usage(char *appname);
void	print_char(char c);
void	print_path(pid_t pid, long addr);
void	print_flags(t_flag*, long addr);
void	print_buf(pid_t pid, long addr, long len);

void	print_read_write(pid_t, long, t_urs*);
void	print_open(pid_t, long, t_urs*);
void	print_close(pid_t, long, t_urs*);
void	print_munmap(pid_t, long, t_urs*);
void	print_access(pid_t, long, t_urs*);
void	print_mprotect(pid_t, long, t_urs*);
void	print_set_tid_address(pid_t, long, t_urs*);
void	print_set_robust_list(pid_t, long, t_urs*);
void	print_futex(pid_t, long, t_urs*);
void	print_rt_sigaction(pid_t, long, t_urs*);
void	print_getrlimit(pid_t, long, t_urs*);
void	print_uname(pid_t, long, t_urs*);
void	print_statfs64(pid_t, long, t_urs*);
void	print_brk(pid_t, long, t_urs*);
void	print_fstat64(pid_t, long, t_urs*);
void	print_stat64(pid_t, long, t_urs*);
void	print_set_thread_area(pid_t, long, t_urs*);
void	print_ioctl(pid_t, long, t_urs*);
void	print_execve(pid_t, long, t_urs*);
void	print_mmap2(pid_t, long, t_urs*);

#endif // !__STRACE_H__
