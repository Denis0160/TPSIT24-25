#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int f;
    char alfabeto[] = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";

    if (argc != 2)
    {
        printf("Errore, numero di qrgomenti sbagliati!");
        exit(1);
    }

    f = open(argv[1], O_WRONLY | O_CREAT, 0777);

    int w = write(f, alfabeto, sizeof(alfabeto));

    close(f);

    return 0;
}