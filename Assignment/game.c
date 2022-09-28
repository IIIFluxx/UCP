/*  --------------------------------------------------------------------------
**  Author: Bharath Sukesh
**  Date: 20/4/2020 4:43pm
**  Purpose: Part of the implementation for battleships game 
**  as per UCP assignment specification. This file handles the game itself.
** --------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"
#include "game.h"
#include "macros.h"
#include "fileio.h"


/*
    Function: playBattleships
    Imports: width (int), height (int), ship (Ship*), shipList (LinkedList*), missile (Missile*), missileList (LinkedList*)
    Exports: (void)
    Purpose: Handles the game of battleships. This function acts as a 
                hub for the game and calls functions as needed. 
*/

void playBattleships(int width, int height, Ship *ship, LinkedList* shipList, Missile* missile, LinkedList* missileList)
{
    char** board; /* 2D Matrix - game board */
    int i,j; /* For loop indexes */
    int destroyed = 0; /* Condition if all ships have been destroyed. */
    int winner = FALSE; /* Condition if the game ending has been reached. */

    /* Heap allocation for the game board */
    board = (char**)malloc(height * sizeof(char*));
    for(i = 0; i < height; i++)
    {
        board[i] = (char*)malloc(width * sizeof(char));

        for(j = 0; j < width; j++)
        {
            /* Initializes the board */
            board[i][j] = '#'; /* All squares will have '#' at the beginning. */
        }
    }

    while(winner == FALSE) /* Runs the game until a game-ending condition has been reached. */
    {
        printBoard(&board, width, height); 
        takeTurn(&board, width, height, &shipList, &missileList, &winner, &destroyed); 
    }
    if(winner == TRUE) /* If a game-ending condition has been reached. */
    {
        spacer();
        printf("FINAL BOARD: \n"); 
        printBoard(&board, width, height);
        spacer();
    }

    /* Heap freeing */
    for( i = 0; i < height; i++ )
    {
        free(board[i]);
    }
    free(board);
}


/*
    Function: printBoard
    Imports:  Board (char***), width(int), height(int)
    Exports: (void)
    Purpose: Displays the board to the terminal
*/
 void printBoard(char*** Board, int width, int height)
{
    int ii,jj,kk; /* For loop indexes */
    char temp;
    char** board; 
    board = *Board;
    temp = 65;
    printf("\n");
    printf(":) ||"); /* Top left corner */

    for(ii=0;ii<width;ii++) /* Top axis -- A,B,C,D, [..] */
    {
        printf(" %c |", temp+ii); 
    }
    printf("\n---++"); /* Divider for y-axis (between 1,2,3,[..]) */
    for(ii=0;ii<width;ii++)
    {
        printf("===+"); /* Divider between top-axis & grid */
    }
    printf("\n");

    for(ii=0;ii<height;ii++)
    {
        printf(" %d ||",ii+1); /* Print Y coords */
        for(jj=0;jj<width;jj++)
        {
            /* Colours w/ conditional compilation */

            #ifdef MONO /* MONO compilation - no colours/only black & white */
                printf(" %c |", board[ii][jj]);
            
            #elif DEBUG /* DEBUG compilation - paints ships visible to user */
            if(board[ii][jj]=='D') 
            {
                printf(" %s%c%s |", MAGENTA, '#', RESET);
            }
            if (board[ii][jj] == '0')
            {
                printf(" %s%c%s |", BLUE, '#', RESET);
            }
            if(board[ii][jj] == 'X')
            {
                printf(" %s%c%s |", BLUE, '#', RESET);
            }
            if(board[ii][jj] == '#')
            {
                printf(" %s%c%s |", BLUE, '#', RESET);
            }
            #else /* Normal compilation - R/G/B/White */

            if (board[ii][jj] == '0') /* If a ship is located at a coordinate, place a green '0' */
            {
                printf(" %s%c%s |", GREEN, board[ii][jj], RESET);
            }
            else if(board[ii][jj] == 'X') /* If a missile hits a tile with no ship present, place a red 'X' */
            {
                printf(" %s%c%s |", RED, board[ii][jj], RESET);
            }
            else if(board[ii][jj] == '#') /* If a tile has not been hit, place a blue '#'. */
            {
                printf(" %s%c%s |", BLUE, board[ii][jj], RESET);
            }
            else
            {
                printf(" X |");
            }
            #endif
        }
        printf("\n");
        printf("---++");  /* Divider between tiles */
        for(kk=0;kk<width;kk++)
        {
            printf("---+"); /* Bottom row divider */
        }
        printf("\n");
    }
    
} 



