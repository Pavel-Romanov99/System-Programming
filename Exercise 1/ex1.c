#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//Да се напише програма на C, която реализира командата cp файл1 файл2

int main(int argc, char** argv)
{
        int fd1, fd2;
        fd1 = open("f1.txt", O_RDONLY);
        fd2 = open("f2.txt", O_WRONLY | O_CREAT, 0666);
        char buffer[1];

        while(read(fd1, buffer, 1)){
            write(fd2, buffer, 1);
        }
        close(fd1);
        close(fd2);

        return 0;
}
