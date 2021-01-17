#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
    1.	Да се напише програма на Си, която прави канал между 2 команди в явен вид. Примерно ls | grep e
 */

int main(int argc, char* argv[])
{   
    int fd[2];
    pipe(fd);
    int pid = fork();

    if(pid == -1){
        printf("error forking\n");
        exit(1);
    }
    else if(pid == 0){
        close(1);
        dup(fd[1]);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", NULL);
    }
    else{
        //grep очаква своя вход от стдин и затова входа на пайпа се пренасочва към стдин
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "e", NULL);
    }
}
