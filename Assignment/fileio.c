/*  --------------------------------------------------------------------------
**  Author: Bharath Sukesh
**  Date: 20/4/2020 5:04pm
**  Purpose: Part of the implementation for battleships game 
**  as per UCP assignment specification. This file handles all File IO
**  for reading settings files & validating them as well as creating/saving 
**  custom settings files from user-inputted arguments.
** --------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "macros.h"
#include "linkedlist.h"
#include "game.h"
#include "fileio.h"


/*
    Function: readSettings
    Imports: argv (char**), width (int*), height (int*), ship (Ship*), shipList (LinkedList*)
    Exports: num (int)
    Purpose: Reads in settings files and sets values to width, height if valid.
                If invalid, outputs a specific error message.  
*/

int readSettings(char** argv, int* width, int* height, Ship* ship, LinkedList* shipList)
{
    FILE* file; /* File pointer to the settings file stream */
    int contLoop = TRUE;
    int numRead;  /* Used for fscanf() error-checking */
    /* Temporary values */
    int temp1, temp2;
    int tempX, tempY;
    int num = FALSE;

    /* Temporary values for ship properties - used for validation */
    char  [4];
    char tempDirection;
    int tempLength;
    char tempName[256];
    
    *width = 0;
    *height = 0;
    /* Opens file with a name specified by user in the command line */
    file = fopen(argv[1], "r"); 

    if(file == NULL) /* If file cannot open */
    {
        printf("Error in handling board file - could not open: ");
    }
    else /* File opens successfully */
    {
        numRead = fscanf(file, "%d %d\n", &temp1, &temp2); /* fscanf returns an integer */
        if(numRead != 2)    /* If we don't read in 2 expected values from the fscanf return */
        {
            perror("Error in file formatting (Error Code: x1). \n");
            contLoop =  FALSE;
            num = FALSE;
        }
        /* We read in 2 values as expected, we can now validate them. */
        if(validateBoard(temp1,temp2)) /* If valid, sets the temp values to our actual values */
        {
            *width = temp1;
            *height = temp2;
            num = TRUE;
        } /* Will throw error in validateBoard if not valid */
        else
        {
            contLoop = FALSE;
        }
        while(contLoop)
        {
            numRead = fscanf(file,"%s %c %d", tempLocation, &tempDirection, &tempLength);
            fgets(tempName, 100, file); /* Gets the name (String) */

            /* printf("Width - %d, Height - %d \t", *width, *height); 
                - Commented out - used for debugging purposes. */

            /* Converts input 'A1' to its corresponding board location as two integers */
            convertLocation(tempLocation, &tempX, &tempY); 

            if(numRead != 3) /* If we don't read in 3 expected values from the fscanf return */
            {
                perror("Error in file formatting (Error Code: x2). \n");
                contLoop = FALSE;
                num = FALSE;
            }
            /* If valid, sets the temp values to our actual values */
            else if(validateShip(width, height, tempX, tempY, tempDirection, tempLength, tempName))
            {
                ship = (Ship*)malloc(sizeof(Ship));
                ship->x = tempX;
                ship->y = tempY;
                ship->direction = tempDirection;
                ship->length = tempLength;
                strcpy(ship->name, tempName);
                ship->dead = FALSE;
                insertLast(shipList, ship);
                num = TRUE;
            }
            if(contLoop)
            {
                contLoop = !feof(file); /* Read till EOF if no errors are present */
            }

            if(ferror(file)) /* If an error occurred in opening the file */
            {
                perror("Error in file format : \n");
                num = FALSE; 
            }

            if(num == FALSE)
            {
                freeLinkedList(shipList, &freeData);
                /* freeData is a function pointer that points
                     to a function that knows how to free our ship */
            }
        }
        fclose(file); /* Closes the file */
    }
    return num;

    /* readSettings & readMissiles both return TRUE or FALSE (integer)
    which dictates whether the menu will run or not */
}


