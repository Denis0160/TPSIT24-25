/**
 * Scrivi il codice sorgente diun programma che consente all'utente di inserire 5 numeri interi e
di salvarli in un file binario.
Successivamente, tali numeri dovranno essere letti dal file e visualizzati a schermo.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;

    file = fopen ("numeri.bin", "wb");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    int numeri[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &numeri[i]);
    }

    fwrite(numeri, sizeof(int),5, file);
    fclose(file);

    file = fopen("numeri.bin", "rb");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    int buff;

    for(int i = 0; i<5;i++){
        fread(&buff, sizeof(int), 1, file);
        printf("%d ", buff);

    }
    fclose(file);
    return 0;
}