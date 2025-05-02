/**
 * Scrivi un programma in C che legge un file di testo contenente
 * una sequenza di numeri interi separati da spazi e li divide in
 * due file distinti: uno per i numeri pari e l'altro per i numeri dispari.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file, *filePari, *fileDispari;

    if (argc != 4)
    {
        printf("Numero invalido di argomenwti\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file di input.\n");
        return 1;
    }

    filePari = fopen(argv[2], "w");
    if (filePari == NULL)
    {
        printf("Errore nell'apertura del file di output per i numeri pari.\n");
        fclose(file);
        return 1;
    }
    fileDispari = fopen(argv[3], "w");
    if (fileDispari == NULL)
    {
        printf("Errore nell'apertura del file di output per i numeri dispari.\n");
        fclose(file);
        fclose(filePari);
        return 1;
    }
    int numero;
    while (fscanf(file,"%d",&numero)!= EOF)
    {
        if (numero % 2 == 0)
        {
            fprintf(filePari, "%d\n", numero);
        }
        else
        {
            fprintf(fileDispari, "%d\n", numero);
        }
    }

    fclose(file);
    fclose(filePari);
    fclose(fileDispari);
    return 0;

}