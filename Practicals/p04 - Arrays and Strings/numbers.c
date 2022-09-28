#include <stdio.h>
#include "orders.h"
#include "user_input.h"

/* main gets input

int x,y,z
ptrX, ptrY, ptrZ

ptrX = &x, ptrY = &y, ptrZ = &z

Get input for x -- = scanf(&x) etc. for y/z etc.

call asc/dsc functions*/

int main()
{

	int x, y, z;
	int *ptrX, *ptrY, *ptrZ;
	funcpoint fp;
	char option;

	ptrX = &x;
	ptrY = &y;
	ptrZ = &z;

	option = readInts(ptrX, ptrY, ptrZ);

	printf("First number: %d \n Memory Address is: %p \n", x, (void *)&x);
	printf("Second number: %d \n Memory Address is: %p \n", y, (void *)&y);
	printf("Third number: %d \n Memory Address is: %p \n", z, (void *)&z);

	fp = order(option);

	(*fp)(ptrX, ptrY, ptrZ);

	/* printf("Running ascending2()... \n");
    ascending2(ptrX, ptrY); 
	
	printf("Running ascending3()... \n");
    ascending3(ptrX,ptrY,ptrZ);*/

	/* printf("Running descending3()... \n");
    descending3(ptrX,ptrY,ptrZ); */
	printf("------------------------- \n ");
	printf("After processing...\n \n ");
	printf("------------------------- \n ");
	printf("First number: %d \n Memory Address is: %p \n", x, (void *)&x);
	printf("Second number: %d \n Memory Address is: %p \n", y, (void *)&y);
	printf("Third number: %d \n Memory Address is: %p \n", z, (void *)&z);

	return 0;
}
