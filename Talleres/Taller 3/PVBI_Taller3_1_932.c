/*
Brayan Ivan Perez Ventura - 372781

Created code: September 16th 2023 / Last modified: September 16th 2023

In this code we will:
    1.- Calculate the factorial of a number using a function without return.
    2.- In this function, we will take a int number as a input and calculate its factorial.
        The result will be displayed in the screen, IT WILL NOT RETURN ANY RESULT, ONLY SHOW THE RESULT.
    3.- In the main function, we will ask the user to introduce a int number, not negative number to calculate its factorial.
    4.- We will ask the user if they want to calculate the factorial of a different number, if so, let the user to introduce a different number.
        If so not, show a good bye message and finish the program.

PVBI_Taller3_1_932
*/

// ******** LIBRARIES *********
#include <stdio.h>
#include <stdlib.h>

//******** PROTOTYPE FUNCTIONS ********
void calculateFactorial(int num);

//********** MAIN FUNCTION ***********
int main()
{
    int num, leave;
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
        calculateFactorial(num);
        printf("Do you want to leave? (1.- Yes 2.- No): ");
        scanf("%d", &leave);
    } while (leave != 1);
    printf("Leaving from the program.\n");
    return 0;
}
//************* DEVELOPMENT FUNCTIONS ********
void calculateFactorial(int num)
{
    int result, i;

    for (i = 1, result = 1; i <= num; i++)
    {
        result *= i;
    }
    printf("The factorial of %d is %d\n", num, result);
}
