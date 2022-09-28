#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caseconvert.h"
#define OFFSET 2

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
