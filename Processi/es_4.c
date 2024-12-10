
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * Scriva un programma in linguaggio C che dato un array prestabilito, prenda in input da
 * riga di comando un numero e lo ricerchi all'interno dell'array.
 * La ricerca deve essere demandata ad un processo figlio e deve essere
 * implementata attraverso un'apposita funzione di nome "ricerca".
 */
int ricerca(int numeri[], int n, int numero)
{
    for (int i = 0; i < n; i++)
    {
        if (numeri[i] == numero)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int dim = 11; // dimensione dell'array
    
    int numeri[] = {1, 4, 23, 65, 6, 9, 3, 12, 11, 5, 13};

    if (argc != 2)
    {
        printf("Devi fornire un numero da cercare.\n");
        return 1;
    }

    int pid = fork();

    if (pid == 0)
    {

        int numero = atoi(argv[1]); // Converte l'argomento in un numero intero
        int posizione = ricerca(numeri, dim, numero);

        if (posizione != -1)
        {
            printf("Il numero %d si trova in posizione %d nell'array.\n", numero, posizione);
        }
        else
        {
            printf("Il numero %d non è presente nell'array.\n", numero);
        }

        exit(0); 
    }

    wait(NULL); // Il processo padre aspetta che il figlio termini

    return 0;
}
