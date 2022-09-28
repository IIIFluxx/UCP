#include <stdio.h>
#include <string.h>
#include "logfile.h"

int main(int argc, char** argv)
{
    FILE* inFile;
    char message[512];
    char month[4];
    int day, hour, minute, second;
    int numSec;
    
    /* Command line argument error checking */
    if(argc != 2)
    {
        printf("Error! Incorrect number of arguments. \n");
    }

    else
    {
        inFile = fopen(argv[1], "r"); /* name of log file */

        if(inFile == NULL)
        {
            perror("Error: could not open inFile \n");
            fclose(inFile);
        }
        else if(ferror(inFile)) /* last minute check - ferror */
        {
            perror("Error reading from inFile \n");
            fclose(inFile);
        }
        else /* Read the file line-by-line using a combination of fscanf and fgets. */
        {
            /* Store string in an array */
            do
            {
                /* month day hour:min:sec process: message 
                e.g. Aug 19 03:37:01 kernel: imklog 4.4.2, log source = /proc/kmsg started. */
                fscanf(inFile, "%3s %d %d:%d:%d", month,&day,&hour,&minute,&second); /* What to do with message */
                fgets(message,512, inFile);
                if(strstr(message, "fail") != NULL)
                {

                    /* For each matching line, convert the time into the number of seconds since midnight -- ask*/
                    numSec = second + (minute * 60) + (hour * 3600);
                    printf("%d %s",numSec,message);
                }

            } while(!feof(inFile));
            fclose(inFile);
        }
    }
    return 0;
}