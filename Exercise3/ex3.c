#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
2.	В текущата директория се намира файл f1 със съдържание:
abcd-abcd-abcd
Отворете файла с 2 различни дескриптора за четене и писане. Започвайки от  последните 2 символа напишете думата wxyz.
 Запишете върху 5 и 6-тия символ от началото на файла - цифрите 12. Отпечатайте цялото съдържание на файла.
 */

int main(int argc, char* argv[])
{
    int fd1, fd2;

    fd1 = open("fff", O_WRONLY);
    fd2 = open("fff", O_WRONLY);

    if(fd1 < 0 || fd2 < 0){
        printf("problem opening files\n");
        exit(1);
    }

    lseek(fd1, -2, SEEK_END);
    write(fd1, "wxyz", 4);

    lseek(fd2, 5, SEEK_SET);
    write(fd2, "12", 2);

    close(fd1);
    close(fd2);
}