#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 11


int main(int argc, char *argv[])
{
  char buf[BUF_SIZE];
  int number;

  int inputFd = open (argv[1], O_RDONLY);
  number = errno;

  if(inputFd == -1)
  {
    perror("file open error string by perror!");
    printf("file open error string by strerror: %s\n", strerror(number));

    printf("print error code: %d\n", number);
  }
  else
  {
    read(inputFd, buf, BUF_SIZE);
 
    close(inputFd);

    for (unsigned int i = 0; i < BUF_SIZE; i++)
      printf("%c", buf[i]);
  }
  return 0;

}
