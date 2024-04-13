/*
 * Driver Menu System for Homework
 * Trevor Paige - Aug 21, 2021  <-- Please put your name/date here
 */

#include <stdio.h>   //header file for input/output -
// since you will place all your assigned functions (programs) in this file, you do not need to include stdio.h again!

int menu(void);   //prototype definition section
void hello(void);
void thisClass (void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
            thisClass();
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
    printf(" 2. This Class \n");
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

void thisClass (void) {
    int classes;
    printf("Hello my name is Trevor Paige.\n");
    printf("I would like to be able to learn more about C Language, so I can further my knowledge of coding for future semesters.\n");
    printf("I am currently taking two classes this semester while I work full-time. \n");
    printf("How many class(es) are you taking this semester? Input class(es): \n");
    scanf("%d", &classes);
    printf("You are in %d class(es) this semester while I am in two! Congratulations to us both being in college! \n",
           classes);

}
