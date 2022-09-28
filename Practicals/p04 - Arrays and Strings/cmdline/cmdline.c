#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayConversion.h"
#include "math.h"
#include "ArrayOutput.h"
#include "caseconvert.h"

#define OFFSET 2

int main(int argc, char **argv)
{
	int soln;

	int *numArray = (int *)malloc(argc * sizeof(int));

	if (argc > 2)
	{
		printf("\nRunning arithemtic method.. \n \n");
		convertToInt(argv, numArray, argc);

		caseconvert(argv);
		/* If the first argument (argv[1]) is "sum", "max" or "reverse", your program should call that function and output the result. */

		/* int strcmp(const char *str1, const char *str2)*/
		if (strcmp(argv[1], "SUMOF") == 0)
		{								  /* int sumOf(int* a, int length) */
			soln = sumOf(numArray, argc); /* number of commands minus the offset (first 2 arguments) */
			printf("Total sum of the array is %d \n", soln);
		}
		else if (strcmp(argv[1], "MAX") == 0)
		{
			/* int max(int* a, int length) */
			soln = max(numArray, argc);
			printf("The largest number in the array is located in index %d \n", soln);
		}

		else if (strcmp(argv[1], "REVERSE") == 0) /* For reverse(), use the array output function from Question 3.*/
		{
			/* void reverse(int* a, int length) */
			reverse(numArray, argc); /*Array returned is a string/char array */
			output(numArray, argc);	 /* void output(int numArr[], int length)*/
		}
		else
		{
			printf("Error! argv[1] is invalid");
		}
	}
	else
	{
		printf("Error! Please enter more than 2 arguments");
	}
	free(numArray);
	return 0;
}