/*
    Function: takeTurn
    Imports:  Board(char***), width(int), height(int), ShipList(LinkedList**), MissileList(LinkedList**), winner(int*), destroyed(int*)
    Exports: (void)
    Purpose: Handles a player taking their turn
*/

void takeTurn(char*** Board, int width, int height, LinkedList** ShipList, LinkedList** MissileList, int* winner, int* destroyed)
{
    char** board;
    char input[40];
    int tempInt = 0;
    char* name_m;
    char* detail_m;
    int error = FALSE;
    int count_m;
    int yPos = 0;
    int finished = FALSE;
    funcPtr fptr;
    ListNode* shipIter;
    
    LinkedList* missileList;
    LinkedList* shipList;
    Missile* tempMissile;
    board = *Board;
    missileList = *MissileList;
    shipList = *ShipList;
    
    shipIter = shipList->head;
    
/* ------------------- */
    /* Algorithm */
    /* Step 1: Check if missile present - removeStart(missile)*/
    /* Step 2: Ask user for turn. If help - help, else valid missile coordinate given */
    /* Step 3: We fire the missile at given coordinate */
    /* Step 4: We use checkShip to check for 'X' and replace with 0 where there are ships */

    /* -----------
    if finished == FALSE
            if tempMissile != NULL
                <game>
            if ships are dead -- finished == TRUE and print ships are dead
            if missiles are empty -- finished == TRUE and print missiles empty
        if finished = true, winner= true */


    /* Grabs the next missile from the linked list at each turn */
    tempMissile = removeStart(missileList);
    if(finished == FALSE)
    {
        if(tempMissile != NULL) /* While there are still missiles present*/
        {
            name_m = tempMissile->name;
            count_m = missileList->count;
            do
            {
                /* A prompt outputted to terminal at each turn */
                printf("Missiles left: %d\n", count_m);
                printf("Missile: %s", name_m);
                printf( "\nPlayer take turn (X,Y): \n");
                scanf(" %14s", input);
                spacer();

                /* Converts input to upper-case for easier input handling */
                toUpperStr(input);

                /* If the user requires help */
                while(strcmp(input, "HELP") == 0)
                {
                    detail_m = tempMissile->detail;
                    printf(" %s", detail_m); /* Prints out help message */
                    printf("\nMissile: %s", name_m);
                    printf( "\nPlayer take turn (X,Y): ");
                    scanf(" %14s", input);
                    spacer();
                    toUpperStr(input);
                }  
                error = convertLocation(input, &tempInt, &yPos);
                /* Returns error = TRUE if invalid location. */
            } while((tempInt < 0 || tempInt >= width) || (yPos < 0 || yPos >= height) || error == TRUE);
            
            /* If not help chosen -- valid input -- we can use it  */
            fptr = tempMissile->function; /* Retrieves the appropriate missile function to be fired. */
            fptr(&board,width,height,tempInt,yPos); /* Fires the missile */

            free(tempMissile); /* Heap freeing */
            
            while(shipIter != NULL) /* While there are ships present in its linked list */
            {
                /* Use checkShip to check for tiles where missiles have hit and replaces the 'X' with '0' where there are ships present */
                /* Also checks if ships are fully destroyed */
                checkShip(&board, ((Ship*)shipIter->data)->x,((Ship*)shipIter->data)->y, ((Ship*)shipIter->data)->length, ((Ship*)shipIter->data)->direction,((Ship*)shipIter->data)->name, &(((Ship*)shipIter->data)->dead), destroyed);
                shipIter = shipIter->next; /* Iterates through the ship linked list */
                /* printf("\nDestroyed #: %d\n", *destroyed);  - Commented out - used for debugging purposes. */
            }
            if(*destroyed == shipList->count) /* If all ships are destroyed */ 
            {
                finished = TRUE;
                printf("All ships are dead! \nGame over.");
            }
        }
        else /* If tempMissile = NULL, no more missiles remaining -- end game */
        {
            finished = TRUE;
            printf("Run out of missiles! \nGame over.");

        } 
    }
    if(finished == TRUE) /* If the game is finished, end game */
    {
        *winner = TRUE;
    }
}


