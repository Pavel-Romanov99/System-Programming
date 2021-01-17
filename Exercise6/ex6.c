#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*	
   9.	Да се напише програма на C, която получава като командни параметри две команди (без параметри).
        Изпълнява ги едновременно и извежда на стандартния изход номера на процеса на първата завършила успешно.
        Ако нито една не завърши успешно извежда -1.
*/

int main(int argc, char* argv[])
{   
  int pid = fork();
  int status;

  if(pid == 0){
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            printf("test1\n");
            
      //child1 
      execlp(argv[1], argv[1], NULL);
  }
  else{
      int pid2 = fork();

      if(pid2 == 0){
        //child2
        execlp(argv[2], argv[2], NULL);
      }
      else{
        //parent
        int res = wait(&status);
        if(status == 0){
            printf("%d", res);
        }
        else {
            printf("-1\n");
        }
      }
  }
}



