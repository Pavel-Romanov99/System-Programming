#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
•	през fd2 записва “Hello world” в него
•	през fd3 прочита 6 байта и изписва прочетеното на стандартния изход
•	през fd1 прочита 5 байта  и изписва прочетеното на стандартния изход
•	през fd3 записва “chil”  в него 
•	през fd2 записва “!!!”  в него
•	през fd1  прочита 9 байта  и изписва прочетеното на стандартния изход

 */

int main(int argc, char* argv[])
{
    int fd1, fd2, fd3;

    fd1 = open("fff", O_CREAT | O_RDONLY, 0666);
    fd2 = open("fff", O_WRONLY);
    fd3 = open("fff", O_RDWR);

    char buffer[10];

    write(fd2, "Hello, world", 12);

    read(fd3, buffer, 6);
    write(1, buffer, 6);
    printf("\n");

    read(fd1, buffer, 5);
    write(1, buffer, 8);
    printf("\n");

    write(fd3, "chil", 4);

    write(fd2, "!!!", 3);

    read(fd1, buffer, 9);
    write(1, buffer, 9);
    printf("\n");
}