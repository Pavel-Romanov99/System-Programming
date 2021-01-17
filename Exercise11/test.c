#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>
main ( int argc, char *argv[] )
{
	int pid = fork();

    if(pid == 0){
        for (int i = 0; i < 3; i++)
        {
            /* code */
            printf("dete\n");
            execlp("ls", "ls", 0);
        }
    }
    else{
        wait();
        printf("roditel\n");
    }

    printf("test\n");
}



