/**
 * Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza. 
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_STRING 100

int main(int argc, char*argv[]){
    if(argc != 2){
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    pipe(p1p2);

    pid = fork();

    if(pid == 0){
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/bin/cat", "cat", argv[1], (char *)0);
        return -1;
    }

    pipe(p2p0);
    pid = fork();

    if(pid == 0){
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/bin/wc", "wc", (char *)0);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    char string[MAX_STRING];
    int count = 0;
    while(1){
        printf("Inserisci una stringa: ");
        scanf("%s", string);
        if(strcmp(string, "fine") == 0){
            break;
        }
        write(p2p0[1], string, strlen(string));
        count++;
    }

    close(p2p0[1]);

    close(p2p0[0]);
    close(0);
    dup(p2p0[0]);
    close(p2p0[0]);

    execl("/bin/wc", "wc", (char *)0);
    return -1;

}