/**
 * Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due figli: F1 e  F2.

   A F1 assegna un tempo t di sleep(t) (ritardo) 2 secondi;
   F1 deve restituire al padre P il numero 2.
   A F2 assegna un tempo t di sleep(t) (ritardo) 4 secondi;
   F2 deve restituire al padre P il numero 4.

   Padre P deve attendere la terminazione del figlio che dorme di più, ossia F2, e
   deve scrivere quanti secondi ha dormito tale figlio.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   è dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena è stato generato,
   è dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare"
   "..."
 */
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
        sleep(2);
        exit(2);
    }
    p2 = fork();
    if (p2 == 0)
    {
        printf("F2: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
        sleep(4);
        exit(4);
    }
    wait(&status1);
    wait(&status2);
    
    int tempo1 = WEXITSTATUS(status1);
    int tempo2 = WEXITSTATUS(status2);

    if (tempo1 > tempo2)
    {
        printf("P: F2 ha dormito per %d secondi\n", tempo1);
    }
    else
    {
        printf("P: F2 ha dormito per %d secondi\n", tempo2);
    }
    return 0;
}