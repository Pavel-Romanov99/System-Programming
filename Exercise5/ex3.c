#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
4.	Да се напише програма на С, която получаваю 
    като параметър команда с опции и аргуманти. При успешното ѝ изпълнение, 
    извежда на стандартния изход кода на завършане.
 */

int main(int argc, char* argv[])
{
    int pid = fork();


    if(pid == 0){
        execvp(argv[1], &(argv[1]));
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