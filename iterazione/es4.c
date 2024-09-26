// Author: Sescu Denis
// Data: 26/09/2024

/*
Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri pari minori o uguali a N.
*/

#include <stdio.h>

int main() {
  int n, pari = 0;

  do {
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &n);
  } while (n <= 0);

  while (pari <= n) {
    printf("%d\n", pari);
    pari += 2;
  }

  return 0;
}
