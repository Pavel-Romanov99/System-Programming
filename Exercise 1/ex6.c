#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


//•	Да се напише програма на C, която реализира командата cut -cm-n файл
//(m и n да се четат от входа)


int main(int argc, char** argv)
{
    int fd1;
    fd1 = open("f1.txt", O_RDONLY);
    char buffer[1];
    int counter = 0;

    int m, n;

    scanf("%d %d", &m, &n);


    while(read(fd1, buffer, 1)){
        if(counter >= m && counter < n){
            write(1, buffer, 1);
        }
        counter++;
    }
    printf("\n");

    close(fd1);
}
