<<<<<<< HEAD
/*
Brayan Ivan Perez Ventura - 372781

Código creado: 07 de septiembre del 2023 / Código modificado: 08 de septiembre del 2023

Lista de programas de la práctica número 2, donde se despliega un menú.
Para trabajo 1 se hace la conversión de numeros decimales a binarios y muestra las luces encendidas.
Para el trabajo 2, este funciona con operadores temarios y se trata de rangos de calificaciones de cambiar de números a una letra (según el rango de calificación)
Para el trabajo 3, es simular un sistema básico de gestión de inventario en C, donde los usuarios pueden agregar, quitar y retirar elementos del inventario

He de agregar que este último se realizó en inglés para la práctica del documentado en inglés (las otras dos se hicieron en español), por eso hay líneas en español e inglés.

PVBI_Act2_1_932
*/

//Declaración de librerías a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVENTORY_SIZE 10 //This constant stores the value of the inventory size (work 3)
#define MAX_NAME_LENGTH 50 //This constant stores the value of the name lenght (work 3)

int num_elements[MAX_INVENTORY_SIZE]; //This global array stores the value of the quantity of product items (work 3)
char name_elements[MAX_INVENTORY_SIZE][MAX_NAME_LENGTH]; //This global matrix stores the name of the products (work 3)

int current_element = 0; //This one is counter. It saves the number of the product. (work 3)

//******** FUNCIONES ********
void trabajo1();
void trabajo2();
void trabajo3();
//********* FUNCTIONS WORK 3********
int menu();
void addItems();
void removeItem();
void displayInventory();

//******** FUNCION PRINCIPAL ************
int main()
{
    //MENU
    system("CLS");
    int op; //Variable para selecciona una opción
    printf("Selecciona el trabajo\n");
    printf("1.- Trabajo 1\n");
    printf("2.- Trabajo 2\n");
    printf("3.- Trabajo 3\n");
    printf("4.- Salir\n");
    printf("Selecciona tu opcion: ");
    scanf("%d", &op);

    //Selección de la opción
    switch (op)
    {
        case 1:
            trabajo1();
            break;
        case 2:
            trabajo2();
            break;
        case 3:
            trabajo3();
            break;
        case 4:
            printf("Cerrando programa");
            exit(0); //Salir del programa
        default:
            printf("Opcion incorrecta.");
    }
    return 0;
}
//********* FUNCIÓN DEL TRABAJO 1 **************
void trabajo1()
{
    int num_entero; //Variable para guardar el número entero que el usuario introducirá
    printf("Programa para convertir numeros enteros a binario\n");
    printf("Ingrese un numero entero: ");
    scanf("%d", &num_entero);

    //En caso de no tener un número entero, este nos regresará a la función principal
    if (num_entero < 0)
    {
        printf("El numero es negativo, intentalo de nuevo");
        main();
    }

    // Calculo de bits necesarios
    int num_bits = 0; //Inicializar el numero de bits en 0
    int temp = num_entero; //Guardar el valor del numero entero en una variable temporal

    while (temp > 0)
    {
        temp /= 2;
        num_bits++;
    }

    // Creación del arreglo
    int bits[num_bits];
    int indice;

    while (num_entero > 0)
    {
        bits[indice] = num_entero % 2;
        num_entero /= 2;
        indice++;
    }
    // Imprimir la cadena de bits
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }
    printf("\n");

    // Cantidad de bits encendidos
    int bit_encendido = -1;
    printf("Los bits encendidos estan en la posición: ");

    for (int i = 0; i < indice; i++)
    {
        if (bits[i] == 1)
        {
            bit_encendido = i;
            printf(" %d", bit_encendido + 1);
        }
    }
    if (bit_encendido == -1)
    {
        printf("No se ha encontrado ningún bit encendido"); //En caso de que no se haya encontrado ningún bit
    }
    main();
}
//********** FUNCION PRINCIPAL DE LA TRABAJO 2************
void trabajo2()
{

    int calificacion; //Variable que guardará el valor de la calificación que el usuario introducirá.

    printf("Ingresa una calificación numérica: ");
    scanf("%d", &calificacion);

    ///Si la calificación es mayor a 100, entonces marcará error y te mandará a la función principal
    if (calificacion > 100){
        printf("Calificacion ingresada incorrecta, por favor ingresa una correcta\n");
    }
    else
    {
        //Utilizando operadores ternarios, se comienza a comparar el valor de calificación según la cantidad ingresada
        char letra = (calificacion >= 90) ? 'A' :
                     (calificacion >= 80) ? 'B' :
                     (calificacion >= 70) ? 'C' :
                     (calificacion >= 60) ? 'D' : 'F';

        printf("La calificacion en letra es: %c\n", letra);
    }
    main();
}
// *********** MAIN FUNCTION WORK 3 ************
void trabajo3()
{
    int op; //This variable stores the value of the option that the user is gonna choose in the menu function
    system("CLS"); //This clear the screen

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            system("CLS");
            addItems(); //Call the new function for adding items
            break;
        case 2:
            removeItem(); // Call the new function for removing items
            break;
        case 3:
            displayInventory(); //Callling the new function for displaying inventory
            break;
        case 4:
            printf("Saliendo del programa\n"); //leaves from the program
            break;
        default:
            printf("Opcion incorrecta, selecciona otro numero\n"); //In case the user picks a wrong number.
            break;
        }
    } while (op != 4); //This is gonna loop until the user wants to leave, so variables does not lose information.
    main(); //Return to the main function
}

