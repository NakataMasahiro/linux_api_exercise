#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 11


int main(int argc, char *argv[])
{
  char buf[BUF_SIZE];

  int inputFd = open (argv[1], O_RDONLY);

  read(inputFd, buf, BUF_SIZE);
 
  close(inputFd);

  for (unsigned int i = 0; i < BUF_SIZE; i++)
    printf("%c", buf[i]);

  return 0;

}