/*
    Function: freeData
    Imports:  data (void*)
    Exports: (void)
    Purpose: Cleanup for the game. (Freeing)
*/

void freeData(void* data)
{
   free(data);
}



/*
    Function: singleFunc
    Imports:  Board (char***), width (int), height (int), xPos (int), yPos (int)
    Exports: (void)
    Purpose: Uniquely modifies the game board - hits only a single tile.
*/

void singleFunc(char*** Board, int width, int height, int xPos, int yPos)
{
    char** board;
    board = *Board;
    /* Unique behavior - mark only a single tile */
    board[yPos][xPos] = 'X'; 
}

/*
    Function: splashFunc
    Imports:  Board (char***), width (int), height (int), xPos (int), yPos (int)
    Exports: (void)
    Purpose: Uniquely modifies the game board - hits a 3x3 square.
*/

void splashFunc(char*** Board, int width, int height, int xPos, int yPos)
{
    int ii,jj;
    char** board;
    board = *Board;
    /* Unique behavior - mark a 3x3 square */    
    for(ii=0;ii<3;ii++)
    {
        for(jj=0;jj<3;jj++)
        { /* If statement hits an area centered around the coordinate - only hits within the board's bounds */
            if((yPos + ii-1) >= 0 && (yPos + ii-1) < height && (xPos + jj-1) >= 0 && (xPos + jj-1) < width)
            {
                board[yPos+ii-1][xPos+jj-1] = 'X';
            }
        }
    }
}

/*
    Function: vlineFunc
    Imports:  Board (char***), width (int), height (int), xPos (int), yPos (int)
    Exports: (void)
    Purpose: Uniquely modifies the game board - hits an entire column of tiles */

void vlineFunc(char*** Board, int width, int height, int xPos, int yPos)
{
    char** board;
    int ii;
    board = *Board;
    /* Unique behavior - mark an entire column of tiles */    
    for(ii=0;ii<height;ii++)
    {
        board[ii][xPos] = 'X';
    }
}

/*
    Function: hlineFunc
    Imports:  Board (char***), width (int), height (int), xPos (int), yPos (int)
    Exports: (void)
    Purpose: Uniquely modifies the game board - hits an entire row of tiles */

void hlineFunc(char*** Board, int width, int height, int xPos, int yPos)
{
    int ii;
    char** board;
    board = *Board;
    /* Unique behavior - mark an entire row of tiles */
   for(ii=0;ii<width;ii++)
    {
        board[yPos][ii] = 'X';
    }
}

/*
    Function: checkShip
    Imports: Board (char***) , x(int), y(int), length(int), direction(char), name(char*), dead(int*), destroyed (int*)
    Exports: (void)
    Purpose: Checks for tiles where missiles have hit and replaces the 'X' with '0' where there are ships present.
            Also checks if a ship is destroyed and outputs if so.*/

