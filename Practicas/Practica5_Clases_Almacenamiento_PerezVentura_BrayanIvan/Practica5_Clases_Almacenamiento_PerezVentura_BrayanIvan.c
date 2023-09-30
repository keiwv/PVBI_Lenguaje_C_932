/*
Brayan Ivan Perez Ventura - 372781

Created code: September 26th 2023 / Modified code: September 26th 2023

DESCRIPTION
In this program, we will display a menu where the options are:
    1.- Lotery game: In this function, we will simulate a lotery game using static and automatics variables.
        First, we will create a random number between 1 and 100 (rand and srand)
        Second, using a static variable called "winningNumber" will saved the value of the random number (it will be initialized at the beginning of the game).
        We will compare the user input and the winningNumber and if they're same, it will display a text "Felicidades, ganaste la loteria", if not, "Lo siento, no gaste esta vez".

    2.- Car race: In this function, we will use register variables to simulate a race game.
        We will create a function called "startRace" where it simlates a car race.
        it will declarate 3 register variables to represent three different race cars.
        We will asign fake names to each car, as example "AMLO", "EPN" and "ElBicho"
        Using register variables, we will save the value of the speed of each car. We will generate random speeds between 100 and 200 km/h for each car.
        Simulate a race calculating the time that each car takes to travel the ficticial distance (as an example, 1000 meters) to their speed.

PVBI_Act _ _932
*/

//**** LIBRARIES ******
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// ***** STATIC VARIABLES ****
static int winningNumber = 0; // Lotery Game static variable

//**** PROTOTYPE FUNCTIONS *****
int msge_menu();
void menu();

int valid(char msge[], int ri, int rf);

void loteryGame();
int generateNumber();

void mainRaceGame();
int generateNumberCar();
int podium();
int askSpeedway();
float getSpeed(int player, int speedway);
int convertMtsKm(int player);

//**** MAIN FUNCTION ****

int main()
{
    menu();
    return 0;
}

//**** PROTOTYPE FUNCTIONS DEVELOPMENT **********

int msge_menu()
{
    int op;
    system("CLS");
    printf("M E N U \n");
    printf("1.- Juego de loteria\n");
    printf("2.- Carrera de Coches\n");
    printf("0.- SALIR\n");
    op = valid("Selecciona una opcion: ", 0, 2);
    return op;
}

void menu()
{
    srand(time(NULL)); // Seed to get a random number
    int op;
    do
    {
        op = msge_menu();
        switch (op)
        {
        case 1:
            loteryGame();
            break;
        case 2:
            mainRaceGame();
            break;
        }

    } while (op != 0);
    printf("Saliendo del programa\n");
}

int valid(char msge[], int ri, int rf)
{
    int op;
    char array[40];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        fgets(array, sizeof(array), stdin);
        op = atoi(array);
    } while (op < ri || op > rf);

    return op;
}

//*** LOTERY GAME FUNCTIONS ***
void loteryGame()
{
    int user;
    winningNumber = generateNumber(); // Generate a random number and save the value in static variable called "winningNumber"
    printf("JUEGO DE LOTERIA\n");
    user = generateNumber();
    if (user == winningNumber) // Compare user Input and winningNumber variable.
    {
        printf("Felicidades, has ganado la loteria\n");
    }
    else
    {
        printf("Lo siento, has perdido la loteria\n");
    }
    system("PAUSE");
}
int generateNumber()
{
    return (rand() % 100) + 1;
}

void mainRaceGame()
{
    register int amlo;    // Car 1
    register int enp;     // Car 2
    register int felipeC; // Car 3

    int speedwayLength, winner;
    float speedAmloKph, speedEnpKph, speedFelipeCKph;

    speedwayLength = askSpeedway();

    amlo = generateNumberCar();
    enp = generateNumberCar();
    felipeC = generateNumberCar();

    winner = podium(amlo, felipeC, enp);

    float timeAmlo = (float)speedwayLength / speedAmloKph;
    float timeEnp = (float)speedwayLength / speedEnpKph;
    float timeFelipeC = (float)speedwayLength / speedFelipeCKph;

    printf("amlo tiene una velocidad de %dkm/h y el tiempo que tomó fue: %.2f segundos\n", amlo, timeAmlo);
    printf("enp tiene una velocidad de %dkm/h y el tiempo que tomó fue: %.2f segundos\n", enp, timeEnp);
    printf("felipeC tiene una velocidad de %dkm/h y el tiempo que tomó fue: %.2f segundos\n", felipeC, timeFelipeC);

    printf("El tamaño de la pista es de: %d\n", speedwayLength);

    if (winner == 1)
    {
        printf("El ganador es: amlo\n");
    }
    else if (winner == 2)
    {
        printf("El ganador es: enp\n");
    }
    else if (winner == 3)
    {
        printf("El ganador es: felipeC\n");
    }
    else if (winner == 4)
    {
        printf("Los 3 carros quedaron empatados\n");
    }
    else if (winner == 5)
    {
        printf("amlo y enp quedaron empatados\n");
    }
    else if (winner == 6)
    {
        printf("amlo y felipeC quedaron empatados\n");
    }
    else if (winner == 7)
    {
        printf("enp y felipeC quedaron empatados\n");
    }
    system("PAUSE");
}

int generateNumberCar()
{
    int num;
    num = (rand() % 100) + 100;
    return num;
}

int podium(int amlo, int felipeC, int enp)
{
    if (enp > amlo)
    {
        if (felipeC > amlo)
        {
            return 1;
        }
    }
    if (amlo > enp)
    {
        if (felipeC > enp)
        {
            return 2;
        }
    }
    if (amlo > felipeC)
    {
        if (enp > felipeC)
        {
            return 3;
        }
    }

    if (amlo == enp)
    {
        if (amlo == felipeC)
        {
            return 4;
        }
        return 5;
    }

    if (amlo == felipeC)
    {
        return 6;
    }

    if (enp == felipeC)
    {
        return 7;
    }
}

int askSpeedway()
{
    return valid("Ingresa el tamaño de la pista en metros: ", 0, INT_MAX);
}

float getSpeed(int player, int speedway)
{
    return speedway / player;
}

int convertMtsKm(int player)
{
    return player * 1000;
}