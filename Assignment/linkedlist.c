/*  --------------------------------------------------------------------------
**  Author: Bharath Sukesh
**  Date: 20/4/2020 4:21pm
**  Purpose: Implementation of a generic doubly-linked,double ended linked list.
**  An older variant of this code was completed for UCP worksheet 06 based on code 
**  provided in Lecture 06. 
** --------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


/*
    Function: createLinkedList
    Imports: (void)
    Exports: list (LinkedList*)
    Purpose: To create and export a empty linked list. 
*/
LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

/*
    Function: insertStart
    Imports: list (LinkedList*), inValue (void*)
    Exports: (void)
    Purpose: Inserts a generic node at the start of the linked list with the imported value
*/

void insertStart(LinkedList* list, void* inValue)
{
    ListNode* newNd = (ListNode*)malloc(sizeof(ListNode));

    newNd->data = inValue;
    
    if(list->head == NULL)
    {
        list->head = newNd;
        list->tail = newNd;
        list->tail->next = NULL;
        list->tail->prev = NULL;
        list->head->next = NULL;
        list->head->prev = NULL;
    }
    else
    {
        /* Assign the *next* of newNd to equal the current head of the list -- newNd now points to the current head */
        newNd-> next = list->head;

        /* Set the head's previous node to be newnode */
        list->head->prev = newNd;

        /* Make the previous head become null (no longer the head)**/
        newNd->prev = NULL;
        
        /* Update the head of the list */
        list->head = newNd;
    }
    list->count++;
}

/*
    Function: removeStart
    Imports: list (LinkedList*)
    Exports: nodeValue (void*)
    Purpose: Removes the first node from the linked list and returns its value
*/

void* removeStart(LinkedList* list)
{
    /*This function should take a pointer to an existing
    linked list, remove the first element from the list and return a pointer to it. (Return NULL
    instead if the list is empty.) */

    void* nodeValue = NULL; /* Return value */
    ListNode* removed = NULL; /* Copy of head that is removed (for freeing) */ 
    if (list->count == 0) 
    {
        nodeValue = NULL;
        printf("Linked list is empty. \n");
    }
    else 
    {
        nodeValue = (list->head)->data; /* = data at head of list */
        removed = list->head; /* we want to remove the head of the list -- temporary variable 'removed' points to the node we want to delete */

        if(list->head->next != NULL)
        {
            list->head = list->head->next; /* Updates the head to head->next "Unplugs the current head and plugs it into the next node" */
            list->head->prev = NULL; /* Makes 'prev' null - cuts ties with previous node */
        }
        else
        {
            list->head = NULL;
        }
        free(removed);
    }
    list->count--;
    return nodeValue;
}


/*
    Function: insertLast
    Imports: list (LinkedList*), inValue (void*)
    Exports: (void)
    Purpose: Inserts a generic node at the end of the linked list with the imported value
*/

void insertLast(LinkedList* list, void* inValue)
{
    ListNode* newNd = (ListNode*)malloc(sizeof(ListNode));
    newNd->data = inValue;
    newNd->next = NULL;
    newNd->prev = NULL;
    
    if(list->head == NULL)
    {
        list->head = newNd;
        list->tail = newNd;
    }
    else
    {
        /* Make the 'next' of the tail-node equal newNd. */
        list->tail->next = newNd;
        /* Assign the *prev* of newNd to equal the current tail of the list */
        newNd -> prev = list->tail;
         /* Set newNd's 'next' to be null */
        newNd->next = NULL;
        /* Set the list's tail to equal newNd */
        list->tail = newNd;
    }
    list->count++;
}

/*
    Function: removeLast
    Imports: list (LinkedList*)
    Exports: nodeValue (void*)
    Purpose: Removes the last node from the linked list and returns its value
*/

void* removeLast(LinkedList* list)
{
    void* nodeValue = NULL; /* Return value */
    ListNode* removed = NULL; /* Copy of tail that is removed (for freeing) */
    if(list->count == 0)
    {
        nodeValue = NULL;
        printf("Linked list is empty. \n");
    }
    else
    {
        nodeValue = (list->tail)->data; /* data at tail of list */
        removed = list->tail; /* we want to remove the tail of the list -- temporary var 'removed' points to the node we want to delete */

        list -> tail = (list->tail)->prev; /* Updates the tail to tail -> prev */
        list->tail->next = NULL; /* Makes 'next' null - cuts ties with next node */
        free(removed);
    }
    list->count--;

    return nodeValue;
}

/*
    Function: printLinkedList
    Imports: list (LinkedList*), toString (toStringFunc*)
    Exports: (void)
    Purpose: Prints the contents of the linked list using the imported toString.
*/

void printLinkedList(LinkedList* list, listFunc toString)
{
    ListNode* curr;
    
    /* if(list->count == 0)
    {
        printf("Linked List is empty. \n"); Commented out - was used for debugging purposes.
    } 
    else
    {*/

    curr = list->head;
    printf( "[" );
    while(curr != NULL) /* Behaves like an iterator */
    {
        if( curr->next == NULL ) /* If last node */
        {
            printf(" %s ]\n", (char*)(curr->data));
        }
        else /* Prints out the contents/each element */
        {
                printf("%s,",(char*)curr->data);
                
        }
        curr = curr->next; /* Iterates to the next element */
    }
    printf("\n");
}


/*
    Function: freeLinkedList
    Imports: list (LinkedList*), freeVal (listFunc*)
    Exports: (void)
    Purpose: To free all memory occupied by the linked list.
*/

void freeLinkedList(LinkedList* list, listFunc freeVal)
{
    ListNode* currNd; /* Pivot current node to free */
    ListNode* nextNd; /* The node adjacent to currNd - next in line to free */

    if(list->count > 0)
    {
        currNd = list->head;
        while(currNd != NULL)
        {
            nextNd = currNd->next;
            (*freeVal)(currNd->data);
            free(currNd);
            currNd = nextNd;
        }
    }
    free(list);
}
