#include <stdio.h>

char readInts(int* x, int* y, int* z)
{
	char choice;
	int n1,n2,n3;
	
	printf("Please enter the first number \n");
	scanf("%d",&n1);
	*x = n1;
	
	printf("Please enter the second number \n");
	scanf("%d",&n2);
	*y = n2;
	
	printf("Please enter the third number \n");
	scanf("%d",&n3);
	*z = n3;
	
	do
	{
		printf("Please enter A for ascending, or D for descending \n");
		scanf(" %c",&choice);
	} while((choice!='A')&&(choice!='D'));
	return choice;
}