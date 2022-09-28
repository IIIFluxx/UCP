#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "randomarray.h"

int main(int argc, char** argv)
{
    /* Accept three command-line parameters: a filename, and two integers representing the number of rows and columns.*/
    FILE* file;
    int rows, cols,ii,jj;
    double** data;

    if(argc != 4)
    {
        printf("Error! Incorrect number of arguments \n");
    }
    else
    {
        /* Open file dependent on where the input comes from, check if null, check ferror using perror and then close */
        if(strcmp(argv[1], "-") == 0)
        {
            file = stdout;
        }
        else
        {
            file = fopen(argv[1], "w");
        }
        
        if(file == NULL)
        {
            printf("Error: could not open file. \n");
        }
        else
        {
            /* Make rows and cols = argument input */
            rows = atoi(argv[2]);
            cols = atoi(argv[3]);
            /* Allocate 2D Array */ 
            data = (double**)malloc(sizeof(double*) * rows); /* 1D Array */
            for(ii = 0; ii<rows; ii++)
            {
                data[ii] = (double*)malloc(sizeof(double)*cols); /* 2D Array */
            }
                /* Processing */
            randomArray(data,rows,cols,2);
            fprintf(file,"%d %d \n", rows,cols);
            for(ii=0;ii<rows;ii++)
            {
                for(jj=0;jj<cols;jj++)
                {
                     fprintf(file, "%f ", data[ii][jj]);
                     
                }
                fprintf(file,"\n");

                free(data[ii]);
            }
            free(data);
            if(ferror(file))
            {
                perror("Error reading from file. \n");
            }
            fclose(file);
        }
    }
    return 0;
}
