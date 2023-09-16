/*
Brayan Ivan Perez Ventura - 372781

Created code: September 16th 2023 / Last modified: September 16th 2023

In this code we will:
    We wil calculate the factorial of a int number using a recursive function.
    It will take a int number as a input and the function will calculate its factorial as a recursive function
    It will return the value of the factorial number.
PVBI_Taller3_2_932
*/

//***** LIBRARIES **********
#include <stdio.h>
#include <stdlib.h>

//******* PROTOTYPE FUNCTIONS ******
int calculateFactorial(int num);

//******** MAIN FUNCTION ******
int main()
{
    int num, leave, result;
    do
    {
        num = -1; // We initialize the num as -1 so it can join to the while.
        while (num < 0)
        {
            system("CLS");
            printf("Program to calculate the factorial of a number\n");
            printf("Introduce a positive number: ");
            scanf("%d", &num);
        }
        result = calculateFactorial(num);
        printf("The factorial of %d is %d\n\n", num, result);
        printf("Do you want to leave? (1.- Yes 2.- No): ");
        scanf("%d", &leave);
    } while (leave != 1);
    printf("Leaving from the program.\n");
    return 0;
}

//******** RECURSIVE FUNCTION ********
int calculateFactorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * calculateFactorial(num - 1);
    }
}
