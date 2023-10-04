/*
    EXAM LENGUAJE C CLASS
    CODE CREATED: OCTOBER 4TH 2023 // MODIFIED: OCTOBER 4TH 2023

    BRAYAN IVAN PEREZ VENTURA - 372781

    PVBI_Exam_1_932
*/

#include "Frijoles.h"
#include <limits.h>

int functionExam(int num);
int leave();

int main()
{
    do
    {
        system("CLS");
        int fin;
        printf("ENCONTRAR TODOS LOS NUMEROS ENTEROS \n");
        fin = valid("Ingresa el rango que deses saber cuantos numeros numeros perfectos hay ", 1, INT_MAX);
        int flag = 0;
        for (int i = 1; i <= fin; i++)
        {
            if (functionExam(i))
            {
                if (i != 1)
                {
                    printf("%d\n", i);
                    flag = 1;
                }
            }
        }
        if (flag != 1)
        {
            printf("\nNo se encontrar valores\n");
        }
    } while (leave() != 1);
}

int functionExam(int num)
{
    int sumaDivisores = 1;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            sumaDivisores += i;
            if (i != num / i)
            {
                sumaDivisores += num / i;
            }
        }
    }

    return sumaDivisores == num;
}

int leave()
{
    int op;
    printf("Deseas salir?\n 1.- Si\n 0.- No\n");
    op = valid("Selecciona tu opcion: ", 0, 1);
    return op;
}