//********** MENU FUNCTION **************
int menu()
{
    int op; //This variable is gonna save the value of the option the user is gonna choose 
    char input_op[10]; //This is a temporal variable, it saves the value of the option input (it will be save and then the program will scan if there's a letter or something different from a number)

//MENU
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

    if ((sscanf(input_op, "%d", &op)) == 1) //This scans the temporal variable (input_op) and it looks for a number, if there's not a number, it will be 0
    {
        if (op >= 1 && op <= 4) //This makes sure there's a number, if it goes outside from the numbers of the menu, it will display the menu again
        {
            return op;
        }
    }

    system("CLS");
    printf("Opcion incorrecta, selecciona otro numero\n");
    goto MENU;
}

// ********* ADDING ITEMS FUNCTION ***********
void addItems()
{
    char leave; //This variable is gonna save the value of y or n, when the user wants to leave.
    do
    {
        if (current_element <= MAX_INVENTORY_SIZE) //If the inventory is higher or equal than the max inventory size (constant), it will tell you the inventory is full
        {
            printf("Introduce el nombre del producto: ");
            scanf("%49s", name_elements[current_element]); //Here, it is going to save the name of the product (in array, which the number will be current element)
            printf("Introduce la cantidad del producto: ");
            scanf("%d", &num_elements[current_element]); //Here, it is going to save the quantify of the product (in array, which the number will be the current element)
            current_element++; //Increase 1 so if the user wants to save another product, it's gonna get save in the same array as the last saved product
            printf("Producto agregado correctamente, desea salir (y/n): ");
            scanf(" %c", &leave); //Saves the value of y or n if he wants to leave or not
            while (leave != 'y' && leave != 'n') //if leave is different y or n, it will be looping until the user introduce a correct value
            {
                printf("Opcion incorrecta, introduce una opcion correcta (y/n): ");
                scanf(" %c", &leave);
            }
        }
        else //In case the inventory is full it will display this: 
        {
            printf("El inventario esta lleno, por favor elimina uno.\n");
            printf("Desea salir (y/n): ");
            scanf(" %c", &leave); //Saves the value of the y or n
            while (leave != 'y' && leave != 'n') //In case the user introduce a invalid term, it will be looping until the user introduces a correct term.
            {
                printf("Opcion incorrecta, introduce una opcion correcta (y/n): ");
                scanf(" %c", &leave);
            }
        }
    } while (leave != 'y'); //It will get out until the user introduces "y"
}

//******* REMOVE ITEMS FUNCTION *********
void removeItem()
{
    int itemIndex; //This variable is gonna save the value of the product you will want to remove
    displayInventory(); //This will display the inventory (so the user can pick the number of the product he wants to remove)
    if (current_element == 0) //If there's not items in the inventory, it will display a message saying it and it will take us back to the menu function
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
            strcpy(name_elements[i], name_elements[i + 1]); //Move the name of the next element in the current element
            num_elements[i] = num_elements[i + 1]; //Move the number of the next element in the current element
        }
        current_element--; //Decrement the count of elements in the inventory
        printf("Elemento retirado correctamente.\n");
    }
    else
    {
        printf("Numero de elemento incorrecto. No se retiró ningun elemento.\n"); //Display an error for an incorrect item number
    }
}

