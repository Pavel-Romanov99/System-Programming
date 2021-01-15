#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
	8.	Да се напише програма на С, която получава като параметри имена на два файла.
        В зад 6 пренасочва изхода на процеса дете във втория файл (ако не съществува, го
        създава, в противен случай добавя в него)
 */

int main(int argc, char* argv[])
{
    int fd1, fd2;

    fd1 = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);

    fd2= dup(fd1);

    int pid = fork();

    if(pid == -1){
        printf("error\n");
        exit(1);
    }
    else if(pid == 0){
        
        write(fd2, "Hello", 5);
    }
    else{
        wait(NULL);
        write(fd1, " my dear friend", 15);
    }

    write(fd1, " how are u doing", 17);
    
    close(fd1);
    close(fd2);
}