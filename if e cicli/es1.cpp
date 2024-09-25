
#include <stdio.h>

int main() {
  int num1, num2;
  double rapporto;

  do {
    printf("Inserisci il primo valore\n");
    scanf("%d", &num1);
    printf("Inserisci il secondo valore\n");
    scanf("%d", &num2);

    if (num1 > num2)
      rapporto = num1 / num2;
    else
      rapporto = num2 / num1;

    printf("Il rapporto è uguale a: %.2f\n", rapporto);
  } while (num1 > 0 && num2 > 0);

  return 0;
}