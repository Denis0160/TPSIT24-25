#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

    int main(int argc, char *argv[])
{
    int n;
    bool verifica = false;

    // Richiesta del numero all'utente
    do
    {
        printf("Inserisci un numero compreso tra 0 e 10\n");
        scanf("%d", &n);
        if (n >= 0 && n <= 10)
        {
            verifica = true;
        }
        else
        {
            printf("Numero non valido! Riprova.\n");
        }
    } while (!verifica);

    int p2, p3;

    // Processo P1 (Padre)
    p2 = fork();
    if (p2 == 0)
    { // Siamo nel processo P2
        printf("P2: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());

        int p4, p5;
        p4 = fork(); // Creazione del processo P4
        if (p4 == 0)
        { // Siamo nel processo P4
            printf("P4: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());
            for (int i = n; i >= 0; i--)
            {
                printf("P4: %d\n", i);
                //sleep(1);
            }
            exit(0);
        }

        p5 = fork(); // Creazione del processo P5
        if (p5 == 0)
        { // Siamo nel processo P5
            printf("P5: mio PID=%d, mio padre P2 ha PID=%d\n", getpid(), getppid());
            for (int i = 0; i <= n; i++)
            {
                printf("P5: %d\n", i);
                //sleep(1);
            }
            exit(0);
        }

        // P2 aspetta la terminazione dei suoi figli P4 e P5
        wait(NULL);
        wait(NULL);

        // P2 termina
        exit(0);
    }
    else if (p2 > 0)
    { // Siamo nel processo P1
        printf("P1: mio PID=%d, mio figlio P2 ha PID=%d\n", getpid(), p2);

        p3 = fork(); // Creazione del processo P3
        if (p3 == 0)
        { // Siamo nel processo P3
            printf("P3: mio PID=%d, mio padre P1 ha PID=%d\n", getpid(), getppid());
            printf("P3: Il numero n è %d\n", n);

            int p6 = fork(); // Creazione del processo P6
            if (p6 == 0)
            { // Siamo nel processo P6
                printf("P6: mio PID=%d, mio padre P3 ha PID=%d\n", getpid(), getppid());
                int quadrato = n * n;
                exit(quadrato); // Restituisce il quadrato di n a P3
            }
            else if (p6 > 0)
            {
                int q;
                wait(&q);
            
                printf("P3: il quadrato di n è %d\n", WEXITSTATUS(q));
            }

            exit(0);
        }

        // P1 aspetta la terminazione dei suoi figli P2 e P3
        wait(NULL);
        wait(NULL);

        // P1 termina
        exit(0);
    }

    return 0;
}
