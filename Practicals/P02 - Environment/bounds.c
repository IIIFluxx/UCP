#include <stdio.h>
#include "macros.h"
#include "powers.h"
    
	
/* print statements - 1 = true, 0 = false */	
int main()
{
	long num, ii, answer;
	do
	{
		printf("Enter an integer between 1 and 31 \n");
		scanf("%ld", &num);
	} while (!BETWEEN(1,31,num)); /* Do-while loops until number is BETWEEN 1 and 31 inclusive */
	
	for (ii=1;ii<=num;ii++)
	{
		answer = power();
	}
	printf("Solution: %ld\n", answer);
    return 0;
}
  
