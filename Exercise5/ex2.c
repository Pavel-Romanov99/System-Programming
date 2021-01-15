#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
3.	Да се напише програма на С, която получава като
    параметър команда (без параметри) и при успешното ѝ изпълнение, 
    извежда на стандартния изход името на командата.
 */

int main(int argc, char* argv[])
{
    int pid = fork();

    if(pid == 0){
        execlp(argv[1], argv[1], NULL);
    }
    else{
        int status;
        wait(&status);

        if(status == 0){
            printf("Success\n");
        }
        else printf("error\n");
    }
}