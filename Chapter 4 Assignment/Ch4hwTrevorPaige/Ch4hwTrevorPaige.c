/*
 * Driver Menu System for Homework
 * Trevor Paige - 9/5/2021  <-- Please put your name/date here
 */

#include <stdio.h>   //header file for input/output -
// since you will place all your assigned functions (programs) in this file, you do not need to include stdio.h again!

int menu(void);   //prototype definition section
void hello(void);
void pay(void);
void bytes(void);
void lettercount(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           pay();
           break;

        case 3:
           bytes();
           break;

        case 4:
           lettercount();
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
    printf(" 2. Pay \n");
    printf(" 3. Download \n");
    printf(" 4. Letter Count \n");
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

#define FICA 0.0765
void pay(void) {

    float hours;  //variables
    float hrpay;
    float gross, taxes, net;
    char empid[10];

    printf("Enter your employee ID, your hours worked, and also you hourly pay.\n");
    scanf("%s", empid);
    scanf("%f %f", &hours, &hrpay);

    gross = hours * hrpay;  //expression variables
    taxes = gross * FICA;
    net = gross - taxes;

    printf("\n%s Empl ID\n"
           "%9.2f Gross\n"
           "%9.2f Fica\n"
           "%9.2f Net Pay\n", empid, gross, taxes, net);
}

void bytes(void) {

    float speed, file;  //variables
    float dls;

    printf("Please enter your download speed in mbps and your file size in MB.\n");
    scanf("%f %f", &speed, &file);

    dls = (file * 8) / speed;  //expression variable

    printf("\nAt %.2f megabits per second, a file of %.2f megabytes\n"
           "downloads in %.2f seconds.\n", speed, file, dls);
}

#include <string.h>
void lettercount(void) {

    char first[40];  //character arrays allowing for possible long names
    char last [40];

    printf("What is your first name? \n");
    scanf("%s", first);
    printf("\nWhat is your last name? \n");
    scanf("%s", last);

    printf("\n%s %s\n", first, last);
    printf("%*d %*d\n", strlen(first), strlen(first), strlen(last), strlen(last)); //had to put strlen twice, because if it's only typed out once, the program just keeps going and never stops.

    printf("\n%s %s\n", first, last);
    printf("%-*d %-*d\n", strlen(first), strlen(first), strlen(last), strlen(last)); //same issue here, the program kept going and going and never finished or reset until I put strlen twice for each variable. Just kept adding lines.
}
