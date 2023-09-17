#include <stdio.h>

int main()
{
    int limite;
    int resultado = 0;

    printf("Ingrese un numero entero positivo");
    scanf("%d", &limite);
    for (int i = 1; i <= limite; i++)
    {
        resultado += i;
    }
    printf("La suma de los primeros %d numeros es: %d\n", limite, resultado);

    return 0;
    
}