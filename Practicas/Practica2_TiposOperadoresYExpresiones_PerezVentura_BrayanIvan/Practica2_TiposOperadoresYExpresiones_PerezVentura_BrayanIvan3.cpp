

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVENTORY_SIZE 10
#define MAX_NAME_LENGTH 50

int num_elements[MAX_INVENTORY_SIZE];
char name_elements[MAX_INVENTORY_SIZE][MAX_NAME_LENGTH];

int current_element = 0;

int menu();
void addItems();
void removeItem();
void displayInventory();

int main()
{
    int leave, op;
    system("CLS");

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            system("CLS");
            addItems();
            break;
        case 2:
            removeItem(); // Call the new function for removing items
            break;
        case 3:
            displayInventory();
            break;
        case 4:
            printf("Saliendo del programa\n");
            break;
        default:
            printf("Opcion incorrecta, selecciona otro numero\n");
            break;
        }
    } while (op != 4);

    return 0;
}

int menu()
{
    int op;
    char input_op[10];
MENU:
    printf("\nInventario de una tienda\n");
    printf("M E N U\n");
    printf("1.- Agregar elementos del inventario\n");
    printf("2.- Retirar elementos\n");
    printf("3.- Mostrar el inventario\n");
    printf("4.- Salir\n");
    printf("Selecciona tu opcion: ");
    scanf("%9s", input_op);
    printf("\n");

    if ((sscanf(input_op, "%d", &op)) == 1)
    {
        if (op >= 1 && op <= 4)
        {
            return op;
        }
    }

    system("CLS");
    printf("Opcion incorrecta, selecciona otro numero\n");
    goto MENU;
}

void addItems()
{
    char leave;
    do
    {
        if (current_element < MAX_INVENTORY_SIZE)
        {
            printf("Introduce el nombre del producto: ");
            scanf("%49s", name_elements[current_element]);
            printf("Introduce la cantidad del producto: ");
            scanf("%d", &num_elements[current_element]);
            current_element++;
            printf("Producto agregado correctamente, desea salir (y/n): ");
            scanf(" %c", &leave);
            while (leave != 'y' && leave != 'n')
            {
                printf("Opcion incorrecta, introduce una opcion correcta (y/n): ");
                scanf(" %c", &leave);
            }
        }
        else
        {
            printf("El inventario esta lleno, por favor elimina uno.\n");
            printf("Desea salir (y/n): ");
            scanf(" %c", &leave);
            while (leave != 'y' && leave != 'n')
            {
                printf("Opcion incorrecta, introduce una opcion correcta (y/n): ");
                scanf(" %c", &leave);
            }
        }
    } while (leave != 'y');
}

void removeItem()
{
    int itemIndex;
    displayInventory();
    if (current_element == 0)
    {
        printf("El inventario esta vacio. No hay elementos para retirar.\n");
        return;
    }
    printf("Introduce el numero del elemento que deseas retirar: ");
    scanf("%d", &itemIndex);
    if (itemIndex >= 1 && itemIndex <= current_element)
    {
        itemIndex--; // Adjust for 0-based indexing
        for (int i = itemIndex; i < current_element - 1; i++)
        {
            // Shift elements to fill the gap
            strcpy(name_elements[i], name_elements[i + 1]);
            num_elements[i] = num_elements[i + 1];
        }
        current_element--;
        printf("Elemento retirado correctamente.\n");
    }
    else
    {
        printf("Numero de elemento incorrecto. No se retiró ningun elemento.\n");
    }
}

void displayInventory()
{
    printf("Inventario actual:\n");
    if (current_element == 0)
    {
        printf("El inventario esta vacio.\n");
    }
    else
    {
        for (int i = 0; i < current_element; i++)
        {
            printf("%d. Nombre: %s, Cantidad: %d\n", i + 1, name_elements[i], num_elements[i]);
        }
    }
}
