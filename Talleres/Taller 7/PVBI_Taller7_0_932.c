/*
Brayan Ivan Perez Ventura - 372781

Created code: October 11th 2023 / Modified code: Octuber 22th 2023

DESCRIPTION
In this program, we will implemented a program where it will be working with pointers.
It will display a menu where:
    1.- Using pointers, we will display 3 names that has been declared already.
    2.- We will save user input and display it using pointers.
    3.- Using pointers, we will revert a string.
    4.- We will ordenate in an alphabethic order user input.

#NOTE: For this code, it's necessary the personal library called "Frijoles.h".

*/

// ******* LIBRARIES ********
#include <stdio.h>
#include <stdlib.h>
#include "Frijoles.h"
#include <string.h>

// ******* PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

void displayNamesPtr(char *array[], int size);
void invertString(char *array);
void inputWords();
void alphaWord(char *array[], int size);
// ******* MAIN FUNCTION ******
int main()
{
    menu();
    return 0;
}
// ******* PROTOTYPE FUNCTIONS DEVELOPMENT *****
void menu()
{
    int op, i;
    char *inputNames[3];
    char letters[5][50];
    char invertString1[] = "Esta es una prueba";

    char *names[3];
    names[0] = "ROGELIO";
    names[1] = "JULIO";
    names[2] = "AGIS";

    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");

        switch (op)
        {
        case 1:
            displayNamesPtr(names, 3);
            break;
        case 2:
            for (i = 0; i < 3; i++)
            {
                printf("Por favor, introduce el nombre %d: ", i + 1);
                inputNames[i] = letters[i];
                scanf("%s", inputNames[i]);
            }

            printf("Los nombres introducidos son: \n");
            displayNamesPtr(inputNames, 3);
            break;
        case 3:
            printf("La cadena normal es: %s\n", invertString1);
            invertString(invertString1);
            printf("La cadena invertida es: %s\n", invertString1);
            break;
        case 4:
            inputWords();
            break;
        }
        system("PAUSE");
    } while (op != 0);
}

int msge_menu()
{
    int op;
    printf("1.- Arreglo y apuntadores con 3 nombres\n");
    printf("2.- Ingresar usuario e imprimirlo\n");
    printf("3.- Invertir Cadena\n");
    printf("4.- Ingresa una lista de 10 palabras\n");
    printf("0.- Salir\n");
    op = valid("Ingresa tu opcion: ", 0, 5);
    return op;
}

void displayNamesPtr(char *array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("El nombre %d es: %s\n", i + 1, array[i]);
    }
}

void invertString(char *array)
{
    char character;
    int size, j, i;
    size = strlen(array);
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        character = array[i];
        array[i] = array[j];
        array[j] = character;
    }
}

void inputWords()
{
    char *array[5];
    char words[5][50];
    int i;
    for (i = 0; i < 5; i++)
    {
        array[i] = words[i];
        printf("Ingresa la palabra %d: ", i + 1);
        scanf(" %s", array[i]);
    }
    alphaWord(array, 5);
    printf("Las palabras ordenadas alfabeticamente: \n");

    displayNamesPtr(array, 5);
}

void alphaWord(char *array[], int size)
{
    int i, j;
    char temp[30];

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(array[i], array[j]) == 1)
            {
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}
