#include <stdio.h>
#include <stdlib.h>

#define buffer_dim 1024

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;

    unsigned char buffer[buffer_dim];

    if (argc != 3)
    {
        printf("numero di argomenti sbagliato");
        return 1;
    }

    origine = fopen(argv[1], "r");

    if (origine == NULL)
    {
        printf("Errore apertura file origine");
        return 1;
    }
    destinazione = fopen(argv[2], "w");
    if (destinazione == NULL)
    {
        printf("Errore apertura file destinazione");
        fclose(origine);
        return 1;
    }
    while (!feof(origine))
    {
        int n = fread(destinazione, buffer_dim, 1, origine);
        if (n > 0)
            fwrite(buffer, n, 1, destinazione);
    }
    fclose(origine);
    fclose(destinazione);
    printf("Copia completata.\n");
    return 0;
}