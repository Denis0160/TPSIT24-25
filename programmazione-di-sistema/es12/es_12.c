/**
 * Si vuole realizzare un software concorrente in linguaggio C che legga un file di testo da argv[1] e conteggi il numero di parole presenti nel file.
Una volta effettuato il conteggio il programma principale deve mostrarlo a video.

Note operative:
P0 genera P1 il quale legge il contenuto del file usando il comando cat.
P2 legge da pipe il flusso di caratteri e capisce quando finisce una parola e ne inizia un'altra, in modo da poter aggiornare il contatore.
P2 invia a P0 il totale
P0 stampa a video il totale.

Esempio:
$ ./a.out file.txt
Nel file sono presenti 10 parole
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int parola(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
    {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti errato");
        exit(1);
    }

    int pid, p1p2[2], p2p0[2];
    char nparole[100];

    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {

        close(p1p2[0]);

        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    close(p1p2[1]);

    pipe(p2p0);

    pid = fork();

    if (pid == 0)
    {
        close(p2p0[0]);

        int n = 0;
        char c;

        while (read(p1p2[0], &c, 1) > 0)
        {
            if (parola(c) == 0)
            {
                n++;
            }
        }

        close(p1p2[0]);

        sprintf(nparole, "%d", n);

        write(p2p0[1], nparole, strlen(nparole) + 1);

        close(p2p0[1]);
        exit(0);
    }

    read(p2p0[0], &nparole, sizeof(nparole));

    close(p1p2[0]);

    close(p2p0[1]);

    close(p1p2[0]);
    wait(&pid);
    wait(&pid);

    printf("Nel file sono presenti %s parole\n", nparole);
}