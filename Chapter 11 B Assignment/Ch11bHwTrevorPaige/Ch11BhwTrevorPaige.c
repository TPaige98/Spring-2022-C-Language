/*
 * Driver Menu System for Homework
 * Trevor Paige - Nov 14, 2021  <-- Please put your name/date here
 */

#include <stdio.h>
#include <string.h>
#define FIRST 18
#define LAST 25
#define LIM 20

void ToUpper(char *);
void stsrt(char *strings[], int num);/* string-sort function */
char * s_gets(char * st, int n);


int menu(void);   //prototype definition section
void hello(void);
void classroll(void);

int main(void)
{
    int selection = menu();

    while(selection != 99) {

        switch(selection) {

        case 1:
           hello();
           break;

        case 2:
           classroll();
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
    printf(" 2. Class Roll\n");
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

void classroll(void)
{
    char firstname[LIM][FIRST];   /* array to first name       */
    char lastname[LIM][LAST];   /* array to store last name   */
    char lastfirst[LIM];
    char *ptstr[LIM];          /* array of pointer variables */
    int ct = 0;                /* input count                */
    int k;                     /* output count               */

    printf("Please enter up to %d names, and I will sort them for class roll call.\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");

    while (ct < LIM)
   {
       printf("\nPLEASE ENTER FIRST NAME: ");
       if (s_gets(firstname[ct], FIRST) != NULL
                && firstname[ct][0] != '\0')
       {
        printf("PLEASE ENTER LAST NAME: ");
        if (s_gets(lastname[ct], LAST) != NULL
                    && lastname[ct][0] != '\0')
           {
            ToUpper(firstname[ct]);
            ToUpper(lastname[ct]);
            strcat(lastname[ct], ", ");
            strcat(lastname[ct], firstname[ct]);
            ptstr[ct] = lastname[ct];
           }
           else
            break;
        }
        else
            break;
        ct++;
    }

    stsrt(ptstr, ct);          /* string sorter              */
    puts("\nHere's the sorted names:\n");
    for (k = 0; k < ct; k++)
        sprintf(lastfirst, "%s, %s\n", lastname, firstname);
        puts(lastfirst);     /* sorted pointers            */
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;

    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top],strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
