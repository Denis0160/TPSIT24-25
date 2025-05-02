/**
 * Scrivi un programma in linguaggio C che:

Apre (o crea) un file chiamato output.txt in modalità append ("a"), in modo che il contenuto precedente non venga sovrascritto.

Chiede all'utente di inserire 3 nomi, uno alla volta.

Per ogni nome inserito:

Lo salva nel file (una riga per ogni nome).

Chiude correttamente il file.
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char nome[30];

    file = fopen("output.txt", "a");

    if (file == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Inserisci un nome: \n");
        scanf("%s", nome);

        fputs(nome, file);
        fputc('\n', file);
    }

    fclose(file);
    return 0;
}