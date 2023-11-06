/*

*/

//***** LIBRARIES *****
#include "Frijoles.h"
#include <limits.h>
#include <string.h>
//***** PROTOTYPE FUNCTIONS *****
int msge_menu();
void menu();

void argLineCmds(int a, int b);
void ordArrays();
void matrix(int *ptr);
//***** MAIN FUNCTIONS *****
int main(int argc, char *argv[])
{
    printf("%d\n", argc);

    int num_1, num_2;
    num_1 = atoi(argv[1]);
    num_2 = atoi(argv[2]);

    menu(num_1, num_2);
    return 0;
}
//***** PROTOTYPE FUNCTIONS DEVELOPMENT *****

int msge_menu()
{
    printf("1.- Argumentos en linea de comandos\n");
    printf("2.- Ordenacion de palabras\n");
    printf("3.- Matriz multidimensional\n");
    printf("0.- Salir\n");
    return valid("Selecciona tu opcion: ", 0, 3);
}

void menu(int a, int b)
{
    int op;
    int random[3][3] = {{30, 2, 4}, {10, 32, 42}, {32, 21, 99}};
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            argLineCmds(a, b);
            break;
        case 2:
            ordArrays();
            break;
        case 3:
            matrix(&random[0][0]);
            break;
        }
    } while (op != 0);
}
void argLineCmds(int a, int b)
{
    printf("El resultado de la suma es: %d\n", a + b);
    printf("El resultado de la resta es: %d\n", a - b);
    printf("El resultado de la multiplicacion es: %d\n", a * b);
    printf("El resultado de la division es: %d\n", a / b);
    system("PAUSE");
}

void ordArrays()
{

    char ctrs[][15] = {"Manzana", "Pera", "Uva", "Cereza", "Naranja", "Toronja", "Sandia", "Pina", "Durazno"};
    char *q[9] = {ctrs[0], ctrs[1], ctrs[2], ctrs[3], ctrs[4], ctrs[5], ctrs[6], ctrs[7], ctrs[8]};

    int i, j;
    printf("Arreglo sin ordenar: \n");
    for (i = 0; i < 8; i++)
    {
        printf("%d.- %s\n", i + 1, q[i]);
    }
    printf("Arreglo ordenado: \n");
    char *temp;
    for (i = 0; i < 9 - 1; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            if (strcmp(q[i], q[j]) > 0)
            {
                temp = q[i];
                q[i] = q[j];
                q[j] = temp;
            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        printf("%d.- %s\n", i + 1, q[i]);
    }
    system("PAUSE");
}

void matrix(int *ptr)
{
    int i, j;
    int result;
    int max = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("[%d]  ", *(ptr + i * 3 + j));
            result += *(ptr + i * 3 + j);
            if (max < *(ptr + i * 3 + j))
            {
                max = *(ptr + i * 3 + j);
            }
        }
        printf("\n");
    }
    printf("La suma de los valores es: %d\n", result);
    printf("El numero mayor es: %d\n", max);
    system("PAUSE");
}
