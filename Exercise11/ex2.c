#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
    2.	Да се напише програма на Си, която прави канал между 2 команди подадени като параметри 
    в командния ред/ без опции и аргументи
 */

int main(int argc, char* argv[])
{   
    int fd[2];
    pipe(fd);
    int pid = fork();

    if( pid == 0){
        close(1);
        dup(fd[1]);
        close(fd[0]);
        close(fd[1]);
        execlp(argv[1], argv[1], NULL);

    }else{
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        execlp(argv[2], argv[2], NULL);
    }
    
}
