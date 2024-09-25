
#include <stdio.h>
#include <math.h>

int main() {
  int num1, num2;
  double prodotto;
  double radice;

  do {
    printf("Inserisci il primo numero\n");
    scanf("%d", &num1);
    if (num1==0){
        printf("Non puoi dividere per 0!");
        break;
    } 
    printf("Inserisci il secondo numero\n");
    scanf("%d", &num2);
    if (num1==0){
        printf("Non puoi dividere per 0!");
        break;
    } 
    
    if (num1 > num2)
      prodotto = num1 / num2;
    else
      prodotto = num2 / num1;
    printf("il prodotto e': %.2f\n", prodotto);
    
    radice=prodotto;
    
    if(radice>0){
        radice=sqrt(radice);
        printf("La radice del prodotto risulta %.2f\n",radice);
    }else{
        printf("non si puo calcolare la radice di un numero negativo");
        break;
    }
    

    

  } while (radice>0);
 

  return 0;
}