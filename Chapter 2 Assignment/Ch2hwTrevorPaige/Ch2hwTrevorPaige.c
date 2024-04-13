/*
 * Driver Menu System for Homework
 * Trevor Paige - August 24, 2021  <-- Please put your name/date here
 */

#include <stdio.h>   //header file for input/output -
// since you will place all your assigned functions (programs) in this file, you do not need to include stdio.h again!

int menu(void);   //prototype definition section
void hello(void);
void mpg(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
            mpg();
           break;

        case 3:

           break;

        case 4:

           break;

         default:
            printf("Please enter a valid selection.\n");
        }

    selection = menu();
    }

   return 0;
}

int menu(void) {
    int choice;
    printf("***************************\n");
    printf(" 1. Hello \n");
    printf(" 2. Miles per Gallon \n");
    printf(" 3. \n");
    printf(" 4. \n");
    printf("99. Exit\n");
    printf("Please select number and press enter:\n");
    printf("***************************\n");
    scanf("%d", &choice);
	getchar();
    return choice;
}

void hello(void) {
    printf("Hello, World!!!\n");
}

void mpg(void) {
    float miles, gallons, milgal;  // float variables
    printf("Please enter the miles driven: ");
    scanf("%f", &miles);  // specifier that uses float so the user can enter half or quarter miles if needed
    printf("Please enter the gallons of gas used: ");
    scanf("%f", &gallons);  // specifier that uses float so the user can enter half or quarter gallons if needed
    milgal = miles / gallons;  // expression that calculate miles per gallon
    printf("The car in question runs at %.1f miles per gallon.\n", milgal);
}
