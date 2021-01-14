#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
Приема число и има на файл като аргумент и извежда номера на реда от файла, който е прочетен
 */

int main(int argc, char* argv[])
{
    char* p;
    long line = strtol(argv[1], &p, 10);
    int n = line;
    int fd1 = open(argv[2], O_CREAT | O_RDONLY);
    char buffer[1];

    if(fd1 < 0){
        printf("error\n");
        exit(1);
    }

    printf("line = %d\n", n);

    int counter = 1;
    while(read(fd1, buffer, 1) > 0){
       
        if(counter == n){
            write(1, buffer, 1);
        }
        if(buffer[0] == '\n'){
            counter++;
        }
    }

    close(fd1);
}