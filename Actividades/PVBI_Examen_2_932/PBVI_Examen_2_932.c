

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Vet
{
    char Animal[50];
    char name[50];
    char enfermedad[50];
    int edad;
    int matricula;
} Vet;
#define MAX_REGISTERS 1000

Vet RegAnimal(int flag, int mat);
void hist(Vet Animal[], int position);
void consulta(Vet animal[], int position);
int alma_read(Vet animales[], int position);

void mostrar(Vet Animal);
int bus_sec(Vet Animals[], int longi, int num);
int numRandom(int ri, int rf);
void save(Vet Animals[], int position);
int load(Vet Animals[], int position);

int main()
{
    srand(time(NULL));
    int op;
    int position = 0;
    Vet Animals[MAX_REGISTERS];
    position = load(Animals, position);

    do
    {
        system("CLS");
        printf("1.- Registrar a una mascota\n");
        printf("2.- Historial medico\n");
        printf("3.- Consulta de registros\n");
        printf("4.- Almacenar datos\n");
        printf("0.- Salir\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Animals[position] = RegAnimal(1, 239291);
            position++;
            break;
        case 2:
            hist(Animals, position);
            break;
        case 3:
            consulta(Animals, position);
            break;
        case 4:
            position = alma_read(Animals, position);
            break;
        }
        system("PAUSE");
    } while (op != 0);
}

Vet RegAnimal(int flag, int mat)
{
    Vet tempReg;
    if (flag)
    {
        tempReg.matricula = numRandom(30000, 39999);
    }
    else
    {
        tempReg.matricula = mat;
    }

    printf("que animal (tipo) desea registrar: ");
    scanf(" %s", tempReg.Animal);

    printf("nombre del animal: ");
    scanf(" %s", tempReg.name);

    printf("Edad: ");
    scanf("%d", &tempReg.edad);

    printf("enfermedad: ");
    scanf(" %s", tempReg.enfermedad);

    mostrar(tempReg);
    return tempReg;
}

void hist(Vet Animal[], int position)
{
    int num;
    int i;
    do
    {
        printf("Introduce matricula del animal: ");
        scanf("%d", &num);
    } while (bus_sec(Animal, position, num) == -1);
    num = bus_sec(Animal, position, num);
    mostrar(Animal[num]);
    i = num;
    printf("Desea actualizarlo (1.- Si, 0.- No): ");
    scanf("%d", &num);
    if (num)
    {
        Animal[num] = RegAnimal(0, Animal[num].matricula);
    }
}

void consulta(Vet animal[], int position)
{
    int num;
    do
    {
        printf("Introduce la matricula del animal a buscar: ");
        scanf("%d", &num);
    } while (bus_sec(animal, position, num) == -1);
    num = bus_sec(animal, position, num);
    mostrar(animal[num]);
}

int alma_read(Vet animales[], int position)
{
    int num;
    printf("Desea guardar (1) o cargar (0): ");
    scanf("%d", &num);
    if (num)
    {
        save(animales, position);
    }
    else
    {
        position = load(animales, position);
    }
    return position;
}

void save(Vet Animals[], int position)
{
    FILE *fa;
    int i = 0;

    fa = fopen("archivo.txt", "w");

    for (i = 0; i < position; i++)
    {
        fprintf(fa, "%-10d %-10s %-10s %-10s %-10d\n", Animals[i].matricula, Animals[i].Animal, Animals[i].name, Animals[i].enfermedad, Animals[i].edad);
    }
    fclose(fa);
}

int load(Vet Animals[], int position)
{
    FILE *fa;
    int i;
    fa = fopen("archivo.txt", "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%d %s %s %s %d", &Animals[position].matricula, Animals[position].Animal, Animals[position].name, Animals[position].enfermedad, &Animals[position].edad);
            position++;
        } while (!feof(fa));
        fclose(fa);
    }
    else
    {
        printf("El archivo no existe\n");
    }
    return position;
}

void mostrar(Vet Animal)
{
    printf("Nombre: %s\n", Animal.name);
    printf("Tipo: %s\n", Animal.Animal);
    printf("Edad: %d\n", Animal.edad);
    printf("Enfermedad: %s\n", Animal.enfermedad);
    printf("Matricula: %d\n", Animal.matricula);
}

int numRandom(int ri, int rf)
{
    int range = (rf - ri + 1);
    return rand() % range + ri;
}

int bus_sec(Vet Animals[], int longi, int num)
{
    int i;
    for (i = 0; i < longi; i++)
    {
        if (Animals[i].matricula == num)
        {
            return i;
        }
    }
    return -1;
}