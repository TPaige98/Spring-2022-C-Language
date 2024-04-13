/*
 * Driver Menu System for Homework
 * Trevor Paige - Oct 9, 2021  <-- Please put your name/date here
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int menu(void);   //prototype definition section
void hello(void);
void count_ch(void);
void betterguess(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           count_ch();
           break;

        case 3:
           betterguess();
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
    printf(" 2. Count Character\n");
    printf(" 3. Better Guess \n");
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

void count_ch(void) {
    char ch;
    int alpha = 0, pun = 0, ws = 0, all;  // variables to be added and included with loops

    printf("Enter text and/or characters to be counted to the screen. "
           "Press ctrl-z or ctrl-d at the beginning of the line to exit.\n");

    while((ch = getchar())!= EOF) { // while loop that sets up text entry and addition of text, whitespace, and punctuations.
        if(isalnum(ch))
            alpha++;
        else if(ispunct(ch))
            pun++;
        else if(isspace(ch))
            ws++;
    all = alpha + ws + pun;
    }

    printf("Alphanumeric: %d, Punctuation: %d, WhiteSpace: %d, All: %d\n", alpha, pun, ws, all);

}

void betterguess(void){
    int guess, high = 100, low = 1;     // variables
    guess = (low + high) / 2;       // basic guess function that will be used later
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nType (c) if my guess is correct and type");
    printf("\n(h) if the answer is too high or an (l) if it is too low.\n\n");
    printf("Is your answer %d?\n", guess);  // use of guess function
    printf("Enter (h)igh, (l)ow, (c)orrect: ");

    while ((response = getchar()) != 'c')     /* get response */
    {
        if (response == 'h') {
            high = guess - 1;       // update for high
            guess = (low + high) / 2;       // new guess
            printf("\nNew high value: %d\n\n", high);
            printf("Next guess: %d?\n", guess);
            printf("Enter (h)igh, (l)ow, (c)orrect: ");
        }
        else if (response == 'l') {
            low = guess + 1;        // update for low
            guess = (low + high) / 2;       // new guess
            printf("\nNew low value: %d\n\n", low);
            printf("Next guess: %d?\n", guess);
            printf("Enter (h)igh, (l)ow, (c)orrect: ");
        }
        else
            printf("Sorry, I understand only (h), (l), or (c).\n");

        while (getchar() != '\n')
            continue;                 /* skip rest of input line */
    }
    printf("\nI knew I could do it!\n");
}
