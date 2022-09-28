#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caseconvert.h"
#define OFFSET 2

int main(int argc, char **argv)
{
    int ii = 0;
    caseconvert(argv);

    for (ii = 0; ii < argc; ii++)
    {
        printf("\n Upper Case String is: %s", argv[ii]);
    }
    printf("\n");

    return 0;
}

void caseconvert(char *s[])
{
    int ii = 0;
    while (s[1][ii])
    {
        if ((s[1][ii] > 'a') && (s[1][ii] < 'z'))
        {
            s[1][ii] -= 32;
        }
        ii++;
    }
}
