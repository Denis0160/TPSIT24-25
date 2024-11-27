
#include <stdio.h>
#include <unistd.h>

/**
 *Scrivi il codice sorgente di un programma che permette al processo padre di generare un processo figlio:
 *sia padre che figlio visualizzano il proprio PID e il PID del proprio parente
 *padre conta da 0 a 19 (visualizza i numeri da 0 a 19)
 *figlio conta da 0 a 9 (visualizza i numeri da 0 a 9)
 *Manda in esecuzione più volte e descrivi il comportamento del programma.
 */

int main(int argc, char *argv[])
{
    int p1 = fork();

    if (p1 > 0)
    {
        printf("Sono il processo padre con PID: %d\n", getpid());
        printf("il pid del figlio è %d\n", p1);
        for (int i = 0; i < 20; i++)
        {
            printf("%d ", i);
        }
    }
    else if (p1 == 0)
    {
        printf("Questo codice è eseguito dal processo figlio con pid %d.\n", getpid());
        printf("Il processo padre ha pid %d\n", getppid());
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
