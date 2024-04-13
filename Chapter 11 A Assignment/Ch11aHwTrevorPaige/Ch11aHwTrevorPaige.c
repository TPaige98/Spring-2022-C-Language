/*
 * Driver Menu System for Homework
 * Trevor Paige - Nov 7, 2021  <-- Please put your name/date here
 */

#include <stdio.h>
#define LEN 10 // Constant variable for LEN. Will always be 10
#define LIM 12 // Constant variable for retailSales

char * getnchar(char * str, int n); // function declaration for #1
float retailSales(float sales[]); // function declaration for #2

int menu(void);

void hello(void);
void ex1(void);
void retail(void);


int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           ex1();
           break;

        case 3:
           retail();
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
    printf(" 2. EX1.c \n");
    printf(" 3. Retail Sales \n");
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

void ex1(void)
{
	char input[LEN];  // character array for LEN
	char *check;      // variable for check

    printf("Please enter 9 characters. "); // print statement
	check = getnchar(input, LEN - 1);      // check to see if input works
	if (check == NULL)      // if statement checking to see if check == NULL
		puts("Input failed..."); // prints "input failed" if check == NULL
	else // else statement for if input is properly entered
		puts(input); // prints input if the input was properly entered
	puts("Done!\n"); // prints done

}

char * getnchar(char * str, int n)  // function call from above
{
	int i; // variable of int i
	int ch; // variable of int ch

	for (i = 0; i < n; i++) // for statement that keeps going while i is less than n
	{
		ch = getchar(); //get character for input
		if (ch != EOF) // if the ch does not equal EOF, then place the ch in the str
			str[i] = ch; // the storing of ch in str
		else // for if ch does equal EOF
			break; // break the for loop
	}
	if (ch == EOF) // if statement that checks to see if ch == EOF
		return NULL; // if ch == EOF, then return NULL
	else    // if ch != EOF then
	{
		str[i] = '\0'; // if at end of string
		return str; // return str value
	}
}

void retail(void) {

    float sales[LIM];
    retailSales(sales);
}

float retailSales(float sales[]) {

    int i;
    const char * months[LIM] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };
    for(i = 0; i < LIM; i++) {
        printf("Please enter sales for %s: ", months[i]);
        scanf("%f", &sales[i]);
    }
   printf("\nMonth:    Sales:\n");
   for(i = 0; i < LIM; i++)
      printf("%-9s $%.2f\n", months[i], sales[i]);
}
