/*
    File name: Practica3_JuegoAdivinanzaEtiquetasGoto_PerezVentura_BrayanIvan
    Author: Brayan Ivan Perez Ventura
    Date of creation: September 13th 2023 // Date of modification: September 13th 2023
    Program description: A game about number guessing using tags and "goto" statement to control the flow of the game
*/

//********* LIBRARIES *******
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//******* FUNCTION PROTOTYPE *********
void mainGame();
void rulesGame();

// ********* MAIN FUNCTION ***********
int main()
{
    mainGame();
    return 0;
}

void mainGame()
{
    int numRandom, numTry, numUser, op;
START:
    system("CLS");
    rulesGame();
    srand(time(NULL));
    numRandom = rand() % 100 + 1;
    numTry++;
GUESSING:
    printf("%d\n", numRandom);
    scanf("%d", &numUser);
    if (numRandom == numUser)
    {
        printf("You have won with %d tries!\n", numTry);
        goto RESTART;
    }
    else
    {
        if (numRandom > numUser)
        {
            printf("The number is low, pick a higher number: ");
            numTry++;
            goto GUESSING;
        }
        else
        {
            printf("The number is high, pick a lower number: ");
            numTry++; 
            goto GUESSING;
        }
    }
RESTART:
    printf("Do you want to keep playing? (1.- yes, 2.- no)\n");
    scanf("%d", &op);
    if (op == 1)
    {
        goto START;
    }
    else
    {
        if (op == 2)
        {
            printf("Exiting from the game.\n");
            exit(0);
        }
        else
        {
            printf("Insert a valid number\n");
            goto RESTART;
        }
    }
}

void rulesGame()
{
    printf("WELCOME TO THE GAME!\n");
    printf("I will explain to you the rules of the game\n");
    printf("-- RULES OF THE GAME --\n");
    printf("1.- You will be able to guess as many times as you want to.\n");
    printf("2.- Everytime you execute the program, the number will change (even if you restart the game without leaving)\n");
    printf("3.- The number to guess is always random\n");
    printf("4.- If you guess correctly, it will display a message saying you've guessed it.\n");
    printf("5.- Have fun.\n\n");
    printf("GUESS THE NUMBER\n");
    printf("Please, insert a positive number (1 - 100): ");
}
