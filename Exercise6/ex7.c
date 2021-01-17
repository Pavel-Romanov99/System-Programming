#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*	
   10.	Да се напише програма на C, която получава като параметри от команден ред две команди
        (без параметри) и име на файл в текущата директория. Ако файлът не съществува, го създава.
        Програмата изпълнява командите последователно, по реда на подаването им. Ако първата команда завърши успешно,
        програмата добавя нейното име към съдържанието на файла, подаден като команден параметър. Ако командата завърши неуспешно,
        програмата уведомява потребителя чрез подходящо съобщение.
*/

int main(int argc, char* argv[])
{   
  int status;
  int status1;
  int success = 0;

  int fd = open(argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0777);

  int pid = fork();

  if(pid == 0){
      //child1 
      execlp(argv[1], argv[1], NULL);
  }
  else{
      wait(&status1);

      if(status1 == 0){
            write(fd, argv[1], strlen(argv[1]));
      }
      else{
        printf("first command failed\n");
      }
      int pid2 = fork();

      if(pid2 == 0){
        //child2
        execlp(argv[2], argv[2], NULL);
      }
    }
}



