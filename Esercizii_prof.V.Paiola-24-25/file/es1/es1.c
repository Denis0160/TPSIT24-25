/**
 * Acquisizione di un carattere da tastiera
Il programma deve leggere un singolo carattere inserito dall'utente tramite la funzione getc().

Visualizzazione del carattere su schermo
Il carattere inserito deve essere stampato a video usando putc().

Scrittura del carattere su file
Il programma deve salvare il carattere in un file chiamato output.txt usando la funzione fprintf().

Gestione del file
Il file deve essere aperto in modalità scrittura ("w") e correttamente chiuso dopo la scrittura.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    FILE *file;
    char c;

    printf("Inserisci un carattere: \n");

    c = getc(stdin);
    putc(c, stdout);

    file = fopen("output.txt","w");

    if(file == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    fprintf(file, "%c", c);
    fclose(file);

    return 0;


}