//Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
//ripetuta, il prodotto dei due numeri e visualizzarli.

#include<stdio.h>
int main(int argc, char *argv[]) {
	int n1,n2;
	int somma=0;
	do {

		printf("inserisci il primo numero\n");
		scanf("%d",&n1);
		printf("inserisci il secondo numero\n");
		scanf("%d",&n2);
		

	} while(n1<0 || n2<0);

	for (int i = 0; i < n2; i++) {
		somma+=n1;
	}

	printf("il prodotto risulta %d\n",somma);


	return 0;
}