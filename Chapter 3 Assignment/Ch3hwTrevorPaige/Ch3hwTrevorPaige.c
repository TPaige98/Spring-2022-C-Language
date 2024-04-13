/*
 * Driver Menu System for Homework
 * Trevor Paige, 8/29/2021  <-- Please put your name/date here
 */

/*
 * To answer the question from #8:
 * The reason why a float is better than an int, is for the reason that when dealing with measurements
 * you could run into the issue of having fractional or decimal measurements. That is why a float is better.
 */

#include <stdio.h>   //header file for input/output -
// since you will place all your assigned functions (programs) in this file, you do not need to include stdio.h again!

int menu(void);   //prototype definition section
void hello(void);
void ascii(void);
void conversion(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           ascii();
           break;

        case 3:
           conversion();
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
    printf(" 2. ASCII \n");
    printf(" 3. Volume Conversion\n");
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

void ascii(void) {
    int as; //variable
    printf("Please enter an ASCII code number in decimal format: ");
    scanf("%d", &as);  //conversion specifier
    printf("The code for %d is %c.\n", as, as); //print statement that converts a code number to the corresponding output
}

void conversion(void) {
    float cup, pint, oz, tespn, tblspn; //variables

    printf("How many cups do you have?: ");
    scanf("%f", &cup); //conversion specifier

    pint = cup / 2; //formulas for conversions
    oz = cup * 8;
    tblspn = oz * 2;
    tespn = tblspn * 3;

    printf("If you converted that number to other measurements, you would have: \n");
    printf("%.2f pints\n%.2f ounces\n%.2f tablespoons\n%.2f teaspoons\n", pint, oz, tblspn, tespn); //print statement that presents the completed formulas
}
