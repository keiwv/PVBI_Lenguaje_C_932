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
        op = msge_menu(); // WE CALL THE MESSAGES FUNCTION HERE TO GET THE OPTION.
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
// MESSAGES FROM THE MENU
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Fibonacci sin Recursion\n");
    printf("2.- Fibonacci con Recursion\n");
    printf("3.- Triángulo de Pascal\n");
    printf("0.- Salir\n");
    op = valid("Selecciona tu opcion: ", 0, 3);
    return op;
}

/*
    FUNCTION: VALID
    DESCRIPTION: IN THIS FUNCTION
*/
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

// In this function, we ask if we want to leave or not.
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

/*
Function: calculateFibonacciNoRecursion
Description: This function calculates and prints the Fibonacci sequence without using recursion.
Parameters: None.
Return Value: None (void).
*/
void calculateFibonacciNoRecursion()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("\nFIBONACCI METHOD WITHOUT RECURSION\n");
        num = valid("Enter the number of Fibonacci numbers you want to print: ", 0, INT_MAX);

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

/*
Function: calculateFibonacciRecursion
Description: This function calculates the nth Fibonacci number using recursion.
Parameters: None.
Return Value: The nth Fibonacci number.
*/
int calculateFibonacciRecursion()
{
    int num, i, tempnum, tempnum2, result;
    result = 0;
    printf("\nFIBONACCI METHOD WITH RECURSION\n");
    num = valid("Enter the number of Fibonacci numbers you want to print: ", 0, INT_MAX);

    // We use this if to skip two special cases in the Fibonacci sequence.
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

/*
Function: trianglePascal
Description: This function prints a Pascal's triangle with a user-specified number of lines.
Parameters: None.
Return Value: None (void).
*/
void trianglePascal()
{
    int number, op, line, space, coef, i;
    do
    {
        number = valid("Enter the number of lines you want to use: ", 0, INT_MAX);

        for (line = 1; line <= number; line++)
        {
            for (space = 1; space <= number - line; space++)
            {
                printf("  ");
            }

            coef = 1;
            for (i = 1; i <= line; i++)
            {
                printf("%4d", coef);
                coef = coef * (line - i) / i;
            }
            printf("\n");
        }
        op = leave();
    } while (op != 0);
}
