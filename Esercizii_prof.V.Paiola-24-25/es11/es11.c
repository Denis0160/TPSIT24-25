/**
 * Leggi il file numeri.txt composto da una sequenza di numeri separati da uno spazio.
Scrivi due file, pari.txt e dispari .txt, nei quali inserisci i numeri letti a seconda del loro valore pari o dispari.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81
#define MAX_NUM 1000

int main(int argc, char *argv[]) {
    FILE *fp, *fp_pari, *fp_dispari;
    int numeri[MAX_NUM];
    int i = 0;
    char buffer[MAX];

    if (argc != 2) {
        printf("Uso: %s <file numeri>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Errore apertura file");
        return 1;
    }

    while (fgets(buffer, MAX, fp) != NULL) {
        char *token = strtok(buffer, " ");
        while (token != NULL && i < MAX_NUM) {
            numeri[i++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    fp_pari = fopen("pari.txt", "w");
    if (fp_pari == NULL) {
        perror("Errore apertura file pari.txt");
        return 1;
    }

    fp_dispari = fopen("dispari.txt", "w");
    if (fp_dispari == NULL) {
        perror("Errore apertura file dispari.txt");
        fclose(fp_pari);
        return 1;
    }
    for (int j = 0; j < i; j++) {
        if (numeri[j] % 2 == 0) {
            fprintf(fp_pari, "%d ", numeri[j]);
        } else {
            fprintf(fp_dispari, "%d ", numeri[j]);
        }
    }
    fclose(fp_pari);
    fclose(fp_dispari); 
    printf("Scrittura completata.\n");
    return 0;
}