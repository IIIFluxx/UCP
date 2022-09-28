#include <stdlib.h>
#include <time.h>

int main( int argc, char* argv[] )
{

    time_t startTime = time(NULL);

    while( time(NULL) - startTime < atoi(argv[1]));
    /* Run until time is elapsed. */
    return 0;
}