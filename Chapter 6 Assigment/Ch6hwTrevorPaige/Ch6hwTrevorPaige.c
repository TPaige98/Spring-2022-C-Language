/*
 * Driver Menu System for Homework
 * Trevor Paige - Sept 27, 2021  <-- Please put your name/date here
 */

#include <stdio.h>
#include <string.h>
#define CLASS 15  // definition for 3rd program. Class size is 15

int menu(void);   //prototype definition section
void hello(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           backrow();
           break;

        case 3:
           singl_back();
           break;

        case 4:
           grades();
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
    printf(" 2. BackRow \n");
    printf(" 3. SingleBack \n");
    printf(" 4. Grades \n");
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

void backrow(void)
{
    const int ROWS = 6;  // variables for the letters and rows
    int row;
    char ch;

    for (row = 0; row <= ROWS; row++)  // for loop
    {
        for (ch = ('F');  row > ('F' - ch); ch--)
            printf("%c", ch);  // action for the for loop (end result)
            printf("\n");
    }
}

void singl_back(void)
{
	char input[81];
	int length, i;

	printf("Enter a word: ");
	scanf("%s", input);
	length = strlen(input);

	i = length;  // initialization
	while (i >= 0)      // test
    {
        printf("%c", input[i]);  // action
        i--;  // update
	}
	printf("\n");
}

void grades(void)
{
    int i, grade[CLASS];  // variables
    int sum = 0;
    float average;

    printf("Enter all %d grades from your class (0-100%%) Please:\n", CLASS);

    for (i = 0; i < CLASS; i++)
        scanf("%d", &grade[i]);  // take in the input of the fifteen grades
        printf("Grades for all students:\n");

    for (i = 0; i < CLASS; i++)
        printf("%3d", grade[i]);  // read back the 15 grades at the end
        printf("\n");

    for (i = 0; i < CLASS; i++)
        sum += grade[i];         // add up the grades for a total

    average = (float) sum / CLASS;    // average formula to average grades
    printf("That's a class average of %.2f%%\n", average);
}

