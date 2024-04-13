/* pe6-7.c */

#include <stdio.h>
#include <string.h>

void pe6-7( void )
{
	char input[81];
	int i;
	int length;

	printf("Enter a word: ");
	scanf("%s", input);
	length = strlen(input);
	for (i = 0; i <= length; i++)
		printf("%c", input[i]);
	printf("\n");

}