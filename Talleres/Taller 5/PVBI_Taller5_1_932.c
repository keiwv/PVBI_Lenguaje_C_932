/*
Brayan Ivan Perez Ventura - 372781

Created code: September 30th 2023 / Last modified: September 30th 2023

In this code we will:
    1. Declare an automatic variable named "counter" within a function. Increment its value in a loop and display its value in each iteration.
    2. Declare an external variable named "saldo" in one source file (file.c) and access it from another source file (anotherfile.c). Modify its value in both files and display the final value.
    3. Declare a static variable named "counter" within a function and display its value in each function call.
    4. Declare a register variable named "temp" and an automatic variable named "value" within a function. Compare the access and lifetime of these variables.
    5. Declare a global variable named "PI" with a value of 3.14159 and another local variable with the same name in a function (with a different value).

PVBI_Taller3_2_932
*/
//*** LIBRARIES ****
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//*** GLOBAL AND EXTERN VARIABLES ***
float PI = 3.14159;

extern int saldo;
//*** PROTOTYPE FUNCTIONS ***
void menu();
int msge_menu();

int valid(char msge[], int ri, int rf);

void variableAuto();
void variableExt();
void mainVariableStatic();
void variableRegister();
void variableLocalGlobal();

void variableStatic();
//*** MAIN FUNCTION ***

int main()
{
    menu();
    return 0;
}

//*** PROTOTYPE FUNCTION DEVELOPMENT ***
/*
Function: menu
Description: Displays a menu to the user and allows them to choose between different options, each calling a specific function.
Parameters: None.
Return Value: None (void).
Variables:
- op: An integer to store the user's choice.
*/
void menu()
{
    int op;
    do
    {
        op = msge_menu(); // WE CALL THE MESSAGES FUNCTION HERE TO GET THE OPTION.
        switch (op)
        {
        case 1:
            variableAuto();
            break;
        case 2:
            variableExt();
            break;
        case 3:
            mainVariableStatic();
            break;
        case 4:
            variableRegister();
            break;
        case 5:
            variableLocalGlobal();
            break;
        }
        printf("\nPresiona una tecla para continuar...");
        getchar();
    } while (op != 0);
}

/*
Function: msge_menu
Description: Displays a menu to the user and prompts them to select an option. Validates the user's input.
Parameters: None.
Return Value: The value of the user's input.
Variables:
- op: An integer to store the user's choice.
*/
int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.- Variable Automatica\n");
    printf("2.- Variable Externa\n");
    printf("3.- Variable Estatitica\n");
    printf("4.- Variable Registro\n");
    printf("5.- Variable Global\n");
    printf("0.- Salir\n");
    op = valid("Selecciona tu opcion: ", 0, 5);
    return op;
}

/*
Function: valid
Description: Validates user input within a specified range.
Parameters:
- msge: A message to display to the user for input.
- ri: The minimum allowed value.
- rf: The maximum allowed value.
Return Value: User input.
Variables:
- num: An integer to store the user's input.
- cadena: A character array to temporarily store user input.
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

/*
Function: variableAuto
Description: Demonstrates the use of automatic variables and increments a count variable.
Parameters: None.
Return Value: None (void).
Variables:
- i: A loop control variable.
- count: An automatic integer variable.
*/
void variableAuto()
{
    int i;
    auto int count = 0;
    printf("VARIABLE AUTOMATICA\n");
    for (i = 0; i <= 5; i++)
    {
        printf("%d ", count);
        count++;
    }
}

/*
Function: variableExt
Description: Demonstrates the use of an external variable (saldo) and increments it.
Parameters: None.
Return Value: None (void).
*/
void variableExt()
{
    printf("Variable Externa\n");
    saldo += 50;
    printf("Saldo final de anotherfile.c: %d", saldo);
}

/*
Function: mainVariableStatic
Description: Calls the variableStatic function multiple times to demonstrate static variables.
Parameters: None.
Return Value: None (void).
Variables:
- i: A loop control variable.
*/
void mainVariableStatic()
{
    int i;
    printf("VARIABLE ESTATICA\n");
    for (i = 0; i < 5; i++)
    {
        variableStatic();
    }
    printf("Vuelve a entrar para ver cambios\n");
}

/*
Function: variableRegister
Description: Demonstrates the use of a register variable and an automatic variable.
Parameters: None.
Return Value: None (void).
Variables:
- temp: A register integer variable.
- valor: An automatic integer variable.
*/
void variableRegister()
{
    register int temp;
    auto int valor;
    
    printf("VARIABLE DE REGISTRO\n");

    temp = 15;
    valor = 5;

    printf("El valor de la variable registro es: %d\n", temp);
    printf("El valor de la variable automatica es: %d\n", valor);
}

/*
Function: variableLocalGlobal
Description: Demonstrates the difference between a global and a locally declared variable with the same name (PI).
Parameters: None.
Return Value: None (void).
*/
void variableLocalGlobal()
{
    printf("VALOR DE PI GLOBAL Y LOCALMENTE\n");
    printf("El valor de PI sin modificar es: %f\n", PI);

    float PI = 4.142541;

    printf("El valor de PI modificado es: %f", PI);
}

/*
Function: variableStatic
Description: Demonstrates the use of a static variable that retains its value across function calls and increments it.
Parameters: None.
Return Value: None (void).
Variables:
- count: A static integer variable.
*/
void variableStatic()
{
    static int count = 0;
    count++;
    printf("Valor del contador: %d\n", count);
}
