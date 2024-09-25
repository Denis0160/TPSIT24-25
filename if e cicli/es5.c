#include <stdio.h>

int main() {
  int A, B, C;
  int sommaAB;
  int differenza;
  int nPari = 0, nDispari = 0, nNulla = 0;

  do {
    printf("Inserisci il valore A\n");
    scanf("%d", &A);
    printf("Inserisci il valore B\n");
    scanf("%d", &B);
    printf("Inserisci il valore C\n");
    scanf("%d", &C);

    sommaAB = A + B;
    differenza = A - B;

    if (differenza % 2 == 0) {
      nPari++;
    } else if (differenza == 0) {
      nNulla++;
    } else
      nDispari++;

  } while (sommaAB > C);
  printf("differenza pari: %d\n", nPari);
  printf("differenza nDispari: %d\n", nDispari);
  printf("differenza nulla: %d\n", nNulla);
  return 0;
}