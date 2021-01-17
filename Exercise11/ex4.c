#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
  4.	Да се напише програма на Си, която прави канал между 3 команди.
        Например:  who | grep s81xxx | wc -l

 */

int main(int argc, char* argv[])
{   
    int fd1[2], fd2[2];
    int pid1, pid2;
    pid1 = fork();

    pipe(fd2);
    pipe(fd1);

    if(pid1 == 0){
        pid2 = fork();

        if(pid2 == 0){
            //child2

            close(fd2[0]);
            close(fd2[1]);


            close(1);
            dup(fd1[1]);
            close(fd1[1]);
            close(fd1[0]);
            execlp("ls", "ls", "-l", NULL);
        }
        else{
            //child1
            wait();
            close(0);
            dup(fd1[0]);
            close(fd1[0]);
            close(fd1[1]);


            close(1);
            dup(fd2[1]);
            close(fd2[1]);
            close(fd2[0]);
            execlp("grep", "grep", "e", NULL);

        }
    }else{
        //parent

        wait(NULL);
        close(fd1[0]);
        close(fd1[1]);
        close(0);
        dup(fd2[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("wc", "wc", NULL);
    }   
}           
