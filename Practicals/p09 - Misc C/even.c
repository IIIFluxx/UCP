/* Using bit manipulation, write a function that converts a positive number to its closest even number (either the number itself or the previous number)
Your function should accept an int—the number to convert. It is to return the closest even number. 
Whether that be the imported number or the previous number 

For example. If the function imports a 7 it should return 6, where as if it imports a 4
then it will return 4. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main( int argc, char* argv[])
{
    /* n+(n&1) */

    printf( "%d\n", atoi(argv[1]) - (atoi(argv[1]) & 1));
    return 0;
}
