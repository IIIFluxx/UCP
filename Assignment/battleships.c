/*  --------------------------------------------------------------------------
**  Author: Bharath Sukesh
**  Date: 20/4/2020 4:20pm
**  Purpose: Part of the implementation for battleships game 
**  as per UCP assignment specification. This file contains the main method 
**  & handles all user interface to run other parts of the program.
** --------------------------------------------------------------------------
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "game.h"
#include "macros.h"
#include "fileio.h"

/*
    Function: main
    Imports: argc (int), argv (char**)
    Exports: (int)
    Purpose: Run when the users launches battleships. 
                Uses readSettings() & readMissiles() to read in the game's settings.
                main() will do error checking for the command line arguments.
*/


int main(int argc, char* argv[])
{
    
    int width,height; /* Width and Height of the board. */
    
    /* Two structures we use for the game itself.*/
    Ship* ship = NULL;
    Missile* missile = NULL;  

    
    int menuLoop = FALSE; /* Boolean variable for looping over the menu. */
    int menuChoice; /* User input for menu options. */

    LinkedList* shipList = NULL;  /* Data structure to store ship structures. */
    LinkedList* missileList = NULL; /* Data structure to store missile structures. */
    
    /* Menu outputted to terminal */
    char menuStr[] = "<1> - New Game.\n"
                     "<2> - List all missiles.\n"
                     "<3> - Create board file.\n"
                     "<4> - Create missile file. \n"
                     "<5> - Exit.\n"
                     "Please choose an option: ";

     /* If incorrect command line arguments */
    if(argc != 3)
    {
        printf("Error! Incorrect number of arguments \n");
        printf("Must have 3 arguments, e.g \t ./battleships board.txt test.txt \n");
    }
    else
    {
        shipList = createLinkedList();
        missileList = createLinkedList();
        if(readSettings(argv, &width, &height, ship, shipList)) 
        /*  Reads the settings file containing ships & shipLocations.
            Returns errors if invalid */
        {
             if(!(readMissile(argv, missile, missileList)))
             /* Reads the settings file containing missiles.
                Returns errors if invalid */
            {
                menuLoop = TRUE; /* Only runs the menu if settings are valid */
            }
            else
            {
                fprintf(stderr,"Invalid missile settings file \n"); 
                /* Freeing done in readMissile()  */
            }
        }
        else
        {
            fprintf(stderr,"Invalid board settings file \n");
            freeLinkedList(missileList,freeData);
        }
    }
    
    while(menuLoop)

    {
        /* Show menu and get the user's choice */
        spacer(); /* Simple divider function for aesthetics */
        printf("\t\t~~~~~~~ Menu ~~~~~~~\t\t");
        printf("\n%s", menuStr);
        scanf("%d", &menuChoice);

        switch(menuChoice)
        {
            case 1: /* New game */
            {
                spacer();
                printf("\t Starting new game.. \n");
                playBattleships(width, height,ship, shipList, missile,missileList);
                freeLinkedList(missileList, &freeData);
                missileList = createLinkedList();
                readMissile(argv, missile, missileList);
                break;
            }
            case 2: /* View missiles */
            {
                spacer();
                printf("\t Listing all missiles.. \n");
                printLinkedList(missileList, printString);
               
                break;
            }
            case 3: /* Make a custom board file */
            {
                spacer();
                printf("\t Creating board.. \n");
                createBoard();
                break;
            }
            case 4: /* Make a custom missiles file */
                spacer();
                printf("\t Creating missiles.. \n");
                createMissile();

            case 5: /* Exit program */
                spacer();
                printf("Exiting program, stay safe! \n");
                freeLinkedList(missileList, &freeData); 
                menuLoop = 0;
                break;
            default: /* If an invalid menu selection chosen by user */
            {
                printError("Invalid input - please choose a number between 1 and 5. \n");
                break;
            }
        }
    }
    
    /* Heap freeing */
    if(argc == 3)
    {
        freeLinkedList(shipList, &freeData);
    }
    else
    {
        printError("Please provide valid files \n");
    }
    



    return 0;
}




