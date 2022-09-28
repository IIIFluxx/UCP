#include <stdio.h>
#include "ArrayOutput.h"
#define OFFSET 2

void output(int numArr[], int length)
{
	int ii;
	printf("Solution: {");
	for(ii=0;ii<length-2;ii++)
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
	printf("} \n");
}
