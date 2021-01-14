#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//•	Да се напише програма на C, която реализира командата cat (без параметри)

int main(int argc, char** argv)
{
        int fd1;
        fd1 = open("f1.txt", O_RDONLY);
        char buffer[1];

        while(read(fd1, buffer, 1)){
            write(1, buffer, 1);
        }
        
        close(fd1);
}