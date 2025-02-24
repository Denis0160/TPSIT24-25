#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p1, p2;
    int status1, status2;

    p1 = fork();
    if (p1 == 0)
    {
        printf("F1: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
        int somma1 = 1 + 2;
        exit(somma1);
    }

    p2 = fork();
    if (p2 == 0)
    {
        // Codice eseguito dal processo figlio F2
        printf("F2: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
        int somma2 = 3 + 4;
        exit(somma2);
    }

    wait(&status1);
    wait(&status2);

    int somma1 = WEXITSTATUS(status1);
    int somma2 = WEXITSTATUS(status2);

    printf("P: %d + %d = %d\n", somma1, somma2, somma1 + somma2);

    return 0;
}
