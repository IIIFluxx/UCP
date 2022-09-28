#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"
#include "functions.h"


/* We insert our file contents into a House struct and then store in LL. */
LinkedList* readFile(char* filename)
{
    FILE* file;
    /* Values to assign to struct */
    int bedCount;
    int bathCount;
    int priceAmt;
    char address[101]; 
    LinkedList* houseList;
   
    struct House;
    House* houseStruct;

    file = fopen(filename, "r");

    if(file == NULL) /* If file cannot open */
    {
        printf("Error in handling board file - could not open: ");
    }
    else
    {
        houseList = createLinkedList();
        while(!feof(file))
        {
            /* Read the file line by line. */
            /* File IO format:
            <bedroom count>,<bathroom count>, <price>, <address> */
            fscanf(file,"%d,%d,%d,%[^\n]", &bedCount,&bathCount, &priceAmt, address);

            houseStruct = (House*)malloc(sizeof(House));
            houseStruct->bedroomCount = bedCount;
            houseStruct->bathroomCount = bathCount;
            houseStruct->price = priceAmt;
            strcpy(houseStruct->address, address);
            /* Struct has been formed, now insert into a houseList */
            insertLast(houseList,houseStruct);
        }
        /* printLinkedList(houseList,printString); */
        fclose(file);
    } /* Finished with reading */

    return houseList;
}

/* File IO format:
        <bedroom count>,<bathroom count>, <price>, <address> */
void writeFile(LinkedList* list, char* filename)
{
    FILE* file;
    int bedCount = 0;
    int bathCount = 0;
    int priceAmt = 0;
    /* char theAddress[101]; */

    House* houseStruct;
    ListNode* currNode;
    currNode = list->head;
    

    file = fopen(filename, "w"); /* Writing to file */
    if(file == NULL) /* If file cannot be opened */
    {
        printf("Error: could not open file. \n");
    }
    else
    {
        while(currNode != NULL)
        {
            houseStruct = (House*)currNode->data;
            houseStruct->bathroomCount = bathCount;
            houseStruct->bedroomCount = bedCount;
            houseStruct->price = priceAmt;
            /* strcpy(houseStruct->address, theAddress); */
            /* fprintf(file,"%d,%d,%d, %s", bedCount,bathCount, priceAmt, theAddress); */
            fprintf(file,"%d,%d,%d, %s", houseStruct->bedroomCount,houseStruct->bathroomCount, houseStruct->price, houseStruct->address);
            fprintf(file,"\n"); /* <------ ? */ 
            currNode = currNode -> next;    
        }        
        if(ferror(file)) /* File reading error */
        {
            perror("Error reading from file. \n");
        }
        fclose(file); /* Closes the file */
    }
    /* Check if fprintf needs to be outside else  <---- */

}

/* Flash sale - loop thru all houses, list->price = (list->price >> 1) */
void flashSale(LinkedList* list)
{
    ListNode* curr;
    House* houseIter;
    curr = list->head;

    while(curr != NULL)
    {
        houseIter = (House*)curr->data;
        houseIter->price = (houseIter->price >> 1);
        /* printf("%d\n", houseIter->price); */
        curr = curr -> next;
    }
    printf("Amounts have been halved :) \n");
}




LinkedList* filterByPrice(LinkedList* list, int inPrice)
{
    /* Filter LL 
    Where PRICE IS LESS THAN OR EQUAL TO IMPORTED PRICE */
    LinkedList* filteredList = createLinkedList();
    ListNode* currHouse;
    House* houseStruct;

  /*   houseStruct = (House*)malloc(sizeof(House)); */

    printf("%d\n", inPrice);
    currHouse = list->head;
    while(currHouse != NULL)
    {
        houseStruct = (House*)currHouse->data;

        /* Check for filter */
        /* printf("HSP: %d \n", houseStruct->price); */
        if(inPrice <= houseStruct->price) /* IF LESS THAN OR EQUAL, ADD TO LIST */
        {
            /* printf("inside\n"); */
            insertLast(filteredList,houseStruct);
        }
        currHouse = currHouse -> next;
    }
    return filteredList;
    /* filteredList must ONLY contain matching properties */
}


LinkedList* filterBySuburb(LinkedList* list, char* suburb)
{
    /* Check if uppercase, copy the uppcase parts to upper. Use suburb as needed. */
    ListNode* currHouse;
    House* houseStruct;
    const char ch = ' ';
    LinkedList* filteredList = createLinkedList();
    char* upper;
    

    currHouse = list->head;
    
    while(currHouse != NULL)
    {
        houseStruct = (House*)currHouse->data;
        upper = strrchr(houseStruct->address, ch);
        if(strcmp(upper, suburb) == 0)
        {
            insertLast(filteredList,houseStruct);
        }
        currHouse = currHouse -> next;
    }
    
    return filteredList;

}



/* ---------------------------- */
/* USE IF NOTHING IN STRUCT TO FREE e.g. dont need to item->name, only the struct itself */
void func(void* data)
{
   free(data);
}


/* ---------------------------- */
/* USE IF NEEDING TO FREE PARTICULAR STRUCT e.g. item->name */

void freeHouse(void* data)
{
    House* house = (House*)data;
    /* We have an item and its contents now */
    /* We can free its contents before freeing the actual struct itself */
   /*  e.g. free(item->name); */
   /*  free(item->fieldThatHasBeenMallocd); */
   free(house);
}




    

void printString(void* data)
{
   char* str = (char*)data;
   printf("  %s\n", str);
}


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