/*
    Code Created: November 22th 2023 // Code modified: November 22th 2023
    Description:
    This C code implements a basic inventory management system. It defines functions
    to perform operations such as adding, removing, displaying, and calculating the total value of
    inventory items. The inventory items are represented by a structure Tinv, which includes details
    such as product name, price, quantity, status, and a unique product code.

    Practica 8
*/

#include "Frijoles.h"
#include <time.h>

#define MAX_REGISTERS 500
// *** STRUCTURES **
typedef struct _Inv
{
    int status;
    char productName[30];
    int amount;
    float price;
    int code;
} Tinv;

//*** PROTOTYPE FUNCTIONS *******
void menu();
int msge_menu();

Tinv addElement();
void dltElement(Tinv products[], int position);
void ShowInventory(Tinv products[], int position);
void calculateValueInventory(Tinv products[], int position);

void ShowElement(Tinv product);
int existElem(Tinv products[], int longi, int num);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu()
{
    int op;
    Tinv Inventory[MAX_REGISTERS];
    int position = 0;
    do
    {
        system("CLS");
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            if (position < MAX_REGISTERS)
            {
                Inventory[position] = addElement();
                position++;
            }
            else
            {
                printf("Registros maximos alcanzados\n");
            }

            break;
        case 2:
            dltElement(Inventory, position);
            break;
        case 3:
            ShowInventory(Inventory, position);
            break;
        case 4:
            calculateValueInventory(Inventory, position);
            break;
        }
        system("PAUSE");
    } while (op != 0);
}
/*
Function: msge_menu
Description: Displays a menu with options to add, remove, display, and calculate the total value of inventory.
Parameters: None.
Return Value: An integer representing the user's menu selection.
Variables: None.
*/
int msge_menu()
{
    printf("1.- Agregar elementos al inventario\n");
    printf("2.- Retirar elementos del inventario\n");
    printf("3.- Mostrar el inventario\n");
    printf("4.- Calcular el valor total del inventario\n");
    printf("0.- Salir del programa\n");
    return valid("Selecciona una opcion: ", 0, 4);
}

/*
Function: addElement
Description: Adds a new element to the inventory, prompting the user for product details.
Parameters: None.
Return Value: A structure of type Tinv representing the added inventory element.
Variables: tempElement - A temporary structure to store user-inputted product details.
*/

Tinv addElement()
{
    Tinv tempElement;
    do
    {
        ask("Introduce el nombre del producto: ", tempElement.productName);
    } while (alfaSpace(tempElement.productName) == -1);

    tempElement.price = valid("\nCual es el precio del producto: ", 1, 10000);

    tempElement.amount = valid("\nCual es la cantidad de producto: ", 0, 100000);

    tempElement.status = 1;

    tempElement.code = numRandom(10000, 19999);

    ShowElement(tempElement);
    return tempElement;
}
/*
Function: dltElement
Description: Deletes an element from the inventory based on the user-provided product code.
Parameters:
- products: An array of inventory elements.
- position: An integer representing the current position in the inventory array.
Return Value: None (void).
Variables: tempnum - An integer to store the user-provided product code for deletion.
*/
void dltElement(Tinv products[], int position)
{
    int tempnum;

    tempnum = valid("Introduce el codigo del producto que deseas remover: ", 10000, 19999);

    if (existElem(products, position, tempnum) != -1)
    {
        ShowElement(products[tempnum]);
        if (valid("Desea eliminarlo (1. No, 1.- Si)", 0, 1))
        {
            products[tempnum].status = 0;
            printf("El producto se ha eliminado con exito\n");
        }
    }
    else
    {
        printf("El codigo introducido no existe\n");
    }
}
/*
Function: ShowInventory
Description: Displays the current inventory, showing only active elements.
Parameters:
- products: An array of inventory elements.
- position: An integer representing the current position in the inventory array.
Return Value: None (void).
Variables: None.
*/
void ShowInventory(Tinv products[], int position)
{
    int i;
    for (i = 0; i < position; i++)
    {
        if (products[i].status == 1)
        {
            ShowElement(products[i]);
        }
    }
}
/*
Function: calculateValueInventory
Description: Calculates the total value of the inventory based on active elements.
Parameters:
- products: An array of inventory elements.
- position: An integer representing the current position in the inventory array.
Return Value: None (void).
Variables: result - An integer to store the total value of the inventory.
*/
void calculateValueInventory(Tinv products[], int position)
{
    int i;
    int result = 0;
    for (i = 0; i < position; i++)
    {
        if (products[i].status == 1)
        {
            result += products[i].price * products[i].amount;
        }
    }
    printf("El inventario tiene un valor aproximado de: %d pesos argentinos.\n", result);
}
/*
Function: ShowElement
Description: Displays details of a single inventory element.
Parameters:
- product: A structure of type Tinv representing an inventory element.
Return Value: None (void).
Variables: None.
*/
void ShowElement(Tinv product)
{
    printf("Nombre:   %s\n", product.productName);
    printf("Cantidad: %d\n", product.amount);
    printf("Precio:   %.f\n", product.price);
    printf("Codigo:   %d\n", product.code);
    printf("----------------------------------\n");
}
/*
Function: existElem
Description: Checks if a given product code exists in the inventory.
Parameters:
- products: An array of inventory elements.
- longi: An integer representing the current position in the inventory array.
- num: An integer representing the product code to be checked.
Return Value: An integer representing the index of the element if found, -1 otherwise.
Variables: i - An integer for looping through the inventory array.
*/
int existElem(Tinv products[], int longi, int num)
{
    int i;

    for (i = 0; i < longi; i++)
    {
        if (products[i].code == num)
        {
            return i;
        }
    }
    return -1;
}