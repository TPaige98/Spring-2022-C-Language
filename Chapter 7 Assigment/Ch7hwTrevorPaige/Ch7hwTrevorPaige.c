/*
 * Driver Menu System for Homework
 * Trevor Paige - October 3, 2021  <-- Please put your name/date here
 */

#include <stdio.h>
#include <stdbool.h>

#define P_RATE 10.0     // constants for program 1 and 2
#define MAXHOUR 40.0
#define OTRATE 1.5
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define CUTOFF1 300.0
#define CUTOFF2 450.0
#define BASE1 RATE1 * CUTOFF1
#define BASE2 BASE1 + (RATE2 * (CUTOFF2 - CUTOFF1))

int menu(void);   //prototype definition section
void hello(void);
void tax_rate(void);
void switch_pay(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           tax_rate();
           break;

        case 3:
           switch_pay();
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
    printf(" 2. Tax Rate \n");
    printf(" 3. Switch Pay \n");
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

void tax_rate(void)
{
    float hours, pay, taxes, total;

    printf("Please enter hours worked:  ");
    scanf("%f", &hours);

    if (hours > MAXHOUR)
        pay = ((MAXHOUR * P_RATE) + ((hours - MAXHOUR) * (P_RATE * OTRATE)));
    else
        pay = P_RATE * hours;


    if (pay <= 300.0)
        taxes = pay * RATE1;
    else if (pay <= 450.0)
        taxes = BASE1 + ((pay - CUTOFF1) * RATE2);
    else if (pay > 450.0)
        taxes = BASE2 + ((pay - CUTOFF2) * RATE3);

    total = pay - taxes;

    printf("You worked a total of %.2f hours which amounts to a gross pay of $%.2f\n"
           "and a tax cost of $%.2f. Which amounts to a net pay of $%.2f.\n", hours, pay, taxes, total);
}

void switch_pay(void)
{
    bool end_prog = false;
    int input;
    float rate, hours, pay, total, taxes;

    while(input != 5)
    {
        printf("*******************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr                            2) $9.33/hr\n");
        printf("3) $10.00/hr                           4) $11.20/hr\n");
        printf("5) quit\n");
        printf("*******************************************************************\n");

        scanf("%d", &input);

        switch (input)
        {
            case 1 :
                rate = 8.75;
                break;
            case 2 :
                rate = 9.33;
                break;
            case 3 :
                rate = 10.00;
                break;
            case 4 :
                rate = 11.20;
                break;
            case 5 :
                end_prog = true;
                break;
            default :
                printf("Please enter a valid input from the list below.\n\n");
                continue;
        }
        if (end_prog)
            break;

        printf("Please enter hours worked:  ");
        scanf("%f", &hours);

        if (hours > MAXHOUR)
            pay = ((MAXHOUR * rate) + ((hours - MAXHOUR) * (rate * OTRATE)));
        else
            pay = rate * hours;

        if (pay <= 300.0)
            taxes = pay * RATE1;
        else if (pay <= 450.0)
            taxes = BASE1 + ((pay - CUTOFF1) * RATE2);
        else if (pay > 450.0)
            taxes = BASE2 + ((pay - CUTOFF2) * RATE3);

            total = pay - taxes;

            printf("You worked a total of %.2f hours which amounts to a gross pay of $%.2f\n"
            "and a tax cost of $%.2f. Which amounts to a net pay of $%.2f.\n\n", hours, pay, taxes, total);
    }
}



