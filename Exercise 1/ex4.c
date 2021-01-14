#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* •	Да се напише програма на C, която реализира командата 
        wc [-cwl ] [файл1 файл2 ....файлN ] */


int main(int argc, char** argv)
{
      int fd1;
      fd1 = open("f1.txt", O_RDONLY);

      int bits = 0;
      int lines = 0;
      int words = 0;

      char buffer[1];

      while(read(fd1, buffer, 1)){
          if(buffer[0] == '\n'){
              lines++;
          }
          else if(buffer[0] == ' '){
              words++;
          }
          bits++;
      }

      printf("Number of lines is: %d\n", ++lines);
      printf("Number of words is: %d\n", words + lines);
      printf("Number of bits is: %d\n", bits);

      close(fd1);

}