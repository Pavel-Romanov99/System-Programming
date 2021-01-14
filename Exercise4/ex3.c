#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	3.В задача 2 се създава файл с име f1 и се пранасочва стандартния изход в него :
•	чрез open
•	чрез системен примитив dup

 */

int main(int argc, char* argv[])
{

    int fd = open(argv[1], O_CREAT | O_RDWR, 0666);

    if(fd < 0){
        write(2, "Error opening file", 18);
        exit(1);
    } 

    dup2(fd, 1);

    printf("hello what is this\n ");
    printf("hello what is this\n ");

    

}