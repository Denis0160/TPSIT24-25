#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid1, pid2, pid3;

    // Creazione del primo figlio
    pid1 = fork();
    if (pid1 == 0) {
        // Processo figlio 1
        printf("Sono un processo figlio, il mio PID=%d, mio padre ha PID=%d, Ciao sono Qui\n", getpid(), getppid());
        return 0;
    }

    // Creazione del secondo figlio
    pid2 = fork();
    if (pid2 == 0) {
        // Processo figlio 2
        printf("Sono un processo figlio, il mio PID=%d, mio padre ha PID=%d, Ciao sono Quo\n", getpid(), getppid());
        return 0;
    }

    // Creazione del terzo figlio
    pid3 = fork();
    if (pid3 == 0) {
        // Processo figlio 3
        printf("Sono un processo figlio, il mio PID=%d, mio padre ha PID=%d, Ciao sono Qua\n", getpid(), getppid());
        return 0;
    }

    // Processo padre
    printf("Sono il processo padre, il mio PID=%d, mio figlio 1 ha PID=%d, mio figlio 2 ha PID=%d, mio figlio 3 ha PID=%d\n",
           getpid(), pid1, pid2, pid3);

    

    return 0;
}
