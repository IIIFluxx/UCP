/*  --------------------------------------------------------------------------
**  Author: Bharath Sukesh
**  Date: 20/4/2020 4:21pm
**  Purpose: This file contains common methods 
**  used across all c files in this program.
** --------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"

/*
    Function: printError
    Imports:  error (char*)
    Exports: (void)
    Purpose: Prints out an error
*/

void printError(char* error)
{
    printf("Error: %s\n", error);
}


/*
    Function: spacer
    Imports:  (void)
    Exports: (void)
    Purpose: Divider to make program look neater
*/
void spacer()
{
    printf("\n -------------------------------------------------\n");
}


/*
    Function: toUpperStr
    Imports:  s(char *)
    Exports: (void)
    Purpose: Converts a string entirerly into upper-case only.
*/

void toUpperStr(char *s)
{
    int ii = 0;
    int ln = strlen(s);

    for(ii=0;ii<ln;ii++) /* For loop - loops until the length of the string. */
    {
        if ((s[ii] >= 'a') && (s[ii] <= 'z')) /* If lower-case
 */        {
            s[ii] -= 32; /* Make upper-case */
        }
    }
}


/*
    Function: toUpper
    Imports:  ch(char)
    Exports: ch(char)
    Purpose: Converts a char into upper-case.
*/

char toUpper(char ch)
{
    if (ch>=97 && ch<=122)
    {
        ch = ch - 32; 
    }
    return ch;
}

/*
    Function: printString
    Imports:  data(void*)
    Exports: (void))
    Purpose: Acts as a toString for any data-type. 
                Prints out the contents of the data import.
*/

void printString(void* data)
{
   char* str = (char*)data;
   printf("  %s\n", str);
}