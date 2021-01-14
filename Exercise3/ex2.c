#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* 
•	през fd3 записва “Hello” в него
•	през fd2 записва „worlds” в него
•	през fd1 прочита 6 байта  и изписва прочетеното на стандартния изход
•	затваря  fd2
•	през fd3 записва “oops”  в него
•	през fd1  прочита 6 байта  и изписва прочетеното на стандартния изход
*/

int main(int argc, char* argv[])
{
    int fd1, fd2, fd3;

    fd1 = open("fff", O_CREAT | O_RDONLY, 0666);
    fd2 = open("fff", O_WRONLY);
    fd3 = open("fff", O_RDWR);

    char buffer[10];

    write(fd3, "hello", 6);

    write(fd2, "worlds", 7);

    read(fd1, buffer, 6);
    write(1, buffer, 6);

    close(fd2);

    write(fd3, "oops", 5);

    read(fd1, buffer, 6);
    write(1, buffer, 6);

    close(fd1);
    close(fd3);
}