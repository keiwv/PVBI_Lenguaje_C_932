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
#include <math.h>

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
    int op, op2, result;
    do
    {
        op = msge_menu(); //WE CALL THE MESSAGES FUNCTION HERE TO GET THE OPTION.
        switch (op)
        {
        case 1:
            calculateFibonacciNoRecursion();
            break;
        case 2:
            do
            {
                result = calculateFibonacciRecursion();
                printf("El resultado es: %d", result);
                op2 = leave();
            } while (op2 != 1);

            break;
        case 3:
            trianglePascal();
            break;
        }
    } while (op != 0);
}
//MESSAGES FROM THE MENU
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
    return op;
}

//IN THIS FUNCTION, WE VALID IF THEIR INPUT IS A NUMBER, IF IT IS NOT, IT WILL LOOP UNTIL IT GETS THE RIGHT NUMBER. (IT WONT CRASH IF WE INTRODUCE A LETTER).
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

//In this function, we ask if we want to leave or not.
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
        printf("\nMETODO DE FIBONACCI SIN RECURSION\n");
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
    int num, i, tempnum, tempnum2, result;
    result = 0;
    printf("\nMETODO DE FIBONACCI CON RECURSION\n");
    num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);

    //We use this if to skip two special cases in the fibonacci method.
    if (num == 0)
    {
        return 0;
    }
    else
    {
        if (num == 1)
        {
            return 1;
        }
        else
        {
            for (i = 2, tempnum = 0, tempnum2 = 1; i <= num; i++)
            {

                result = tempnum2 + tempnum;
                tempnum = tempnum2;
                tempnum2 = result;
            }
            return result;
        }
    }
}

void trianglePascal()
{
    int op, num, result, i;
    result = 0;
    do
    {
        printf("\nTRIANGULO DE PASCAL\n");
        num = valid("Introduce la cantidad de numeros para el triangulo de pascal: ", 0, INT_MAX);

        for (i = 0; i <= num; i++)
        {
            result = pow(2, i);
            printf("%d ", result);
        }
        op = leave();
    } while (op != 1);
}