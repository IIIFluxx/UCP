#include <stdio.h>
#include "ArrayOutput.h"
#define SIZE 5

int main(void)
{
	int numArr[SIZE] = {4,14,5,8,2};
	printf("Solution: {");
	output(numArr, SIZE);
	printf("} \n");
	return 0;
}


void output(int numArr[], int length)
{
	int ii;
	for(ii=0;ii<length;ii++)
	{
		printf("%d", numArr[ii]);
		if (ii != length-1)
		{
        	printf(",");
    	}
		else
    	{
			printf(".");
		}
	}
}
