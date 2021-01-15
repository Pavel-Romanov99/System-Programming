#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
    1.Да се пуснат един след друг два системни примитива fork(), като за всеки
    генериран процес се отпечатва pid-а на процеса/getpid()/ и pid-a на родителския
    ппроцес/getppid()/.
 */

int main(int argc, char* argv[])
{   
    int pid = fork();
    fork();
    wait();

    printf("Process id and paren id : %d    %d\n", getpid(), getppid());
}