void displayInventory()
{
    printf("Inventario actual:\n"); // Print a header indicating the display of the current inventory
    if (current_element == 0)
    {
        printf("El inventario esta vacio.\n"); // If there are no items in the inventory, display a message indicating it's empty
    }
    else
    {
        for (int i = 0; i < current_element; i++)
        {
            printf("%d. Nombre: %s, Cantidad: %d\n", i + 1, name_elements[i], num_elements[i]);
            // Display the item number (starting from 1), name, and quantity for each item in the inventory
        }
    }
}
=======
/*
Brayan Ivan Perez Ventura - 372781

Código creado: 07 de septiembre del 2023 / Código modificado: 08 de septiembre del 2023

Lista de programas de la práctica número 2, donde se despliega un menú.
Para trabajo 1 se hace la conversión de numeros decimales a binarios y muestra las luces encendidas.
Para el trabajo 2, este funciona con operadores temarios y se trata de rangos de calificaciones de cambiar de números a una letra (según el rango de calificación)
Para el trabajo 3, es simular un sistema básico de gestión de inventario en C, donde los usuarios pueden agregar, quitar y retirar elementos del inventario

He de agregar que este último se realizó en inglés para la práctica del documentado en inglés (las otras dos se hicieron en español), por eso hay líneas en español e inglés.

PVBI_Act2_1_932
*/

//Declaración de librerías a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVENTORY_SIZE 10 //This constant stores the value of the inventory size (work 3)
#define MAX_NAME_LENGTH 50 //This constant stores the value of the name lenght (work 3)

int num_elements[MAX_INVENTORY_SIZE]; //This global array stores the value of the quantity of product items (work 3)
char name_elements[MAX_INVENTORY_SIZE][MAX_NAME_LENGTH]; //This global matrix stores the name of the products (work 3)

int current_element = 0; //This one is counter. It saves the number of the product. (work 3)

//******** FUNCIONES ********
void trabajo1();
void trabajo2();
void trabajo3();
//********* FUNCTIONS WORK 3********
int menu();
void addItems();
void removeItem();
void displayInventory();

//******** FUNCION PRINCIPAL ************
int main()
{
    //MENU
    system("CLS");
    int op; //Variable para selecciona una opción
    printf("Selecciona el trabajo\n");
    printf("1.- Trabajo 1\n");
    printf("2.- Trabajo 2\n");
    printf("3.- Trabajo 3\n");
    printf("4.- Salir\n");
    printf("Selecciona tu opcion: ");
    scanf("%d", &op);

    //Selección de la opción
    switch (op)
    {
        case 1:
            trabajo1();
            break;
        case 2:
            trabajo2();
            break;
        case 3:
            trabajo3();
            break;
        case 4:
            printf("Cerrando programa");
            exit(0); //Salir del programa
        default:
            printf("Opcion incorrecta.");
    }
    return 0;
}
//********* FUNCIÓN DEL TRABAJO 1 **************
void trabajo1()
{
    int num_entero; //Variable para guardar el número entero que el usuario introducirá
    printf("Programa para convertir numeros enteros a binario\n");
    printf("Ingrese un numero entero: ");
    scanf("%d", &num_entero);

    //En caso de no tener un número entero, este nos regresará a la función principal
    if (num_entero < 0)
    {
        printf("El numero es negativo, intentalo de nuevo");
        main();
    }

    // Calculo de bits necesarios
    int num_bits = 0; //Inicializar el numero de bits en 0
    int temp = num_entero; //Guardar el valor del numero entero en una variable temporal

    while (temp > 0)
    {
        temp /= 2;
        num_bits++;
    }

    // Creación del arreglo
    int bits[num_bits];
    int indice;

    while (num_entero > 0)
    {
        bits[indice] = num_entero % 2;
        num_entero /= 2;
        indice++;
    }
    // Imprimir la cadena de bits
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }
    printf("\n");

    // Cantidad de bits encendidos
    int bit_encendido = -1;
    printf("Los bits encendidos estan en la posición: ");

    for (int i = 0; i < indice; i++)
    {
        if (bits[i] == 1)
        {
            bit_encendido = i;
            printf(" %d", bit_encendido + 1);
        }
    }
    if (bit_encendido == -1)
    {
        printf("No se ha encontrado ningún bit encendido"); //En caso de que no se haya encontrado ningún bit
    }
    main();
}
//********** FUNCION PRINCIPAL DE LA TRABAJO 2************
void trabajo2()
{

    int calificacion; //Variable que guardará el valor de la calificación que el usuario introducirá.

    printf("Ingresa una calificación numérica: ");
    scanf("%d", &calificacion);

    ///Si la calificación es mayor a 100, entonces marcará error y te mandará a la función principal
    if (calificacion > 100){
        printf("Calificacion ingresada incorrecta, por favor ingresa una correcta\n");
    }
    else
    {
        //Utilizando operadores ternarios, se comienza a comparar el valor de calificación según la cantidad ingresada
        char letra = (calificacion >= 90) ? 'A' :
                     (calificacion >= 80) ? 'B' :
                     (calificacion >= 70) ? 'C' :
                     (calificacion >= 60) ? 'D' : 'F';

        printf("La calificacion en letra es: %c\n", letra);
    }
    main();
}
// *********** MAIN FUNCTION WORK 3 ************
void trabajo3()
{
    int op; //This variable stores the value of the option that the user is gonna choose in the menu function
    system("CLS"); //This clear the screen

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            system("CLS");
            addItems(); //Call the new function for adding items
            break;
        case 2:
            removeItem(); // Call the new function for removing items
            break;
        case 3:
            displayInventory(); //Callling the new function for displaying inventory
            break;
        case 4:
            printf("Saliendo del programa\n"); //leaves from the program
            break;
        default:
            printf("Opcion incorrecta, selecciona otro numero\n"); //In case the user picks a wrong number.
            break;
        }
    } while (op != 4); //This is gonna loop until the user wants to leave, so variables does not lose information.
    main(); //Return to the main function
}

