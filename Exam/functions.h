#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define FALSE 0
#define TRUE 1

#include "linkedlist.h"




/* Header guard for functions within file. */



	
    /* House struct */
    typedef struct {
        char address[101]; 
        int bedroomCount;
        int bathroomCount;
        int price;
    }House;
    
/* ------------------------------- */
/* ------------------------------- */
/* ------------------------------- */


LinkedList* readFile(char* argv);
void writeFile(LinkedList* list, char* filename);

LinkedList* filterByPrice(LinkedList* list, int price);
LinkedList* filterBySuburb(LinkedList* list, char* suburb);

void flashSale(LinkedList* list);


void func(void* data);
void freeHouse(void* data);
void printString(void* data);



#endif
