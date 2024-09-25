// Author:Sescu Denis
// Data:25/09/2024

/*
Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il
software gestionale il quale le chiede di inserire una alla volta le
consumazioni servite. Le consumazioni si dividono in bevande e ristorazione. La
cassiera per ogni consumazione deve inserire la tipologia di consumazione e il
suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video
le seguenti informazioni: 1.	La media dell’incasso delle bevande 2.	La media
dell’incasso della ristorazione 3.	Deve indicare se sono state vendute più
bevande o più ristorazioni
*/

#include <stdio.h>
#include <string.h>

int main ()
{
  char tipologia[12];
  double contBevande = 0, contRistorazione = 0, mediaBevande, mediaRistorazione,
         importoBevande, importoRistorazione;
  double sommaImportoB = 0, sommaImportoR = 0;

  do
    {
      printf ("Inserisci il tipo di consumazione: 1) ristorazione 2)bevande "
              "3)esci\n");
      scanf ("%s", tipologia);

      if (strcmp (tipologia, "esci") == 0)
        {
          break; // Esci dal ciclo
        }

      if (strcmp (tipologia, "ristorazione") == 0)
        {
          contRistorazione++;
          printf ("Inserisci l'importo della ristorazione\n");
          scanf ("%f", &importoRistorazione);
          sommaImportoR = sommaImportoR + importoRistorazione;
        }

      if (strcmp (tipologia, "bevande") == 0)
        {
          contBevande++;
          printf ("Inserisci l'importo per le bevande\n");
          scanf ("%f", &importoBevande);
          sommaImportoB = sommaImportoB + importoBevande;
        }
    }while (1);

  mediaBevande = sommaImportoB / contBevande;
  mediaRistorazione = sommaImportoR / contRistorazione;
  printf ("La media dell'incasso delle bevande e': %.2f\n", mediaBevande);
  printf ("La media dell'incasso della ristorazione e':%.2f\n",
          mediaRistorazione);
  if (contBevande > contRistorazione)
    {
      printf ("sono state vendute piu bevande\n");
    }
  else if (contBevande < contRistorazione)
    {
      printf ("sono state vendute piu ristorazioni\n");
    }
  else
    printf ("sono state vendute lo steso numero di bevande e ristorazioni");
}