void checkShip(char*** Board, int x, int y, int length, char direction, char* name, int* dead, int* destroyed)
{
    int ii;
    int hit;
    char** board;
    board = *Board;
    hit = 0;

    /* board[y][x] will be the ship head location
    if head is east, x-ii
    if head is west, x+ii
    if head is north, y+ii
    if head is south, y-ii
    */
    if(direction == 'E')
    {
        for(ii=0;ii<length;ii++)
        {
            if(board[y][x-ii] == 'X')
            {
                board[y][x-ii] = '0';
            }
            #ifdef DEBUG
            if(board[y][x-ii] == '#')
            {
                board[y][x-ii] = 'D';
            }
            #endif 
            if(board[y][x-ii] == '0')
            {
                hit++;
                /* printf("Hit E: %d\n", hit);  
                - Commented out - used for debugging purposes. */
            }
        }
        /* printf("Before Dead: %d \n", *dead); 
        - Commented out - used for debugging purposes. */

        /* If we hit a dead ship -- ignore. If we hit a live ship -- hit. 
        If hit == length, destroyed. */

        if((hit == length) && (*dead == FALSE))
        {
            printf("Ship %s has been destroyed\n", name);
            (*destroyed)++;
            *dead = TRUE;
            /* printf("Dead: %d \n", *dead); 
            - Commented out - used for debugging purposes. */
        }
    }

    if(direction == 'W')
    {
        for(ii=0;ii<length;ii++)
        {
            if(board[y][x+ii] == 'X')
            {
                board[y][x+ii] = '0';
            }
            #ifdef DEBUG
            if(board[y][x+ii] == '#')
            {
                board[y][x+ii] = 'D';
            }
            #endif 
            if(board[y][x+ii] == '0')
            {
                hit++;
                /* printf("Hit W: %d\n", hit);  
                - Commented out - used for debugging purposes. */
            }
        }
        /* printf("Before Dead: %d \n", *dead);  
        - Commented out - used for debugging purposes.  */
        if((hit == length) && (*dead == FALSE)) /* If the hit = length of ship, it's dead */
        {
            printf("Ship %s has been destroyed\n", name);
            (*destroyed)++;
            *dead = TRUE;
            /*  printf("Dead: %d \n", *dead);  
            - Commented out - used for debugging purposes. */
        } 
        /* ->> If the hit != length of ship - it's still alive. <<- */
    }

    if(direction == 'N')
    {
        for(ii=0;ii<length;ii++)
        {
            if(board[y+ii][x] == 'X')
            {
                board[y+ii][x] = '0';
            }
            #ifdef DEBUG
            if(board[y+ii][x] == '#')
            {
                board[y+ii][x] = 'D';
            }
            #endif 

            if(board[y+ii][x] == '0')
            {
                hit++;
                /* printf("Hit N: %d\n", hit);  
                - Commented out - used for debugging purposes. */
            }
        }
        /* printf("Before Dead: %d \n", *dead);  
        - Commented out - used for debugging purposes. */
        if((hit == length) && (*dead == FALSE))
        {
            printf("Ship %s has been destroyed\n", name);
            (*destroyed)++;
            *dead = TRUE;
            /* printf("Dead: %d \n", *dead);  
            - Commented out - used for debugging purposes. */
        }
    }

    if(direction == 'S')
    {
        for(ii=0;ii<length;ii++)
        {
            if(board[y-ii][x] == 'X')
            {
                board[y-ii][x] = '0';
            }
            #ifdef DEBUG
            if(board[y-ii][x] == '#')
            {
                board[y-ii][x] = 'D';
            }
            #endif 
            if(board[y-ii][x] == '0')
            {
                hit++;
                /* printf("Hit S: %d\n", hit);  
                - Commented out - used for debugging purposes. */
            }
        }
        /* printf("Before Dead: %d \n", *dead);  
        - Commented out - used for debugging purposes.  */
        if((hit == length) && (*dead == FALSE))
        {
            printf("Ship %s has been destroyed\n", name);
            (*destroyed)++;
            *dead = TRUE;
            /* printf("Dead: %d \n", *dead);  
            - Commented out - used for debugging purposes. */
        }
    }
        /*  if hit++ equals length (ship) -- destroyed
            if hit == sum of all ships, win
        */
}
    