/*
    Function: convertLocation
    Imports: tempLocation (char*), tempX (int*), tempY (int*)
    Exports: error (int)
    Purpose: Converts user input 'A1' 
                to its corresponding board location as two integers
*/

int convertLocation(char* tempLocation, int* tempX, int* tempY)
{
    int error = FALSE;
    char upper;
    if(strlen(tempLocation) == 2) /* If valid location input */
    {
        /* Converts to upper-case */
        upper = toUpper(tempLocation[0]); 
        /* Converts both characters to integers */
        *tempX = upper - 65;
        *tempY = atoi(&tempLocation[1])-1; /* -1 for board-use */
    }
    else /* Invalid location */
    {
        error = TRUE;
        printError("Invalid location. \n");
    }
    
    return error;
}

/*
    Function: validateBoard
    Imports: inWidth (int), inHeight (int*)
    Exports: valid (int)
    Purpose: Checks if the board size from the board settings file is valid
*/

int validateBoard(int inWidth, int inHeight)
{
    int valid = TRUE;
    if(inWidth < 1)
    {
        printError("Invalid width - board width must be greater than 0. \n");
        valid = FALSE;
    }
    else if(inHeight < 1)
    {
        printError("Invalid height - board height must be greater than 0. \n");
        valid = FALSE;
    }
    else if(inWidth > 12)
    {
        printError("Invalid width - max board width is 12. \n");
        valid = FALSE;
    }
    else if(inHeight > 12)
    {
        printError("Invalid height - max board height is 12. \n");
        valid = FALSE;
    }
    return valid;
}

/*
    Function: validateBoard
    Imports: inWidth (int), inHeight (int*)
    Exports: valid (int)
    Purpose: Checks if the ship properties from the settings file is valid
    Assertion: Direction must be valid (NSEW in any case) & checks whether
        the ship location is within the bounds of the board width & height.
*/

int validateShip(int *width, int *height, int x, int y, char tempDirection, int tempLength, char* tempName)
{

    int valid = FALSE;
    /* --------------------------------------*/
    
    if(tempDirection == 'W' || tempDirection == 'w')
    {
        if((x + tempLength) < *width)
        {
            valid = TRUE;
        }
    }

    else if(tempDirection == 'E' || tempDirection == 'e')
    {
        if((x - tempLength) > 0)
        {
            valid = TRUE;
        }
    }
    
    else if(tempDirection == 'N' || tempDirection == 'n')
    {
        if((y + tempLength) < *height)
        {
            valid = TRUE;
        }
    }
    else if(tempDirection == 'S' || tempDirection == 's')
    {
        if((y - tempLength) > 0)
        {
            valid = TRUE;
        }
    }
    else 
    {
        valid = FALSE;
    }


    
    if(tempLength <= 0)
    {
        printError("Invalid settings - length out of bounds. Must be a positive number. ");
        valid = FALSE;
    }
    
    
    if (strlen(tempName) > 0)
    {
        valid = TRUE;
    }
    else 
    {
        valid = FALSE;
    }
    
    return valid;
}

