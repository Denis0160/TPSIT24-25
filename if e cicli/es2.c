
#include <stdio.h>

int main() {
  int num1, num2;
  double prodotto;
  double somma = 0;

  do {
    printf("Inserisci il primo numero\n");
    scanf("%d", &num1);
    if (num1 == 0) break;
    printf("Inserisci il secondo numero\n");
    scanf("%d", &num2);
    if (num2 == 0) break;

    if (num1 > num2)
      prodotto = num1 / num2;
    else
      prodotto = num2 / num1;
    printf("il prodotto e': %.2f\n", prodotto);

    somma += prodotto;

  } while (num1 != 0 && num2 != 0);
  printf("la somma dei prodotti riulta:%.2f ", somma);

  return 0;
}