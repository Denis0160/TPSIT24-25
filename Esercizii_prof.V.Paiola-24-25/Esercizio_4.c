
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int p;
int status;
int main(int argc, char *argv[])
{
    p = fork();

    if (p == 0) // figlio
    {
        printf("1_Sono il figlio il mio pid e' %d \n", getpid());
        printf("2_sono il figlio e mio padre ha pid: %d\n", getppid());

        exit(34);
    }
    else // padre
    {
        printf("4_Sono il padre e il mio pid e' %d\n", getpid());
        printf("5_Sono il padre e mio figlio ha pid= %d\n", p);

        printf("Attendo che il mio figlio %d termini\n", wait(&status));

        printf("Sono il padre con pid %d e vedo ancora il pid del figlio anche se è gia terminato pid= %d\n", getpid(), p);
        printf("La exit di mio figlio e' %d",WEXITSTATUS(status));
    }
}
