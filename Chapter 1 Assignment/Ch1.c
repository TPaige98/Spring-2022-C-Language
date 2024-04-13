/*
 * Menu driver for Chapter 1 programs
 * 7/31/2020 - JAL
 */

#include <stdio.h>   //header file for input/output

int menu(void);   //function prototypes
void hello(void);
void concrete(void);
void extension(void);
void dogs(void);
void macroMuscle(void);

int main(void)
{
    int selection = menu();  //variable declaration and initialization via
    //call to menu(). The line above also serves as the 'priming' read
    //for the following while loop

    while(selection != 99) {

        // The switch statement is similar to a chained if-else except conditions
        //fall through in C!
        switch(selection) {

        case 1:
            hello(); // function call to hello()
            break; /* optional, but the remaining code will execute if omitted! */

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        default: /* Optional - but a good idea especially if you have no other
            error catching! */
            printf("Please enter a valid selection.\n");
        }

    selection = menu();    // get the next menu selection,
    //otherwise, you have an eternal loop!
    }

   return 0;  // 0 is an integer type and int main(void) returns an int
}

int menu(void) {
    int choice = 99;
    printf("***************************\n");
    printf(" 1. Hello World Program\n");  //menu option for hello()
    printf(" 2. Concrete Program\n");
    printf(" 3. Extension Program\n");
    printf(" 4. Dogs Program\n");
    printf(" 5. MacroMuscle Program\n");
    printf("99. Exit\n");
    printf("Please select number and press enter:\n");
    printf("***************************\n");
    scanf("%d", &choice);
    getchar();  // clear the buffer since the integer will be read
    // but the act of pressing enter leaves the \n in the buffer
    return choice;
}

// hello() function definition
void hello(void) {
    printf("Hello, world!\n");
}
