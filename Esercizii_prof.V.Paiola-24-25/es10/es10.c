/**
 * Copia, carattere per carattere, il contenuto di un file già esistente in un secondo file, da creare.
I nomi dei file devono essere inseriti in input dall'utente. utilizzando fgetc().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

int main(int argc, char* argv[]){
    FILE *fp1, *fp2;
    char c;

    if (argc != 3) {
        printf("Uso: %s <file sorgente> <file destinazione>\n", argv[0]);
        return 1;
    }

    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        perror("Errore apertura file sorgente");
        return 1;
    }

    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        perror("Errore apertura file destinazione");
        fclose(fp1);
        return 1;
    }

    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Copia completata.\n");

    return 0;
}