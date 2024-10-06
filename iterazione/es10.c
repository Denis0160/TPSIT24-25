//Dato N un numero intero positivo, calcolare e visualizzare la somma dei
//primi N numeri interi.
#include<stdio.h>
int main(int argc, char *argv[]) {
	int n;
	int somma=0;
	do {

		printf("inserisci il numero\n");
		scanf("%d",&n);

	} while(n<0);

	for (int i = n - 1; i > 0; i--) {
		printf("%d\n", i);
		somma=somma+i;
	}

	printf("La somma risulta %d\n",somma);


	return 0;
}