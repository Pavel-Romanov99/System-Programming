#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*1.	Напишете програма на Си, която отваря файл за четене, дублира дескритора, 
        последователно чете от двата дескриптора и извежда прочетеното на екрана. 
        Затваря оригиналния дексриптор и продължава за чете от дублирания.
 */

int main(int argc, char* argv[])
{
    int fd = open("fff", O_CREAT | O_WRONLY);

    if(fd == -1){
        printf("error\n");
        exit(1);
    }

    int d = dup(fd);

    write(fd, "hello what are", 14);
    write(d, "you doing", 9);

    close(fd);

    write(d, "lol", 3);

    printf("\n");


}