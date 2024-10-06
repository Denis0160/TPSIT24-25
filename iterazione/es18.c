//Data una misura di tempo espressa in secondi S1, convertirla in ore H,
//minuti M e secondi S.

//Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
//dal programma, 0h 27m 10s

#include<stdio.h>
int main(int argc, char *argv[]) {
	
    int S1, H, M, S;

    printf("Inserisci il tempo in secondi: ");
    scanf("%d", &S1);

    H = S1 / 3600;        
    M = (S1 % 3600) / 60; // I minuti sono il resto diviso per 60
    S = S1 % 60;          // I secondi sono il resto della divisione per 60

    printf("%dh %dm %ds\n", H, M, S);

    return 0;
}
