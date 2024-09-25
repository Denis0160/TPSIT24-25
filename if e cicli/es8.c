// Author:Sescu Denis
// Data:25/09/2024

/*
Progettare un algoritmo che risolve il seguente problema. Si desidera
calcolare la somma delle radici quadrate di N valori numerici inseriti
dall’utente, con N inserito in input.
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).
*/

#include <math.h>
#include <stdio.h>

int main() {
  int N;
  double somma = 0;

  printf("Quanti numeri vuoi inserire?\n");
  scanf("%d", &N);

  int numero[N];

  for (int i = 0; i < N; i++) {
    printf("Inserisci il %d numero\n", i + 1);
    scanf("%d", &numero[i]);

    if (numero[i] > 0) {
      somma = somma + sqrt(numero[i]);
    } else {
      printf("Numero errato\n");
      return 1;
    }
  }
  printf("la somma risulta: %.2f", somma);
}
