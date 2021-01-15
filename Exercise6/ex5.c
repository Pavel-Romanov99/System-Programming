#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
   6.	В зад 5 в края на действията на детето възстановявате стандартния му изход.
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
        int std_out = dup(1);
        close(1);
        dup(fd1);

        write(1, "Hello1", 6);
        write(1, "Hello2", 6);

        close(fd1);
        dup(std_out);

        write(1, "test", 4);
        printf("\n");
    }
    else{
        wait();
        write(fd1, "Hello3", 6);
        write(fd1, "Hello4", 6);
    }
    close(fd1);

}


// close(1);
// dup(fd);
// write(1, "hello", 5);

//dup2(fd, 1);


