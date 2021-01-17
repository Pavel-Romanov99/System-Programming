#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>

/*  Да се напише програма на C, която получава 2 параметъра – имена на файлове. Стартира команда 
    тръсеща срещането на низ pts, като пренасочва стандартния й вход от първия файл, а стандартния й изход 
    и изхода й за грешки - във втория. Накрая извежда кода й на завършване на екрана.

*/

main ( int argc, char *argv[] )
{
    int status;
    int pid = fork();
    if (pid == 0)
    {
        /* code */
        close(0);
        int fd1 = open(argv[1], O_RDONLY);
        close(1);
        int fd2 = open(argv[1], O_WRONLY);
        dup2(2, fd2);
        execlp("grep", "grep", "pts", 0);
    }else{
        wait(&status);
        printf("%d", status);
    }

}


