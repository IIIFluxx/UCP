#include <stdio.h>
#include <stdlib.h>
#include "ArrayConversion.h"
#define OFFSET 2

/* 
Write a function to convert an array of string-formatted integers into an array of ints.


Note: There are a few standard C functions used to convert a single number from a
string to an int. Consult the lecture notes, or other resources.

 For instance, given the array {"7", "1", "14", "-5"}, the function should produce the
array {7, 1, 14, -5}.

*/


	/*
	The function should take three parameters 
		� an array of char* (i.e. an array of strings,not just a single string/char*)
		- an int array 
		- a length (int)
	*/

void convertToInt(char* strArray[], int intArray[], int length)
{
	int jj, ii;
	for(jj=0;jj<length;jj++)
	{
		intArray[jj] = atoi(strArray[jj]);
	}

	for(ii=OFFSET;ii<length;ii++)
	{
		printf("%d ",intArray[ii]);
	}
	printf("\n");

}