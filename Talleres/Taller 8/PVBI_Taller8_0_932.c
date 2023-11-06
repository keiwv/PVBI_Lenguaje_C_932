/*
*/

//**** LIBRARIES ******

//**** PROTOTYPE FUNCTIONS *****
void menu();
int msge_menu();

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
    op = msge_menu();
    switch(op)
    {
        
    }
}

int msge_menu()
{
    printf("1.- Codigos replicados de la presentacion\n");
    printf("2.- Funcion de busqueda lineal\n");
    printf("3.- Comparacion de metodos\n");
    printf("4.- Medicion del tiempo de ejecucion\n");
    printf("0.- Salir");
    return valid("Selecciona tu opcion: ",0,4);
}