//********** MENU FUNCTION **************
int menu()
{
    int op; //This variable is gonna save the value of the option the user is gonna choose 
    char input_op[10]; //This is a temporal variable, it saves the value of the option input (it will be save and then the program will scan if there's a letter or something different from a number)

//MENU
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

    if ((sscanf(input_op, "%d", &op)) == 1) //This scans the temporal variable (input_op) and it looks for a number, if there's not a number, it will be 0
    {
        if (op >= 1 && op <= 4) //This makes sure there's a number, if it goes outside from the numbers of the menu, it will display the menu again
        {
            return op;
        }
    }

    system("CLS");
    printf("Opcion incorrecta, selecciona otro numero\n");
    goto MENU;
}

// ********* ADDING ITEMS FUNCTION ***********
void addItems()
{
    char leave; //This variable is gonna save the value of y or n, when the user wants to leave.
    do
    {
        if (current_element <= MAX_INVENTORY_SIZE) //If the inventory is higher or equal than the max inventory size (constant), it will tell you the inventory is full
        {
            printf("Introduce el nombre del producto: ");
            scanf("%49s", name_elements[current_element]); //Here, it is going to save the name of the product (in array, which the number will be current element)
            printf("Introduce la cantidad del producto: ");
            scanf("%d", &num_elements[current_element]); //Here, it is going to save the quantify of the product (in array, which the number will be the current element)
            current_element++; //Increase 1 so if the user wants to save another product, it's gonna get save in the same array as the last saved product
            printf("Producto agregado correctamente, desea salir (y/n): ");
            scanf(" %c", &leave); //Saves the value of y or n if he wants to leave or not
            while (leave != 'y' && leave != 'n') //if leave is different y or n, it will be looping until the user introduce a correct value
            {
                printf("Opcion incorrecta, introduce una opcion correcta (y/n): ");
                scanf(" %c", &leave);
            }
        }
        else //In case the inventory is full it will display this: 
        {
            printf("El inventario esta lleno, por favor elimina uno.\n");
            printf("Desea salir (y/n): ");
            scanf(" %c", &leave); //Saves the value of the y or n
            while (leave != 'y' && leave != 'n') //In case the user introduce a invalid term, it will be looping until the user introduces a correct term.
            {
                printf("Opcion incorrecta, introduce una opcion correcta (y/n): ");
                scanf(" %c", &leave);
            }
        }
    } while (leave != 'y'); //It will get out until the user introduces "y"
}

//******* REMOVE ITEMS FUNCTION *********
void removeItem()
{
    int itemIndex; //This variable is gonna save the value of the product you will want to remove
    displayInventory(); //This will display the inventory (so the user can pick the number of the product he wants to remove)
    if (current_element == 0) //If there's not items in the inventory, it will display a message saying it and it will take us back to the menu function
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
            strcpy(name_elements[i], name_elements[i + 1]); //Move the name of the next element in the current element
            num_elements[i] = num_elements[i + 1]; //Move the number of the next element in the current element
        }
        current_element--; //Decrement the count of elements in the inventory
        printf("Elemento retirado correctamente.\n");
    }
    else
    {
        printf("Numero de elemento incorrecto. No se retiró ningun elemento.\n"); //Display an error for an incorrect item number
    }
}

void displayInventory()
{
    printf("Inventario actual:\n"); // Print a header indicating the display of the current inventory
    if (current_element == 0)
    {
        printf("El inventario esta vacio.\n"); // If there are no items in the inventory, display a message indicating it's empty
    }
    else
    {
        for (int i = 0; i < current_element; i++)
        {
            printf("%d. Nombre: %s, Cantidad: %d\n", i + 1, name_elements[i], num_elements[i]);
            // Display the item number (starting from 1), name, and quantity for each item in the inventory
        }
    }
}
>>>>>>> 819ee1ffce0b3b5ee10ff6b99b91ca782b7be80c
