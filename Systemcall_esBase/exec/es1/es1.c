/**
 * Scrivere un programma in linguaggio C che usa il comando 
della shell cat per mostrare a video un file di testo
presente in argv[1]

esempio:
$ ./a.out costituzione.txt
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
     printf("Errore: numero di argomenti errato\n");
     exit(1);    
    }

    execl("/usr/bin/cat", "cat", argv[1], NULL);

    

    return 0;
}