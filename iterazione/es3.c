// Author: Sescu Denis
// Data: 26/09/2024

#include <stdio.h>

int main() {
    int n, dispari = 1; 

    
    do {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    while (dispari <= n) {
        printf("%d\n", dispari);
        dispari += 2; 
    }

    return 0;
}
