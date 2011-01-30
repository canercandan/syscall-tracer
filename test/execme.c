#include <unistd.h>

int	main(void)
{
  char	*args[] = {"/bin/ls", NULL};

  execvp(*args, args);

  return (0);
}
