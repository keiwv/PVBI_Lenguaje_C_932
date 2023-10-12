/*
Brayan Ivan Perez Ventura - 372781

Código creado: 06 de Septiembre del 2023 / Código modificado: 06 de Septiembre del 2023

Algoritmo para el juego adivinanza de números con etiquetas y "goto".

Actividad Clase 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num_secreto, adivinar, op, i;
    srand(time(NULL));

    inicio:
        i = 0;
        num_secreto = rand() % 100 + 1;
        printf("Juego de adivinar un numero\n");
        printf("El juego se podra repetir las veces que quieras.\n");
        printf("Tendras intentos infinitos pero al final te mostrara la cantidad de intentos\n");
        goto adivinanza;

    adivinanza:
        printf("Por favor, ingresa un numero entero: ");
        scanf("%d",&adivinar);

        if(adivinar == num_secreto){
            printf("Felicidades, has ganado, el numero era: %d con %d intentos", adivinar, i);
            goto reinicio;
        }
        if(adivinar > num_secreto){
            printf("Es menor\n");
            i++;
            goto adivinanza;
        } else {
            printf("Es mayor\n");
            i++;
            goto adivinanza;
        }
    reinicio:
        printf("\nDesea continuar?\n");
        printf("1.- Si\n");
        printf("2.- No\n");
        printf("Introduce tu respuesta: ");
        scanf("%d",&op);
        if((op != 1)&&(op != 2)){
            printf("\nIntroduce una opcion valida.");
            goto reinicio;
        }
        if(op == 1){
            goto inicio;
        } else {
            printf("Gracias por jugar, adios!\n");
        }
        
}