#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int fd;
   fd = open("aa", O_RDONLY);

   if(fd < 0){
       printf("Error\n");
       exit(1);
   }
   
   char buffer[16];

   for (int i = 5; i > 0; i--)
   {
       lseek(fd, 3, SEEK_CUR);
       read(fd, buffer, 16);
       printf("%s\n", buffer);
   }
   close(fd);

}