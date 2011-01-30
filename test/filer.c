#include <fcntl.h>

int	main(void)
{
  open("toto.txt", O_WRONLY | O_CREAT);

  return (0);
}
