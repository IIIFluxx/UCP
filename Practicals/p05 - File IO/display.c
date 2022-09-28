#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plot.h"
#include "display.h"

int main(int argc, char** argv)
{
    FILE* file;
    double** data;
    int rows, cols;
    int ii,jj;

    /* (a) Accept a filename as a command-line parameter 
        argv = 2 total. */

    if(argc != 2)
    {
        printf("Error! Incorrect number of arguments \n");
    }
    else
    {
        
        if(strcmp(argv[1], "-") == 0)
        {
           file = stdin;
        }
        else
        {
            file = fopen(argv[1],"r");
        }
        /* Error checking when opening file -- both perror's and last ferror check 
            1. file == NULL
            2. ferror(file pointer)
                perror(message)
                close file */

        if(file == NULL)
        {
            printf("Error: could not open file \n");
        }
        else /* Checks all complete, processing */
        {
            /* Read from file */
            fscanf(file, "%d %d", &rows, &cols); /* reads in first line */
            data = (double**)malloc(sizeof(double) * rows);  /* allocate a 2D array of the required size*/
            /* Make second level with cols ~ important step -- working with our integer level*/
            for(ii = 0; ii<rows;ii++)
            {
                data[ii] = (double*)malloc(sizeof(double) * cols); /* Makes a new array of double's */
                /* Read in all values (cols) and fill the array*/
                for(jj = 0;jj<cols;jj++)
                {
                    fscanf(file, "%lf", &(data[ii][jj]));
                }
            }
            /* Pass the array, row count and column count to the plot() function.
            void plot(double** data, int rows, int cols); */
            plot(data, rows, cols);
            /* Perform appropriate error checking and cleaning up, as before -- freeing, ferror to check EOF */
            for(ii=0;ii<rows;ii++)
            {
                free(data[ii]);
            }
            free(data);
            if(ferror(file))
            {
                perror("Error reading from file \n");
            }
            fclose(file);
        }
    }

    /* How to use ferror to check whether file ended prematurely? <---------- */
    return 0;
}

    /* The input file/data is structured as follows:
• The first line contains two integers, separated by a space — the number of rows
and columns in the array.
• Each subsequent line represents one row, and contains a space-separated list of
real numbers, one for each column*/