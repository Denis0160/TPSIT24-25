/*
Scrivere un programma concorrente che realizzi il seguente comando:

cat file.txt | wc

il processo p2 deve rimandare l'output di wc al padre, il quale lo scriverà
su un file chiamato wc.txt

il nome del file "file.txt" deve essere passato come argomento in argv[1]
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pipe(p2p0);
    pid = fork();

    if (pid == 0)
    {
        close(p1p2[1]); 
        close(0);       
        dup(p1p2[0]);   
        close(p1p2[0]); 

        close(p2p0[0]); 
        close(1);      
        dup(p2p0[1]);  
        close(p2p0[1]); 

        execl("/bin/wc", "wc", (char *)0);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);
    close(p2p0[1]);
    int fd = open("wc.txt", O_CREAT | O_WRONLY, 0777);
    char buff;
    int r;

    while ((r = read(p2p0[0], &buff, sizeof(buff))) > 0)
    {
        write(fd, &buff, r);
    }
    close(p2p0[0]);
    close(fd);

    return 0;
}