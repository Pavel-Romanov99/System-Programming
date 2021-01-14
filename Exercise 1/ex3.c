#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//•	Да се напише програма на C, която реализира командата cat >>файл

int main(int argc, char** argv)
{
      int fd1;
      fd1 = open("f3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
      char buffer[100];

      while(read(0, buffer, 1) > 0){
          write(fd1, buffer, 1);
      }
      close(fd1);
}