/*
 */

//**** LIBRARIES ******
#include "Frijoles.h"
#include <time.h>
#include <ctype.h>
//**** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

void busquedaLineal_Metodo1(int *p, int m, int n);
void busquedaLineal_Metodo2(int v[], int m, int n);
void busquedaLineal_Metodo3(int A[][3], int m, int n);
void busquedaLineal_Metodo4(int *p[], int m, int n);
void busquedaLineal_Metodo5(int **q, int m, int n);

//**** MAIN FUNCTION ******
int main()
{
    menu();
    return 0;
}

//***** PROTOTYPE FUNCTIONS DEVELOPMENT ****
void menu()
{
    int op;
    srand(time(NULL));
    int n, m, i, j, iteracion;
    n = (rand() % 15) + 1;
    m = (rand() % 100) + 1;
    int matriz[m][n];
    int vector[m];
    int *q[m];
    int **t = q;
    clock_t inicio, fin;
    double tiempo;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matriz[i][j] = (rand() % 100) + 1;
        }
    }

    for (i = 0; i < m; i++)
    {
        vector[i] = (rand() % 100) + 1;
    }
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            iteracion = valid("cuantas veces lo quieres iterar?", 1, 5000);
            for (i = 0; i < iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo1(&matriz[0][0], m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;
        case 2:
            iteracion = valid("cuantas veces lo quieres iterar?", 1, 5000);
            for (i = 0; i < iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo2(vector, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;
        case 3:
            iteracion = valid("cuantas veces lo quieres iterar?", 1, 5000);
            for (i = 0; i < iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo3(matriz, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;

        case 4:
            iteracion = valid("cuantas veces lo quieres iterar?", 1, 5000);
            for (i = 0; i < m; i++)
            {
                q[i] = &matriz[i][0];
            }
            for (i = 0; i < iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo4(q, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;

        case 5:
            iteracion = valid("cuantas veces lo quieres iterar?", 1, 5000);
            for (i = 0; i < iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo5(t, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion del Método 5: %f seg.", tiempo);
            printf("\n\n");
            break;
        }
    } while (op != 0);
}

int msge_menu()
{
    printf("1.- Metodo 1\n");
    printf("2.- Metodo 2\n");
    printf("3.- Metodo 3\n");
    printf("4.- Metodo 4\n");
    printf("5.- Metodo 5\n");
    printf("0.- Salir");
    return valid("Selecciona tu opcion: ", 0, 5);
}

void busquedaLineal_Metodo1(int *p, int m, int n) // funcion del metodo 1 de busqueda
{
    int i, j;
    printf("metodo 1\n");
    printf("Matriz\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(p + i * n + j));
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo2(int v[], int m, int n) // funcion del metodo 2 de busqueda
{
    int i, j;
    printf("metodo 2\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", v[i * n + j]);
        }
        // printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo3(int A[][3], int m, int n) // funcion del metodo 3 de busqueda
{
    int i, j;
    printf("metodo 3\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo4(int *p[], int m, int n) // funcion del metodo 4 de busqueda
{
    int i, j;
    printf("metodo 4\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo5(int **q, int m, int n) // funcion del metodo 5 de busqueda
{
    int i, j;
    printf("metodo 5\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}