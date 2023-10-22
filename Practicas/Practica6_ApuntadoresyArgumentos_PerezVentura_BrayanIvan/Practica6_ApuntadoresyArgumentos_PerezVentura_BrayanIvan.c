/*
Brayan Ivan Perez Ventura - 372781

Created code: October 11th 2023 / Modified code: Octuber 22th 2023

DESCRIPTION
In this program, we will implemented a program where it will be working with pointers.
It will display a menu where:
    1.- Sum the elements in an array: We will fill an array and using pointers, we will sum them.
    2.- Copy array: Using pointers, copy an array from a different array.
    3.- Concatenate arrays: Using pointers, we will concatenate arrays.
    4.- Comparation: We will comparate arrays using pointers
    5.- Find the max element. Using pointers, we need to find the max element in an array using pointers.

#NOTE: For this code, it's necessary the personal library called "Frijoles.h".


*/

//**** LIBRARIES ***

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
/*
Function: menu
Description: Implements a menu to perform various operations on arrays.
Parameters: None.
Return Value: None.
Variables:
- op: Integer to store the user's menu choice.
- i: Loop variable.
- size: Size of the main integer array.
- nSize: Size of the second integer array.
- array: Main integer array.
- copyyArray: Integer array used for copying elements.
- newArray: Second integer array.
- finalArray: Integer array to store the concatenated result.
- compArray: Integer array for array comparison.
- compReturn: Integer to store the result of array comparison.
- maxNumber: Maximum number in the array.
*/
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
            break;
        }
    } while (op != 0);
}

//******************
/*
Function: msge_menu
Description: Displays a menu to the user, asks them to select an option, and validates the user's input within a specified range.
Parameters: None.
Return Value: The value of the user's input (an integer representing the selected option).
Variables:
- op: An integer to store the user's choice.
*/
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
/*
Function: sumArray
Description: Calculates the sum of elements in an integer array.
Parameters:
- size: The size of the array.
- array: Pointer to the integer array.
Return Value: None.
Variables:
- sum: Integer to store the sum of array elements.
- i: Loop variable.
- ptr: Pointer to iterate through the array.
*/
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
    printf("La suma del vector es: %d\n", sum);
    system("PAUSE");
}

/*
Function: copyArrayy
Description: Copies the elements from one integer array to another.
Parameters:
- size: The size of the arrays.
- array: Pointer to the source array.
- copyArray: Pointer to the destination array.
Return Value: None.
Variables:
- i: Loop variable.
- ptr1: Pointer to iterate through the source array.
- ptr2: Pointer to iterate through the destination array.
*/
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

/*
Function: concatenateArrays
Description: Concatenates two integer arrays into a third array.
Parameters:
- size: The size of the first array.
- array: Pointer to the first array.
- newArray: Pointer to the second array.
- finalArray: Pointer to the concatenated array.
- nSize: The size of the second array.
Return Value: None.
Variables:
- i: Loop variable.
- ptr1: Pointer to iterate through the first array.
- ptr2: Pointer to iterate through the second array.
- ptr3: Pointer to iterate through the concatenated array.
- fSize: The size of the concatenated array.
*/
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

/*
Function: comparationArray
Description: Compares two integer arrays for equality.
Parameters:
- size: The size of the arrays.
- array: Pointer to the first array.
- compArray: Pointer to the second array.
Return Value: 1 if the arrays are equal, 0 otherwise.
Variables:
- i: Loop variable.
- ptr1: Pointer to iterate through the first array.
- ptr2: Pointer to iterate through the second array.
*/
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

/*
Function: findElementMax
Description: Finds the maximum element in an integer array.
Parameters:
- size: The size of the array.
- array: Pointer to the integer array.
Return Value: The maximum element in the array.
Variables:
- max: Integer to store the maximum element.
- ptr: Pointer to iterate through the array.
*/
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

/*
Function: fillArray
Description: Fills an integer array with random numbers within a given range.
Parameters:
- size: The size of the array.
- array: Integer array to be filled.
- ri: Minimum random value.
- rf: Maximum random value.
Return Value: None.
Variables:
- i: Loop variable.
*/
void fillArray(int size, int array[], int ri, int rf)
{
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = numRandom(ri, rf); // Note: The function numRandom is used, but it's not defined in the provided code.
    }
}
