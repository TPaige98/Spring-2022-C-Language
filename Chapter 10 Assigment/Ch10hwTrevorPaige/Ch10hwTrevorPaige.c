/*
 * Driver Menu System for Homework
 * Trevor Paige - Oct 31, 2021  <-- Please put your name/date here
 */

#include <stdio.h>

#define STUD 10
#define TEST 4

#define SIZE 10

int menu(void);   //prototype definition section
void hello(void);
void grades(void);
void sum_arr2(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           grades();
           break;

        case 3:
           sum_arr2();
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
    printf(" 2. Grades \n");
    printf(" 3. Sum_ARR2 \n");
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

void grades(void) {
    // initializing grade data for 4 students
    const float exams[TEST][STUD] =
    {
        {65,75,85,95,74,74,98,75,85,65},
        {88,65,75,78,99,88,87,76,98,100},
        {78,65,78,82,93,81,99,97,82,65},
        {90,85,88,96,100,88,100,96,95,92}
    };
    int test, student;
    float subtot, total;

    printf(" TEST         AVERAGE\n");
    for (test = 0, total = 0; test < TEST; test++)
    {             // for each test, sum grades for all student
        for (student = 0, subtot = 0; student < STUD; student++)
            subtot += exams[test][student];
        printf("%5d %15.1f\n", 1 + test, subtot/STUD);
        total += subtot; // total for all tests
    }
    printf("\nSTUDENT AVERAGES:\n\n");
    printf("  STU1  STU2  STU3  STU4  STU5  STU6  STU7  STU8  STU9  STU10 \n ");

    for (student = 0; student < STUD; student++)
    {             // for each test, sum grades for each student
        for (test = 0, subtot =0; test < TEST; test++)
            subtot += exams[test][student];
        printf("%5.1f ", subtot/TEST);
    }
    printf("\n");
}

int sump(int * start, int * end);
int min(int * ar, int * x);
int max(int ar[], int x);

void sum_arr2(void){

    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n", sizeof marbles);
    printf("The largest number is %d\n", max(marbles, SIZE));
    printf("The smallest number is %d\n", min(marbles, SIZE));

}
/* use pointer arithmetic   */
int sump(int * start, int * end)
{
    int total = 0;

    while (start < end)
    {
        total += *start; // add value to total
        start++;         // advance pointer to next element
    }

    return total;
}

int min(int * ar, int * x) // start of function that includes for loop
{
    int m;
    int min_marb = ar[0];

    for(m = 0; m < x; m++) // for loop that will determine the lowest number in the array

        if (min_marb > ar[m])
        min_marb = ar[m];

    return(min_marb);
}

int max(int ar[], int x) // start of function that includes while loop
{
    int m;
    int max_marb = ar[0];

    while(m < x) // start of while loop that will determine the highest number in the array.
    {
        if(max_marb < ar[m])
        max_marb = ar[m];
        m++;
    }
    return(max_marb);
}
