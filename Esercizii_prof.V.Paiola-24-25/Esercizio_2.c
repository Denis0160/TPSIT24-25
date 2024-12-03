#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid1, pid2, pid3, pid4, pid5, pid6;

    // Creazione del primo processo figlio (P2)
    pid1 = fork();
    if (pid1 == 0)
    {
        // Siamo nel processo P2
        printf("Sono il processo P2 di pid %d, mio padre ha pid %d\n", getpid(), getppid());
        return 0;
    }
    else if (pid1 > 0)
    {
        // Siamo nel padre, che ora crea il secondo processo figlio (P3)
        pid2 = fork();
        if (pid2 == 0)
        {
            // Siamo nel processo P3
            printf("Sono il processo P3 di pid %d, mio padre ha pid %d\n", getpid(), getppid());

            // Creazione del figlio P5
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("Sono il processo P5 di pid %d, mio padre ha pid %d\n", getpid(), getppid());
                return 0;
            }

            // Creazione del figlio P6
            pid4 = fork();
            if (pid4 == 0)
            {
                printf("Sono il processo P6 di pid %d mio padre ha pid %d\n", getpid(), getppid());
                return 0;
            }
            return 0; // Il processo P3 termina
        }
    }

    // Creazione del figlio P4 da parte del processo P2
    if (getpid() == pid1)
    {
        pid5 = fork();
        if (pid5 == 0)
        {
            // Siamo nel processo P4
            printf("Sono il processo P4 di pid %d, mio padre ha pid %d \n", getpid(), getppid());
            return 0;
        }
    }

    return 0;
}
