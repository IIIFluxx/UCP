#include <stdio.h>
#include "math.h"
#define SIZE 5
/* 
Each takes an array of ints and the array length. 

The return types differ.

You should also write a temporary main() function for testing purposes.
Use the array initialisation notation to create test arrays. (Later we�ll replace this). */

int main()
{
	int arr[] = {10, 30, 50, 40, 20};
	int *ptr;
	int sumSoln = 0;
	int maxSoln = 0;
	ptr = arr; /* Storing the address of the first element of the array, in a pointer. a = &a[0] */
	/* METHOD 1: sumOf() */
	printf("Running sum()...\n");
	sumSoln = sumOf(ptr, SIZE);

	printf("Total sum of the array is %d \n", sumSoln);

	/* METHOD 2: max() */
	printf("Running max()...\n");

	maxSoln = max(ptr, SIZE);
	printf("The largest number in the array is located in index %d \n", maxSoln);

	/* METHOD 3: reverse() */

	printf("Running reverse()...\n");
	reverse(ptr, SIZE);

	return 0;
}

/* (a) sum() � adds up all the array elements and returns the sum, an int. */
int sumOf(int *a, int length)
{
	int i, solution;
	solution = 0;
	for (i = 0; i < length; i++)
	{
		solution = solution + *a;
		a++; /* moves to the next element in array (works when summing) */
	}
	return solution;
}

/* (b) max() � returns the index of the largest element in the array. */

int max(int *a, int length)
{
	int i;
	int *max = a; /* address with largest value */
	int cursor = 0;

	for (i = 0; i < length; i++)
	{
		/*if(*max < a[i])*/
		if (a[i] > *max)
		{
			max = a + i; /* save position of pointer with largest value */
			cursor = i;
		}
	}
	return cursor;

	/* (For an array containing {10, 5, 1}, max() should return 0. For the array {3, 15, 6, 500, 9} it should return 3). */
}

/* (c) reverse() � reverses the order of the array elements. It doesn�t return anything. */
void reverse(int *a, int length)
{
	int ii = 0;
	int *ptrX = a; /* address with first value */
	int *ptrY = a + length - 1;

	/* printf("Current array elements are: ");
	for(ii=0; ii<length; ii++)
	{
		printf("%d ", *a++);
	}
	printf("\n");

	Ask - why does this break the program?
	*/

	while (ptrX < ptrY)
	{
		int temp = *ptrX;
		*ptrX = *ptrY;
		*ptrY = temp;
		ptrX++;
		ptrY--;
	}

	printf("Reversed array elements are: ");
	for (ii = 0; ii < length; ii++)
	{
		printf("%d ", *a++);
	}
	printf("\n");
	/* (For an array containing {1, 2, 3, 4}, reverse() should change it to {4, 3, 2, 1}.) */
}
