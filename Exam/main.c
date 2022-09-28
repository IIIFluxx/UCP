#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include "linkedlist.h"



int main(int argc, char* argv[])
{
    int price;
    int menuChoice; 
	LinkedList* list;    
    LinkedList* filteredList;

    

    /* char suburb[100]; */

    /* ListNode* currNode; */
    

    char menuStr[] = "<1> - filterByPrice.\n"
                     "<2> - filterBySuburb.\n"
                     "Please choose an option: ";
    price = 5;
    srand(time(NULL));
    
    list = readFile(argv[1]);
    
    /* printLinkedList(list,printString); */

    /* currNode = list -> head;
    printf("Printing\n");
    while(currNode != NULL)
    {
        printf("%s\n", (char*)currNode->data);
        currNode = currNode->next;
    } */
    printf("\n");

    printf("\n%s", menuStr);
    scanf("%d", &menuChoice);

    switch(menuChoice)
    {
        case 1:
            filteredList = filterByPrice(list,price);
            break;

        case 2:
        /* Method causes memory issues, but code is written. */
        
            /* filteredList = filterBySuburb(list,suburb); */
            break;

        default:
            printf("Invalid input. \n");
            break;
    }

    /* ---------- */
    
    
    

    
    if (rand() % 4 == 0) 
    {
        printf("Running flash sale! \n");
        flashSale(list);
    }

    

    /* --------- */

    writeFile(list,"test.txt"); 

    freeLinkedList(list, &freeHouse);
    if(menuChoice == 1)
    {
        free(filteredList);
    }
    printf("=========EOF=========\n\n");

    return 0;
}


