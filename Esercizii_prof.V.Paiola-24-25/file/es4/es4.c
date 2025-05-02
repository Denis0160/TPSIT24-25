/**
 * Scrivere un programma in linguaggio C che:

Utilizza gli argomenti da riga di comando per gestire i nomi dei file:

Il primo argomento (argv[1]) rappresenta il nome del file di input (sorgente).

Il secondo argomento (argv[2]) rappresenta il nome del file di output (destinazione).

Controlla che siano stati forniti esattamente due argomenti (oltre al nome del programma stesso).

Apre il file di input in modalità lettura ("r") e il file di output in modalità scrittura ("w"):

Se uno dei due file non può essere aperto, stampa un messaggio di errore e termina il programma.

Copia il contenuto del file di input nel file di output, carattere per carattere, utilizzando le funzioni fgetc() e fputc().

Chiude entrambi i file al termine della copia.


 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fileIN, *fileOUT;

    if (argc != 3)
    {
        printf("Numeri di argomenti errato\n");
        return 1;
    }

    fileIN = fopen(argv[1], "r");
    if (fileIN == NULL)
    {
        printf("Errore nell'apertura del file di input.\n");
        return 1;
    }
    fileOUT = fopen(argv[2], "w");
    if (fileOUT == NULL)
    {
        printf("Errore nell'apertura del file di output.\n");
        fclose(fileIN);
        return 1;
    }
    int c;
    while ((c = fgetc(fileIN)) != EOF)
    {
        fputc(c, fileOUT);
    }
    fclose(fileIN);
    fclose(fileOUT);
    return 0;
}