//Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
//visualizzare in ordine decrescente i numeri compresi tra N1 e N2. 
#include<stdio.h>
int main(int argc, char *argv[]) {
	int n1, n2;
	do {
		printf("inserisci il primo numero\n");
		scanf("%d",&n1);
		printf("Inserisci il secondo numero\n");
		scanf("%d",&n2);
	} while(n2<n1);

	 for (int i = n2 - 1; i > n1; i--) {
        printf("%d\n", i);
    }


	return 0;
}