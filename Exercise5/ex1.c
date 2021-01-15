#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
1.	Напишете програма на Си, която изпълнява команда извеждаща редовете,
в които се среща символния низ int в подадения като параметър файл.
 */

int main(int argc, char* argv[])
{
    int pid = fork();

    if(pid == -1){
        printf("error\n");
        exit(1);
    }
    else if(pid == 0){
        execlp("grep", "grep", "int", "a", NULL);

    }
    else{
        wait(NULL);
        printf("Process is complete\n");
    }
}