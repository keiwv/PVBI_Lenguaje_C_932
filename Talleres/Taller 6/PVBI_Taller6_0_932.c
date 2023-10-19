#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void basicPtr();

void multiForTwo(int *ptr);

void vectorsPtr(int vector[]);
int findNumber(int vect[], int num);
void fillVectorNoRepeat(int vect[], int n, int ri, int rf);
int existElem(int vector[], int longi, int num);

void sumVector(int *ptr, int value);
int main()
{
    system("CLS");
    srand(time(NULL));
    int x = 10;
    int *ptr = &x;
    int value;
    int vector[7];
    value = 10;
    basicPtr();

    multiForTwo(ptr);
    printf("\nEl valor de 10 por 2 utilizando punteros es: %d\n\n", *ptr);
    system("PAUSE");

    vectorsPtr(vector);

    sumVector(vector, value);
    for(int i = 0; i < 7; i++)
    {
        printf("Vector %d: %d\n", i, vector[i]);
    }
    return 0;
}

void basicPtr()
{
    int x = 10;
    int *ptr;
    ptr = &x;

    printf("El valor de x es: %d y el valor el que apunta el apuntador es: %d\n", x, *ptr);
    system("PAUSE");
}

void multiForTwo(int *ptr)
{
    *ptr = *ptr * 2;
}

void vectorsPtr(int vector[])
{
    int *ptr;
    printf("\n IMPRESION DE ARREGLO CON PUNTEROS\n");
    ptr = vector;
    fillVectorNoRepeat(vector, 7, 1, 50);
    for(int i = 0; i < 7; i++, ptr++)
    {
        printf("Valor %d = %d\n", i, *ptr);
    }
    system("PAUSE");
}

void fillVectorNoRepeat(int vect[], int n, int ri, int rf)
{
    int num, range;
    int i;
    num = 0;
    range = (rf - ri) + 1;
    for (i = 0; i < n; i++)
    {
        do
        {
            num = (rand() % range) + ri;
        } while (existElem(vect, i, num) != -1);
        vect[i] = num;
    }
}

int existElem(int vector[], int longi, int num)
{
    int i;

    for (i = 0; i < longi; i++)
    {
        if (vector[i] == num)
        {
            return i;
        }
    }
    return -1;
}


void sumVector(int *array, int value)
{
    int i;
    for(i = 0; i <7; i++)
    {
        *(array + i) += value;
    }
}