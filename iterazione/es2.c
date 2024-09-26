// Author:Sescu Denis
// Data:26/09/2024

/*Dato N un numero intero positivo, generare e visualizzare in ordine crescente
i primi N numeri interi positivi.*/

#include <stdio.h>

int main() {
  int n, j = 0;

  do {
    printf("Inserisci il numero\n");
    scanf("%d", &n);

  } while (n <= 0);

  do {
    j++;
    printf("%d\n", j);
  } while (j < n);

  return 0;
}