/*
    Function: readMissile
    Imports: argv (char**), missileStruct (Missile*), missileList (LinkedList*)
    Exports: error (int)
    Purpose: Reads in missiles settings and sets values to a missile structure valid.
                If all is valid, it stores each missile struct into a linkedlist.
                If invalid, outputs a specific error message.  
*/
int readMissile(char** argv, Missile* missileStruct, LinkedList* missileList)
{
    FILE *file = fopen(argv[2], "r");
    int error = FALSE;
    char* name;
    char description[50];
    struct Missile;
    int ln;
    funcPtr missileFunc;
    if(file == NULL)
    {
        printf("Error in handling missile file - could not open: ");
        error = TRUE;
    }
    else
    {
        while(!feof(file) && (error == FALSE))
        {
            missileStruct = (Missile*)malloc(sizeof(Missile));
            name = (char*)malloc(sizeof(char) * 21);
            fgets(name, 20, file);

            toUpperStr(name);
            
            /* Strip function or ignore if last ch = \n */
            ln = strlen(name) - 1;
            if(name[ln] == '\n')
            {
                name[ln] = '\0';
            }
            if(strlen(name) > 0)
            {   
                /* assignFunc performs error checking for missiles */
                missileFunc = assignFunc(name, &error);
                missileDescription(name, description);
                strcpy(missileStruct->detail, description);
                strcpy(missileStruct->name, name);
                missileStruct->function = missileFunc;
                insertLast(missileList, missileStruct);
                free(name);
                /* printLinkedList(missileList, printString);
                    - Commented out - used for debugging purposes.*/
            }
            else
            { /* Heap freeing when file is empty/all missiles have been read in */
                free(missileStruct); 
                free(name);
            }
        }
        if(ferror(file)) /* If an error occurred in opening the file */
        {
            perror("Error in file format : \n");
            error = TRUE; 
        }

        if(error == TRUE)
        { /* Heap freeing */
            freeLinkedList(missileList, &freeData);
        }
    }
    fclose(file); /* Closes the file */
    return error;
    /* readSettings & readMissiles both return TRUE or FALSE (integer) 
    which dictates whether the menu will run or not */
}


/*
    Function: assignFunc
    Imports: missile (char*), error (int*)
    Exports: result (funcPtr)
    Purpose: Assigns the appropriate function based on 
                what the missile string contains.
                If invalid, it throws an error.
*/


funcPtr assignFunc(char* missile, int* error)
{
    funcPtr result;
    int singleCount, splashCount, vLineCount, hLineCount;
    singleCount = 0;
    splashCount = 0;
    vLineCount = 0;
    hLineCount = 0;
    result = NULL;
    /* Test printf's */
    /* printf("assignFunc %s\n", missile); */
    if(strcmp(missile, "SINGLE") == 0)
    {
        result = singleFunc;
        singleCount++;
    }
    else if(strcmp(missile, "SPLASH") == 0)
    {
        result = splashFunc;
        splashCount++;
    }
    else if(strcmp(missile, "V-LINE") == 0)
    {
        result = vlineFunc;
        vLineCount++;
    }
    else if(strcmp(missile, "H-LINE") == 0)
    {
        result = hlineFunc;
        hLineCount++;
    }
    else
    {
        printf("Invalid missile! Cannot assign function to missile \n");
        *error = TRUE;
    }
    if(singleCount>4 || splashCount>4 || vLineCount>4 || hLineCount>4) /* Restrict to max 4 of any type of missile */
    {
        *error = TRUE;
    }
    return result;
}

/*
    Function: missileDescription
    Imports: missile (char*), description (char*)
    Exports: (void)
    Purpose: Assigns the appropriate description based on 
                what the missile name is.
                If invalid, it throws an error.
*/

void missileDescription(char* missile, char* description)
{
    if(strcmp(missile, "SINGLE") == 0)
    {
        strcpy(description,"Single missile : Hits a single tile.");
    }
    else if(strcmp(missile, "SPLASH") == 0)
    {
        strcpy(description,"Splash : Hits a 3x3 square.");
    }
    else if(strcmp(missile, "V-LINE") == 0)
    {
        strcpy(description,"V-line missile: Hits an entire column (Vertical line).");
    }
    else if(strcmp(missile, "H-LINE") == 0)
    {
        strcpy(description,"H-line : Hits an entire row (Horizontal Line).");
    }
    else
    {
        printf("Invalid missile type! No description set.\n");
    }
}


/* File IO - creating Missile & Board files */

/* Board Format:
<width>,<height>
<location> <direction> <length> <ship name>
<location> <direction> <length> <ship name>
*/


