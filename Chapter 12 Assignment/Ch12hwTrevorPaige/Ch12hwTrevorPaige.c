/*
 * Driver Menu System for Homework
 * Trevor Paige - Nov 21, 2021  <-- Please put your name/date here
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cpuscore = 0, yourscore = 0;

int menu(void);
void hello(void);
void guessGame(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           guessGame();
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
    printf(" 2. Guessing Game \n");
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

void guessGame(void) {
    int randNum, guess;
    int attempts = 0;
    srand((unsigned int) (time(0)));
    randNum = rand() % 20 + 1;

    printf("Welcome to the guessing game!\n"
           "I am thinking of a number between 1 and 20 inclusive.\n"
           "You have 5 guesses. \n");

    while (attempts != 5) {
        printf("Please enter your guess... \n");
        while((scanf("%d", &guess) != 1) || guess < 1 || guess > 20) {
            while (getchar() != '\n')
                continue;
            printf("The number must be between 1 and 20 inclusive\n");
            printf("Please enter your guess... \n");
        }
        if (guess > randNum){
            attempts++;
            printf("The number is lower.\n");
        }
        else if (guess < randNum){
            attempts++;
            printf("The number is higher.\n");
        }
        else {
            printf("You guessed it! \n");
            yourscore++;
            printf("\nCurrent score is You: %d || Computer: %d \n", yourscore, cpuscore);
            printf("Game is over. Select the option from the menu to try again. \n");
            return;
        }
    }
    cpuscore++;
    printf("\nCurrent score is You: %d || Computer: %d \n", yourscore, cpuscore);
    printf("Game is over. Select the option from the menu to try again. \n");
}
