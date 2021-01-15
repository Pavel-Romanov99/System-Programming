#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
    2.	Да се пусне един fork() и само в детския процес още един fork().
        За всеки генериран процес се отпечатва pid-а на процеса/getpid()/ и
        pid-a на родителския ппроцес/getppid()/.
 */

int main(int argc, char* argv[])
{   
    int pid = fork();
    if(pid==0){
        fork();
    }
    wait();

    printf("Process id and paren id : %d    %d\n", getpid(), getppid());
}
