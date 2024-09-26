// Author:Sescu Denis
// Data:25/09/2024

/*
Progettare un algoritmo che risolva il seguente problema. Si richieda
all’utente di inserire una serie di terne di dati numerici (A, B, C).
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.
*/

#include <math.h>
#include <stdio.h>

    int
    main ()
{

  int A, B, C;
  int max, min;

  do
    {
      printf ("Inserisci il valore A\n");
      scanf ("%d", &A);
      printf ("Inserisci il valore B\n");
      scanf ("%d", &B);
      printf ("Inserisci il valore C\n");
      scanf ("%d", &C);

      if (A < B && B < C)
        {
          max = A;

          if (B > max)
            {
              max = B;
            }
          if (C > max)
            {
              max = C;
            }

          min = A;

          if (B < min)
            {
              min = B;
            }
          if (C < min)
            {
              min = C;
            }


        }
      else
        printf ("I numeri non sono in ordine\n");
    }
  while (A >= 0 && B >= 0 && C >= 0);
    printf ("Il numero minimo è: %d\n", min);
    printf ("Il numero massimo è: %d\n", max);
  return 0;
}
