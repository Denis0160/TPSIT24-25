#include <stdio.h>
int main() {
  int A, B;
  int numero, i = 0, somma;
  double media;

  do {
    printf("Inserisci il valore A\n");
    scanf("%d", &A);
    printf("inserisci il valore B\n");
    scanf("%d", &B);

  } while (B < A);
  do {
    printf("inserisci un numero\n");
    scanf("%d", &numero);

    if (numero >= A && numero <= B) {
      somma += numero;
      i++;
    }
  } while (numero >= A && numero <= B);
  media = somma / i;
  printf("media:%.2f", media);
}