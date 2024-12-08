#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
/**
 * Data una stringa letta da riga di comando si scriva un programma in linguaggio C
 * che istanzi un processo figlio il quale converta la stringa da minuscolo a maiuscolo
 * esempio di esecuzione:
 * $./a.out ciao
 * la stringa in maiuscolo è CIAO
 *
 */
int main(int argc, char *argv[])
{
    // Se non viene passato esattamente un argomento, il programma termina.
    if (argc != 2)
    {
        return 1;
    }
    
    int pid;

    pid = fork(); // processo figlio.

    if (pid == 0)
    {
        for (int i = 0; argv[1][i]; i++)
        {
            argv[1][i] = toupper(argv[1][i]);
        }
        printf("La stringa in maiuscolo è %s\n", argv[1]); // Stampa la stringa in maiuscolo.
    }

    return 0;
}
