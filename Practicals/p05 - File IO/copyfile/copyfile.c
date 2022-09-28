#include <stdio.h>
#include "copyfile.h"
int main(int argc, char** argv)
{
    FILE* inFile;
    FILE* outFile;
    int ch;

    /* Command line argument error checking */


    if(argc != 3)
    {
        printf("Error! Incorrect number of arguments \n");
    }
    else
    {
        inFile = fopen(argv[1], "r"); /*argv[1] =  the source filename */
        outFile = fopen(argv[2],"w"); /*argv[2] =  the destination filename */
        
        /* Perform fopen error checking */
        if(inFile == NULL)
        {
            perror("Error: could not open inFile \n");
            fclose(inFile);
        }
        else if(outFile == NULL)
        {
            perror("Error: could not open outFile \n");
            fclose(outFile);
        }
        else if(ferror(inFile))
        {
            perror("Error reading from inFile \n");
            fclose(inFile);
        }
        else if(ferror(outFile))
        {
            perror("Error outputting to outFile");
            fclose(outFile);
        }
        else
        {
            ch = fgetc(inFile);
            while(!feof(inFile))
            {
                fputc((char)ch, outFile);
                 /* Insert next char into inFile */
                ch = fgetc(inFile);
                 /* Read next char */
            }
            fclose(inFile);
            fclose(outFile);
        }
    }
    return 0;
}
