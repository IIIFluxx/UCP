#include <stdio.h>
int power()
{
    int ii;
    int n = 2;
    static int count = 0;
    
    for(ii=0;ii<count;ii++) 
    {
        n = n*2; /* Calculates a 'power of 2' - n multiplied by 2 */
    }
	/* printf statement will only print when DEBUG is defined */
	#ifdef DEBUG 
	printf("%dn\n",n);
	#endif
    count++;

    return n;
}
