#include <stdio.h>

int main(int argc, char *argv[])
{
    char car;
    printf("\nInserici un carrattere: -->   ");
    car = getc(stdin);
    printf("Hai inserito il carattere %c\n", car);
    printf("Hai inserito il carattere %d\n", car);

    putc(car, stdout);

    FILE *fp;
    fp = fopen("es8.txt", "w");
    if (fp != NULL)
    {
        printf("\n Il file è stato aperto correttamente\n");
        putc(car, fp);
        fclose(fp);
    }
    else
    {
        printf("\n Il file non è stato aperto correttamente\n");
    }
    putchar(car);
    printf("\n");

    return 0;
}