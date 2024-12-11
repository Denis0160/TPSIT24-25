#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * Data una stringa letta da riga di comando si scriva un programma in linguaggio C
 * che istanzi un processo figlio il quale converta la stringa da minuscolo a maiuscolo
 * esempio di esecuzione:
 * $./a.out ciao
 * la stringa in maiuscolo è CIAO
 */

int main(int argv, char *argc[])
{
    int pid;

    pid = fork();
    char stringa[40];

    printf("inserisci la stringa\n");
    scanf("%s", stringa);

    int l = strelen(stringa);

    char stringa2[l];

    if (pid == 0)
    {
        int k=0;
        for (int i = 0; i < strlen(stringa); i++)
        {
            stringa[i] = toupper(i);
            stringa2[k]=stringa[i];
            k++;
        }

        printf("%s",stringa2);
        exit(0);
    }
    else
    {
        wait(&pid);
    }

    return 0;
}