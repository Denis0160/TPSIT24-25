#include <stdio.h>
#include <stdlib.h>

/**
 * scrivere un programma che scriva su un file dei nomi e che vengano salvati
 * in un file chiamato "nomi.txt"
 */
int main(int argc, char *argv[])
{
    // file è un tipo di dato definito in stdio.h
    FILE *nomi; // definisco una variabile di tipo puntatore a file
    nomi = fopen("nomi.txt", "w"); // apro il file in scrittura
    if (nomi == NULL) // se il file non è stato aperto correttamente
    {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    // scrivo sul file
    fprintf(nomi, "Mario\n");

    // chiudo il file
    fclose(nomi);


    return 0;
}