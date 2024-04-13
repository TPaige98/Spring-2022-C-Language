/*
 * Driver Menu System for Homework
 * Trevor Paige - Sept 19, 2021  <-- Please put your name/date here
 */

#include <stdio.h>   //header file for input/output -
// since you will place all your assigned functions (programs) in this file, you do not need to include stdio.h again!

int menu(void);   //prototype definition section
void hello(void);
void min_hour(void);
void buildup(void);
void addemup2(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           min_hour();
           break;

        case 3:
           buildup();
           break;

        case 4:
           addemup2();
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
    printf(" 2. Min_Hour \n");
    printf(" 3. Buildup \n");
    printf(" 4. AddEmUp 2 \n");
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

#include <stdio.h>
#define MIN_PER_HOUR 60  // minutes in an hour
void min_hour(void)
{
    int min, hour, left;

    printf("Convert minutes to hours and minutes.\n");
    printf("Please enter the number of minutes (Enter 0 or <0 to quit):\n");
    scanf("%d", &min);

    while (min > 0) //loop start
    {
        hour = min / MIN_PER_HOUR;
        left = min % MIN_PER_HOUR;
        printf("%d minute(s) is %d hour(s), %d minute(s).\n", min,
                hour, left);
        printf("Convert minutes to hours and minutes.\n");
        printf("Please enter the number of minutes (Enter 0 or <0 to quit):\n");
        scanf("%d", &min);  //update
    }

    printf("Done!\n");
}

void buildup(void)
{
    int num, add;  //variable

    printf("Enter an integer and see your integer add up to +10 the integer you entered.\n");
    printf("(For ex. Entering 5 will show 5, 6, 7... All the way up to 15.\n");
    printf("Please enter your integer:\n");
    scanf("%d", &num);
    printf("\n");

    add = num + 10;  //variable content

    while (num <= add) //loop start
    {
        printf("%d\n", num);
        num = num + 1.0; //update
    }
}

void addemup2(void)
{
    int count, sum, dec;  // variables

    printf("This program calculates the sum of an entered integer and all the integers before it.\n");
    printf("For ex. If you enter 4, then the answer will be the sum of 1 + 2 + 3 + 4\n");
    printf("Please enter your integer of choice:\n");
    scanf("%d", &dec);
    printf("\n");

    sum = 0;      // variable content
    count = 0;

    while (count++ < dec)  // loop start
        sum = sum + count;
        printf("sum = %d\n", sum);
}
