#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>

#include "t3-strace.h"

void	*g_flags[255] = {NULL};

static void	with_command(int ac, char **av, int pos)
{
  pid_t		pid;

  pid = fork();
  if (pid == -1)
    exit(-1);
  if (pid == 0)
    {
      if (g_flags['e'] == NULL)
	goto_child(ac - pos, av + pos);
      else
	goto_child(ac - pos + 1, av + pos - 1);
    }
  else
    goto_parent(pid);
}

static void	with_pid(void)
{
  pid_t		pid;

  pid = (pid_t)atoi(g_flags['p']);
  if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
    {
      perror("attach: ptrace(PTRACE_ATTACH, ...): Operation not permitted");
      exit(-1);
    }
  goto_parent(pid);
  if (ptrace(PTRACE_DETACH, pid, NULL, NULL) == -1)
    {
      perror("detach: ptrace(PTRACE_DETACH, ...): Operation not permitted");
      exit(-1);
    }
}

int	main(int ac, char **av)
{
  int	pos;

  if (ac < 2)
    return (-1);
  pos = get_flags_value(ac, av);
  usage(av[0]);
  if (g_flags['p'] == NULL)
    with_command(ac, av, pos);
  else
    with_pid();
  return (0);
}
