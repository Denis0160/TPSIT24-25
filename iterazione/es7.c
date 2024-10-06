//Dato N un numero intero positivo maggiore di 1, generare e visualizzare
//il numero precedente.
#include<stdio.h>
int main(int argc, char *argv[]) {
	int N, P;
	do {
		printf("inserisci un numero positivo maggiore di 1\n");
		scanf("%d",&N);
	} while(N<1);
	P=N+1;
	printf("Il suo successivo C(:%d\n",P);
	return 0;
}