//Dato N un numero intero positivo, generare e visualizzare in ordine
//decrescente i primi N numeri interi positivi.
#include<stdio.h>
int main(int argc, char *argv[]) {
	int N, P;
	do {
		printf("inserisci un numero positivo maggiore di 1\n");
		scanf("%d",&N);
	} while(N<0);
	
	do{
	    P=N-1;
	    printf("%d\n",P);
	    N=P;
	}while(P>0);
	
	
	return 0;
}