#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
    5.Да се напише програма на С, която получава като параметри три команди (без параметри),
    изпълнява ги последователно, като изчаква края на всяка и извежда на стандартния изход номера на завършилия
    процес, както и неговия код на завършване
 */

int main(int argc, char* argv[])
{
    int status;
    for (int i = 1; i < argc; i++)
    {
        int pid = fork();

        if(pid == 0){
            execlp(argv[i], &argv[i], NULL);
        }        
        else{
            int res = wait(&status);
            printf("pid = %d, exitcode = %d\n",  res, status);
        }
    }
}