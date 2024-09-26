// Author:Sescu Denis
// Data:26/09/2024

/*
Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N.
*/
#include <stdio.h>
int main() {
  int n, n1;

  do {
    printf("Inserisci il numero 1:\n");
    scanf("%d", &n);

  } while (n <= 0);

  n1 = -n;

  while (n1 <= n) {
    printf("%d\n", n1);
    n1++;
  }
  return 0;
}