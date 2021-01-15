#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
    4.	Да се напише програма на С, която получава като параметри две имена на файлове. 
    Отваря първия файл за писане (ако не съществува, го създава, в противен случай го занулява),
     създава 2 процеса. Родителят пише hello1, а детето – hello2 във първия файл. 
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
        write(fd1, "Hello1", 6);
    }
    else{
        wait();
        write(fd1, "Hello2", 6);
    }
    close(fd1);

}
