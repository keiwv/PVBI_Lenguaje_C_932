/*
    File name: Practica3_JuegoAdivinanzaEtiquetasGoto_PerezVentura_BrayanIvan
    Author: Brayan Ivan Perez Ventura
    Date of creation: September 17th 2023 // Date of modification: September 21th 2023
    Program description:
    In this program, three functions will be implemented, each of which will aim to perform the following:

        1.-Non-recursive Fibonacci: Create a function that calculates and displays the first n terms of the Fibonacci series without using recursion.

        2.-Recursive Fibonacci: Create a function that calculates and displays the nth term of the Fibonacci series using a recursive function.

        3.- Pascal's Triangle: Create a function that generates and displays the first n rows of Pascal's Triangle.
*/

//**** LIBRARIES *********
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

//***** PROTOTYPE FUNCTIONS *******
void menu();
int msge_menu();
int valid(char msge[], int rl, int rh);
int leave();

void calculateFibonacciNoRecursion();
int calculateFibonacciRecursion();
void trianglePascal();
//**** MAIN FUNCTION **********
int main()
{
    menu();
    return 0;
}

//***** FUNCTION DEVELOPMENT ********
//***** MENU DEVELOPMENT *********
void menu()
{
    int op;
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            calculateFibonacciNoRecursion();
            break;
        case 2:
            int result, op;
            do
            {
                result = calculateFibonacciRecursion();
                printf("El resultado es: %d", result);
                op = leave();
            } while (op != 1);

            break;
        case 3:
            trianglePascal();
            break;
        }
    }
}

int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Fibonacci sin Recursion\n");
    printf("2.- Fibonacci con Recursion\n");
    printf("3.- Triángulo de Pascal\n");
    printf("0.- Salir\n");
    printf("Selecciona tu opcion: ");
    op = valid("Selecciona tu opcion: ", 0, 3);
}

int valid(char msge[], int ri, int rf)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(cadena, sizeof(cadena), stdin);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

int leave()
{
    int op;
    printf("\nDesea salir?\n");
    printf("0.- No\n");
    printf("1.- Si\n");
    op = valid("Selecciona una opcion: ", 0, 1);
    return op;
}
//***** THREE FUNCTIONS *********

void calculateFibonacciNoRecursion()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("\nMETODO DE FIBONACCI POR FOR\n");
        num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);

        for (i = 0, tempnum = 0, tempnum2 = 1; i <= num; i++)
        {
            printf("%d  ", tempnum);

            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
        }
        op = leave();

    } while (op != 1);
}
int calculateFibonacciRecursion()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    printf("\nMETODO DE FIBONACCI\n");
    num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);

    for (i = 0, tempnum = 0, tempnum2 = 1; i <= num; i++)
    {

        result = tempnum2 + tempnum;
        tempnum = tempnum2;
        tempnum2 = result;
    }
    return tempnum2;
}
void trianglePascal()
{
    
}