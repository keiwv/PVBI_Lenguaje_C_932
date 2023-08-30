
#include <stdio.h>

int main(){
    int num_entero;
    printf("Programa para convertir numeros enteros a binario\n");
    printf("Ingrese un numero entero: ");
    scanf("%d",&num_entero);

    if (num_entero < 0){
        return 1;
    }
    int num_bits = 0;
    int temp = num_entero;

    while(temp>0){
        temp/=2;
        num_bits++;
        printf("Numero decimal: %d  Numero temp: %d\n", num_bits, temp);
    }

    int bits[num_bits];
    int indice;
    while (num_entero>0){
        bits[indice] = num_entero % 2;
        num_entero = num_entero / 2;
        indice++;
        printf("bits indice: %d -- num entero: %d -- Indice: %d\n\n", bits[indice], num_entero, indice);
    }

    printf("Numero en bits: ");

    for(int i = indice-1;i>=0;i--){
        printf("%d",bits[i]);
    }
    printf("\n");
    return 0;
}
