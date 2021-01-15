#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
	7.	Да се напише програма на С, която получава като параметър име на файл.
        Създава процес син, който записва стринга Hello във файла (ако не съществува,
        го създава, в противен случай го занулява), след което процеса родител прочита
        записаното във файла съдържание и го извежда на стандартния изход, добавяйки по
        един интервал между всеки два символа.
 */

int main(int argc, char* argv[])
{
    char * filename = argv[1];
    char buffer[20];
    int fd1 = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    int fd2 = open(filename, O_RDONLY);

    int pid = fork();

    if(pid == -1){
        printf("error\n");
        exit(1);
    }
    else if(pid == 0){
        write(fd1, "Hello", 6);
    }
    else {
        wait();
        read(fd2, buffer, 6);

        for (int i = 0; i < 6; i++)
        {
            /* code */
            printf("%c ", buffer[i]);
        }        
    }
    close(fd1);
}