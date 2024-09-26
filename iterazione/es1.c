// Author:Sescu Denis
// Data:26/09/2024

/*
Dato N un numero intero positivo, generare e visualizzare il numero
successivo.
*/
#include <stdio.h>
int main() {
  int n, successivo;

  do {
    printf("Inserisci il numero:\n");
    scanf("%d", &n);

  } while (n >= 0);

  successivo = n + 1;
  printf("Il suo successivo e': %d", successivo);

  return 0;
}