#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

   int fd;
   fd = open(argv[1], O_RDONLY);

   if(fd < 0){
       printf("Error\n");
       exit(1);
   }

   char buffer[16];

   for (int i = 5; i > 0; i--)
   {
       read(fd, buffer, 16);
       write(1, buffer, 16);
       printf("\n");
   }
   close(fd);

}