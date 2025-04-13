/**
 * fai una calcolatrice in c con le seguenti operazioni utilizzando le funzioni:
 * 1) somma
 * 2) sottrazione
 * 3) moltiplicazione
 * 4) divisione
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int somma(int a, int b)
{
    return a + b;
}
int sottrazione(int a, int b)
{
    return a - b;
}
int moltiplicazione(int a, int b)
{
    return a * b;
}
int divisione(int a, int b)
{
    if (b == 0)
    {
        printf("Errore: divisione per zero\n");
        return 0;
    }
    return a / b;
}

int main(int argc, char *argv[])
{

    int a, b;
    char operazione;

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);
    printf("Inserisci l'operazione (+, -, *, /): ");
    scanf(" %c", &operazione);

    switch (operazione)
    {
    case '+':
        printf("Risultato: %d\n", somma(a, b));
        break;
    case '-':
        printf("Risultato: %d\n", sottrazione(a, b));
        break;
    case '*':
        printf("Risultato: %d\n", moltiplicazione(a, b));
        break;
    case '/':
        printf("Risultato: %d\n", divisione(a, b));
        break;
    default:
        printf("Operazione non valida\n");
        break;
    }

    return 0;
}
    
