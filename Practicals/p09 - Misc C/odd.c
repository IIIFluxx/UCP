/* Import 5 return 5, import 6 return 7 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main( int argc, char* argv[])
{
    /* n+(n&1) */

    printf( "%d\n", atoi(argv[1]) | 1 );
    return 0;
}
