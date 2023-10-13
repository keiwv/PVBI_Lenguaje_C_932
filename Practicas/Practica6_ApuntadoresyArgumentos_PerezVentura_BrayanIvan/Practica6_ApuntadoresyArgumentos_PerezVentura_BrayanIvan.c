/*

*/

//**** LIBRARIES ***
#include <stdio.h>
#include <stdlib.h>
#include "Frijoles.h"

//**** PROTOTYPE FUNCTIONS ****
void menu();
int msge_menu();

void sumArray(int size, int *array);
void copyArrayy(int size, int *array, int *copyArray);
void concatenateArrays(int size, int *array, int *newArray, int *finalArray, int nSize);
int comparationArray(int size, int *array, int *compArray);
int findElementMax(int size, int *array);
void fillArray(int size, int array[], int ri, int rs);
//**** MAIN FUNCTIONS ***
int main()
{
    menu();
    return 0;
}
//**** PROTOTYPE DEVELOPMENT FUNCTIONS ****
void menu()
{
    int op, i, size, nSize;
    size = numRandom(1, 30);
    nSize = numRandom(1, 30);
    int array[size];
    int copyyArray[size];
    int newArray[nSize];
    int finalArray[size + nSize];
    int compArray[size];
    int compReturn, maxNumber;
    do
    {
        system("CLS");
        op = msge_menu();
        switch (op)
        {
        case 1:
            fillArray(size, array, 1, 30);
            sumArray(size, array);
            break;
        case 2:
            fillArray(size, array, 1, 30);
            copyArrayy(size, array, copyyArray);
            printf("Copiado correctamente\n");
            system("PAUSE");
            break;
        case 3:
            fillArray(size, array, 1, 30);
            fillArray(nSize, newArray, 1, 30);
            concatenateArrays(size, array, newArray, finalArray, nSize);
            for (i = 0; i < (nSize + size); i++)
            {
                printf("%d\n", finalArray[i]);
            }
            system("PAUSE");
            break;
        case 4:
            for (i = 0; i < size; i++)
            {
                array[i] = numRandom(0, 1);
                compArray[i] = numRandom(0, 1);
            }
            compReturn = comparationArray(size, array, compArray);
            if (compReturn == 1)
            {
                printf("Los arreglos son iguales\n");
            }
            else
            {
                printf("Los arreglos no son iguales\n");
            }
            system("PAUSE");
            break;
        case 5:
            fillArray(size, array, 1, 30);
            maxNumber = findElementMax(size, array);
            printf("El numero mayor encontrado es: %d\n", maxNumber);
            system("PAUSE");
        }
    } while (op != 0);
}

//******************
int msge_menu()
{
    int op;
    printf("1.- Suma de elementos en un arreglo\n");
    printf("2.- Copia de arreglos\n");
    printf("3.- Concatenacion de arreglos\n");
    printf("4.- Comparacion de arreglos\n");
    printf("5.- Encontrar el elemento máximo\n");
    printf("0.- Salir\n");
    op = valid("Selecciona una opcion: ", 0, 5);
    return op;
}

//****************
void sumArray(int size, int *array)
{
    int sum, i;
    sum = 0;
    int *ptr = array;
    for (i = 0; i < size; i++)
    {
        sum += *ptr;
        ptr++;
    }
    printf("%d\n", sum);
    system("PAUSE");
}

//*****************
void copyArrayy(int size, int *array, int *copyArray)
{
    int i;
    int *ptr1 = array;
    int *ptr2 = copyArray;
    for (i = 0; i < size; i++)
    {
        *ptr2 = *ptr1;
        ptr2++;
        ptr1++;
    }
    system("PAUSE");
}

//************
void concatenateArrays(int size, int *array, int *newArray, int *finalArray, int nSize)
{
    int i;
    int *ptr1 = array;
    int *ptr2 = newArray;
    int *ptr3 = finalArray;
    int fSize = nSize + size;
    for (i = 0; i < fSize; i++)
    {
        if (i < size)
        {
            *ptr3 = *ptr1;
            ptr1++;
            ptr3++;
        }
        else
        {
            *ptr3 = *ptr2;
            ptr2++;
            ptr3++;
        }
    }
}

int comparationArray(int size, int *array, int *compArray)
{
    int i;
    int *ptr1 = array;
    int *ptr2 = compArray;
    for (i = 0; i < size; i++)
    {
        if (*ptr2 != *ptr1)
        {
            return 0;
        }
        ptr2++;
        ptr1++;
    }
    return 1;
}

int findElementMax(int size, int *array)
{
    int max = *array;
    int *ptr = array + 1;
    for (int i = 1; i < size; i++)
    {
        if (*ptr > max)
        {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}

void fillArray(int size, int array[], int ri, int rf)
{
    int i;
    for(i = 0; i < size; i++)
    {
        array[i] = numRandom(ri,rf);
    }
}