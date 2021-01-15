#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
   5.	В зад 4 пренасочвате изхода на детето във втория файл. В общи действия на двата процеса
         се записват hello3 на стандартния изход и hello4 във втория файл:
            •	с wait в родителя
            •	без wait в родителя
*/

int main(int argc, char* argv[])
{   
    int fd1;

    fd1 = open(argv[1], O_CREAT | O_WRONLY, 0666);

    int pid = fork();

    if(pid == -1){
        printf("error\n");
        exit(1);
    }
    else if(pid == 0){
        close(1);
        dup(fd1);
        write(1, "Hello1", 6);
        write(1, "Hello2", 6);
    }
    else{
        wait();
        write(fd1, "Hello3", 6);
        write(fd1, "Hello4", 6);
    }
    close(fd1);

}
