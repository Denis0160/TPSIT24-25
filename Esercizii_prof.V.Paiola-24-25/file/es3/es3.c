/**
 * Scrivere un programma in linguaggio C che:

Apre un file di testo chiamato input.txt in modalità lettura ("r").

Legge il contenuto del file riga per riga utilizzando la funzione fgets().

Conta:

Il numero totale di righe presenti nel file.

Il numero totale di caratteri presenti nel file (inclusi spazi e caratteri di newline \n).

Stampa a schermo i due conteggi:

Quante righe contiene il file.

Quanti caratteri in totale ci sono.

Chiude correttamente il file dopo la lettura.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file =fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }
    char buffer[50];
    int nRighe = 0, nParole = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        nParole += strlen(buffer);
        nRighe++;
    }

    printf("Il file contiene %d righe e %d caratteri.\n", nRighe, nParole);
    fclose(file);
    return 0;
}