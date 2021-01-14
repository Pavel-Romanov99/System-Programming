#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//•	Да се напише програма на C, която реализира командата head -10l файл

int main(int argc, char** argv)
{
    int fd1;
    fd1 = open("f1.txt" ,O_RDONLY);
    char buffer[1];
    int lines = 0;

    while(read(fd1, buffer, 1) && lines < 10){
        write(1, buffer, 1);
        if(buffer[0] == '\n'){
            lines++;
        }
    }
    close(fd1);
}
