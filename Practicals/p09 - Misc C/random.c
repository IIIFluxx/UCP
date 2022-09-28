#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Write a function to return a random array element. Your function should accept two parameters
    — an array of void pointers and
    — the array length. 
    
    It should return a void pointer.
    
    Your function should pick an element from the array at random and return it.
    Your function does not need to seed the random number generator itself. You should do this in main() when testing the function. */

int main()
{
    void* arr[5];
    int intArr[] = {1, 2, 3, 4, 5};
    int len = 5;
    int i;

    srand(time( NULL));

    for( i = 0; i < len; i++ )
    {
        /* Set fields of arr = &intArr */
        arr[i] = (void*)&intArr[i];
    }

    printf("Chosen element (1-5): %d\n",*(int*)randElement(arr, len));
    

    return 0;
}


void* randElement(void** arr, int len)
{
    return arr[ ( rand() % len ) ];
}

