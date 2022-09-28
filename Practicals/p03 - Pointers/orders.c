#include <stdio.h>
void ascending2(int* x, int* y)
{
	int temp;
	if(*x > *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
	}
}

void ascending3(int* x, int* y, int* z)
{
	ascending2(&x,&y);
	ascending2(&y,&z);
	ascending2(&x,&y);
	/* y will always be biggest number in this case */
}

void descending3(int* x, int* y, int* z)
{
	/* Run ascending3() first, then swap the values of x and z around */
	int temp;
	
	ascending3(&x,&y,&z); /*Output from ascending3() will have x,y & z in ascending order (from smallest to biggest) */
	
	temp = *x; /* Make temp, the value of the smallest number - dereference x/value of x. */
	*x = *z; /* x now equals the biggest value -- *z 	*/
	*z = temp;	/*Temp holds derefenced x value (from line 28) -- the smallest value. 
				 We assign *z the value held in temp. */
}