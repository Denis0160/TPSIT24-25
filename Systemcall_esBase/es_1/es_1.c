/**
 * Utilizzando le system call open, read, write, close leggere il file rfc1918.txt e stamparlo a video.
 * Il programa deve essere cosi invocato:
 * $./a.out rfc1918.txt
 * Consiglio: leggere un carratere per volta
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero di argomenti invalido\n");
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    printf("fd = %d\n", fd);

    char buff;

    int r = read(fd, &buff, sizeof(buff));

    while (r > 0)
    {
        write(1, &buff, r);
        r = read(fd, &buff, sizeof(buff)); 
    }
   
    return 0;
}