/*
    Function: createBoard
    Imports: (void)
    Exports: (void)
    Purpose: Makes a board settings file based on user-input
                Does not do any validation - all validation
                is handled in readSettings(), however the output
                to terminal indicates what is valid and what is not.
*/
void createBoard()
{
    /* File pointer to the settings file stream */
    FILE* file; 
    int width = 0;
    int height = 0;
    char location[4];
    char direction = ' ';
    char choice = ' ';
    int length = 0;
    char name[256];
    char filename[20];

    /*  File format to be outputted to terminal to give 
        user an indication of what the bounds are for board settings files. */
    char settingsTemp[] = "Board file format:\n<width>,<height>\n<location> <direction> <length> <ship name>\n<location> <direction> <length> <ship name>\n";
    do 
    {
        printf("Please specify a file name: \n");
        scanf("%s", filename);
    } while(strcmp(filename, "") == 0);
    file = fopen(filename, "w"); /* Writing to file */

    if(file == NULL) /* If file cannot be opened */
    {
        printf("Error: could not open file. \n");
    }
    else /* File opened successfully. */
    {
        do /* Series of instructions for making board settings file */
        {
            spacer();
            printf("\n%s", settingsTemp);
            spacer();
            printf("Please enter a number for the width (Min: 1, Max: 12): \n");
            scanf("%d", &width);
            printf("Please enter a number for the height (Min: 1, Max: 12): \n");
            scanf("%d", &height);
            spacer();

            printf("Please enter the board location you would like the place the ship: \n");
            printf("Must be within board size that you specified earlier. \t");
            printf("Width: %d \t", width);
            printf("Height: %d \n", height);
            scanf("%s", location);

            spacer();

            printf("Please enter the direction (n/s/e/w): \n");
            scanf(" %c", &direction);
            
            spacer();

            printf("Please enter a number for the length of the ship (must be within board size): \n");
            scanf("%d", &length);
            
            spacer();
            
            printf("Please enter your ship name (must be non-empty)\n");
            scanf(" %s", name);

            
            fprintf(file,"%d %d", width,height);
            fprintf(file, "\n%s %c %d %s",location,direction,length,name);

            /* If user wishes to enter more than one ship (common). */
            printf("Would you like to enter another ship? \n");
            scanf(" %c", &choice);
            toUpper(choice);
        } while(choice == 'Y'); /* Runs until the user is satisfied with the number of ships entered. */
        
        spacer();

        if(ferror(file)) /* File reading error */
        {
            perror("Error reading from file. \n");
        }
        fclose(file); /* Closes the file */
    }
}


/*
    Function: createMissile
    Imports: (void)
    Exports: (void)
    Purpose: Makes a missiles settings file based on user-input
                Does not do any validation - all validation
                is handled in readMissiles(), however the output
                to terminal indicates what is valid and what is not.
*/

void createMissile()
{
    /* File pointer to the settings file stream */
    FILE* file;
    
    char choice = ' ';
    char name[50];
    char filename[20];

    /*  File format to be outputted to terminal to give 
        user an indication of what the bounds are for missile settings file. */
    char settingsTemp[] = "Missile file format:\n"
                     "<Missile name>\n"
                     "<Missile name>\n"
                     "<Missile name>\n";
    do
    {
        printf("Please specify a file name: \n");
        scanf("%s", filename);
    } while(strcmp(filename, "") == 0);
    file = fopen(filename, "w"); /* Writing to file */

    if(file == NULL)  /* If file cannot be opened */
    {
        printf("Error: could not open file. \n");
    }
    else
    {
        do /* Series of instructions for making missiles settings file */
        {
            spacer();
            printf("\n%s", settingsTemp);
            spacer();

            printf("Please enter the name of the missile you would like to use in the game: \n");
            scanf(" %s", name);

            fprintf(file,"%s", name);
            fprintf(file,"\n");

            /* If user wishes to enter more than one missile (common). */
            printf("Would you like to enter another missile? \n");
            scanf(" %c", &choice);
            
            choice = toUpper(choice);
        } while (choice == 'Y'); /* Runs until the user is satisfied with the number of missiles entered. */
            

        spacer();
        
        if(ferror(file)) /* File reading error */
        {
            perror("Error reading from file. \n");
        }
        fclose(file); /* Closes the file */
    }








}