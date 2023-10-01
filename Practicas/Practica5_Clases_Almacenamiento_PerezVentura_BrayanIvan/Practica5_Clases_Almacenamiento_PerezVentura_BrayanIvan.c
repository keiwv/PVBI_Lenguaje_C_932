/*
Brayan Ivan Perez Ventura - 372781

Created code: September 26th 2023 / Modified code: September 30th 2023

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
int podium(float timeAmlo, float timeFelipeC, float timeEnp);
float askSpeedway();
float getSpeed(float speedway, float playerSpeed);

//**** MAIN FUNCTION ****

int main()
{
    menu();
    return 0;
}

//**** PROTOTYPE FUNCTIONS DEVELOPMENT **********
/*
Function: msge_menu
Description: Displays a menu to the user and ask them to select an option. It also validates the user's input.
Parameters: None.
Return Value: The value of the user's input.
Variables:
- op: An integer to store the user's choice.
*/
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

/*
Function: menu
Description: Main menu function that allows the user to navigate between Race Game, Lotery Game and exit the program.
Parameters: None.
Return Value: None (void).
Variables:
- op: An integer to store the user's choice.
*/
void menu()
{
    srand(time(NULL)); // Seed to get a random number
    int op;
    do
    {
        op = msge_menu();
        system("CLS");
        switch (op)
        {
        case 1:
            printf("L O T E R I A\n");
            loteryGame();
            break;
        case 2:
            printf("SIMULACION DE UNA CARRERA DE COCHES\n");
            mainRaceGame();
            break;
        }

    } while (op != 0);
    printf("Saliendo del programa\n");
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
- op: An integer to store the user's input.
- array: A character array to temporarily store user input.
*/
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

/*
Function: loteryGame
Description: Implements a lottery game where the computer generates two random numbers and it compares, if they're same, the user will win. if not, the user will lose.
Parameters: None.
Return Value: None (void).
Variables:
- user: An integer to store the user's random number generated by the game.
*/
void loteryGame()
{
    int user;
    winningNumber = generateNumber(); // Generate a random number and save the value in static variable called "winningNumber"
    printf("JUEGO DE LOTERIA\n");
    user = generateNumber();
    if (user == winningNumber) // Compare user Input and winningNumber variable.
    {
        printf("Felicidades, has ganado la loteria, tu numero es: %d y el numero ganador es: %d\n", user, winningNumber);
    }
    else
    {
        printf("Lo siento, has perdido la loteria, tu numero es: %d y el numero ganador es: %d\n", user, winningNumber);
    }
    printf("Presiona una tecla para continuar...");
    getchar();
}

/*
Function: generateNumber
Description: Generates a random number between 1 and 100.
Parameters: None.
Return Value: A random integer.
*/

int generateNumber()
{
    return (rand() % 100) + 1;
}

//*** RACE GAME FUNCTIONS ***

/*
Function: mainRaceGame
Description: Simulates a car race game with three cars and determines the winner.
Parameters: None.
Return Value: None (void).
Variables:
- amlo, enp, felipeC: Integers representing the speeds of three cars.
- winner: An integer representing the winning car.
- speedwayLength: The length of the racetrack.
- timeAmlo, timeEnp, timeFelipeC: Floats representing the time taken by each car to complete the race.
*/
void mainRaceGame()
{
    register int amlo;    // Car 1
    register int enp;     // Car 2
    register int felipeC; // Car 3

    int winner;
    float speedwayLength, timeAmlo, timeEnp, timeFelipeC;

    speedwayLength = askSpeedway();

    amlo = generateNumberCar();
    enp = generateNumberCar();
    felipeC = generateNumberCar();

    timeAmlo = getSpeed(speedwayLength, amlo);
    timeEnp = getSpeed(speedwayLength, enp);
    timeFelipeC = getSpeed(speedwayLength, felipeC);

    winner = podium(timeAmlo, timeFelipeC, timeEnp);

    printf("\namlo tiene una velocidad de %dkm/h y el tiempo que tomo fue: %.2f segundos\n", amlo, timeAmlo);
    printf("enp tiene una velocidad de %dkm/h y el tiempo que tomo fue: %.2f segundos\n", enp, timeEnp);
    printf("felipeC tiene una velocidad de %dkm/h y el tiempo que tomo fue: %.2f segundos\n\n", felipeC, timeFelipeC);

    printf("El tamano de la pista es de: %.2f km\n", speedwayLength);

    if (winner == 1)
    {
        printf("El ganador es: amlo\n");
    }
    if (winner == 2)
    {
        printf("El ganador es: enp\n");
    }
    if (winner == 3)
    {
        printf("El ganador es: felipeC\n");
    }
    if (winner == 4)
    {
        printf("Los 3 carros quedaron empatados\n");
    }
    if (winner == 5)
    {
        printf("amlo y enp quedaron empatados\n");
    }
    if (winner == 6)
    {
        printf("amlo y felipeC quedaron empatados\n");
    }
    if (winner == 7)
    {
        printf("enp y felipeC quedaron empatados\n");
    }
    printf("Presiona una tecla para continuar...");
    getchar();
}

/*
Function: generateNumberCar
Description: Generates a random speed for a car in the race.
Parameters: None.
Return Value: A random integer speed for a car.
*/
int generateNumberCar()
{
    int num;
    num = (rand() % 100) + 100;
    return num;
}

/*
Function: podium
Description: Determines the winner of the race and handles tie scenarios.
Parameters:
- amlo, felipeC, enp: Floats representing the time taken by each car to complete the race.
Return Value: An integer representing the winner or a tie scenario.
*/
int podium(float amlo, float felipeC, float enp)
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
    return 0;
}

/*
Function: askSpeedway
Description: Prompts the user to input the length of the racetrack and validates the input.
Parameters: None.
Return Value: The length of the racetrack as a float (in kilometers).
Variables:
- speedway: An integer to store the user's input.
*/
float askSpeedway()
{
    int speedway;
    speedway = valid("Ingresa el tamano de la pista en metros: ", 0, INT_MAX);
    return (float)speedway / 1000;
}

/*
Function: getSpeed
Description: Calculates the speed of a car based on the racetrack length and the car's speed.
Parameters:
- speedway: The length of the racetrack in kilometers.
- playerSpeed: The speed of a car.
Return Value: The time taken by the car to complete the race in seconds.
Variables:
- speed: A float to store the calculated speed.
*/
float getSpeed(float speedway, float playerSpeed) 
{
    float speed;
    speed = speedway / playerSpeed;
    return speed * 3600;
}

// END OF THE CODE