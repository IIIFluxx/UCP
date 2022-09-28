#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readJournal.h"

int main( int argc, char* argv[] )
{
    FILE* file;
    Entry** journalEntry; /* 2D array of Structs (Entry) */
    int index, numEntries;
    int i = 0;
    
    if(argc != 2)
    {
        printf("Error! Incorrect number of arguments \n");
    }
    else
    {
        file = fopen("journal.txt", "r");
        if(file == NULL)
        {
            perror("Error: could not open file. \n");
        }
        else /* Processing: */
        {
            /* Your program should take a single command-line parameter — an integer (index) (converted from a string).*/
            /* Steps:
            1. Get index
            2. Grab num entries
            3. fscanf from index onwards
            */

            fscanf(file,"%d",&numEntries); /* From integer on first line */

            index = atoi(argv[1]);

            if(index >= numEntries)
            {
                printf("Index greater than number of entries (%d). \n", numEntries);
            }
            else
            {
                journalEntry = (Entry**)malloc(numEntries * sizeof(Entry*));
            
                for(i=0;i<numEntries;i++)
                {
                    journalEntry[i] = (Entry*)malloc(sizeof(Entry)); /* Allocating memory for the Entry struct */
                    
                    journalEntry[i]->text = (char*)malloc(101*sizeof(char)); /* Specifically allocating space for 100 entries in the text/message field */
                    /* Space allocated -- reading  */

                    fscanf(file, "%d/%d/%d\n%101[^\n]", &(journalEntry[i]->day), (&journalEntry[i]->month), (&journalEntry[i]->year), (journalEntry[i]->text));
                    /* Read in the file and assort each part of the file to its according part in our journalEntry array of structs 
                    journalEntry = array
                    journalEntry[i] = struct
                    journalEntry[i].day = int
                    journalEntry[i]->day == (*journalEntry[i]).day
                    */
                }

                /* Scanned, print */

                printf("%d/%d/%d: %s\n", journalEntry[index]->year, journalEntry[index]->month, journalEntry[index]->day, journalEntry[index]->text);


                for(i=0;i<numEntries;i++)
                {
                    free(journalEntry[i] -> text);
                    free(journalEntry[i]);
                }
                free(journalEntry);
            }
            if(ferror(file))
            {
                perror("Error reading from file. \n");
            }
            fclose(file);
        }
    }
    return 0;
}