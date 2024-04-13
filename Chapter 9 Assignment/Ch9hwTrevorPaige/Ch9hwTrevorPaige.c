/*
 * Driver Menu System for Homework
 * Trevor Paige - Oct 24, 2021  <-- Please put your name/date here
 */

#include <stdio.h>   //header file for input/output -
// since you will place all your assigned functions (programs) in this file, you do not need to include stdio.h again!

int menu(void);   //prototype definition section
void hello(void);
void min_driver(void);
void chline_driver(void);
void sort_driver(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           min_driver();
           break;

        case 3:
           chline_driver();
           break;

        case 4:
           sort_driver();
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
    printf(" 2. Min \n");
    printf(" 3. ChLine \n");
    printf(" 4. Sort \n");
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

double min(double, double);

void min_driver(void) {    // driver that takes keyboard input to send to "min"
    double num1, num2;

    printf("Enter a pair of doubles (q to quit): \n");

    while (scanf("%lf %lf", &num1, &num2) == 2) {      // while loop for keyboard input
        printf("\nThe minimum value of %.2f and %.2f is %.2f.\n\n", num1, num2, min(num1,num2));

        printf("Enter a pair of doubles (q to quit): \n");
    }
    getchar();
}

double min(double n, double m) {
    double minmin;
    if (n < m)
        minmin = n;
    else
        minmin = m;
    return minmin;
}

int chline(char, int, int);

void chline_driver(void) { // driver that takes the input from keyboard to send to "chline"
    char ch;
    int coli, colj;

    printf("Please enter a type character and then two integers (qq to quit): \n");

    while (scanf("%c %d %d", &ch, &coli, &colj) == 3){ // while loop for keyboard input

        chline(ch, coli, colj); // reference to chline function
        while(getchar() != '\n')
            continue;

        printf("\n\nPlease enter a type character and then two integers (qq to quit): \n");
    }
    getchar();
}

int chline(char ch, int coli, int colj){ // function loops for chline_driver
    int column;

    for (column = 1; column < coli; column++){ // blank space for loop
        putchar(' ');
    }
    for (; column <= colj; column++){ // character type for loop
        putchar(ch);
    }
}

double sort(double *a, double *b, double *c);

void sort_driver(void){ // driver that takes the input from the keyboard to send to "sort"
    double a, b, c;

    printf("Please enter 3 doubles to be sorted in order (q to quit):\n");

    while (scanf("%lf %lf %lf", &a, &b, &c) == 3){ // while loop for keyboard input

        printf("\nYour original order is: \n" // the original order of keyboard input
            "a = %.2f, b = %.2f, and c = %.2f", a, b, c);

        sort(&a, &b, &c);

        printf("\n\nYour updated order is: \n" // the updated order of keyboard input after the function "sort" is ran
            "a = %.2f, b = %.2f, and c = %.2f", a, b, c);

        while(getchar() != '\n')
            continue;

        printf("\n\nPlease enter 3 doubles to be sorted in order (q to quit):\n");
    }
    getchar();
}

double sort(double *a, double *b, double *c) { // function for sort_driver

    double temp;

    if (*a > *b) {      // if's that setup the order of numbers.
        temp = *b;
        *b = *a;
        *a = temp;
    }
    if (*b > *c) {
        temp = *c;
        *c = *b;
        *b = temp;
    if (*a > *b){
        temp = *b;
        *b = *a;
        *a = temp;
        }
    }
}
