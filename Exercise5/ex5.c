#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
	6.Да се напише програма на С, която получава като параметър име на файл. Отваря подадения файл за писане (ако не съществува, 
    го създава, в противен случай го занулява), създава 2 процеса и двата процеса пишат символния низ Hello във файла.
 */

int main(int argc, char* argv[])
{
    int fd1, fd2;

    fd1 = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
    fd2 = open(argv[1], O_WRONLY);

    int pid = fork();

    if(pid == -1){
        printf("error\n");
        exit(1);
    }
    else if(pid == 0){
        write(fd1, "Hello", 5);
    }
    else{
        wait(NULL);
        write(fd2, "Hello", 5);
    }

    close(fd1);
    close(fd2);
}