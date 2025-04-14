/**
 * Apria un file già esistente e conta il numero di righe e di caratteri di cui si compone.
Utilizza la funzione fgets().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[MAX];
    int righe = 0, caratteri = 0;

    if (argc != 2) {
        printf("Uso: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Errore apertura file");
        return 1;
    }

    while (fgets(buffer, MAX, fp) != NULL) {
        righe++;
        caratteri += strlen(buffer);
    }

    fclose(fp);

    printf("Numero di righe: %d\n", righe);
    printf("Numero di caratteri: %d\n", caratteri);

    return 0;
}