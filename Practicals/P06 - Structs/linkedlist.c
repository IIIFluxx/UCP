#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

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

        list->head = list->head->next; /* Updates the head to head->next "Unplugs the current head and plugs it into the next node" */
        list->head->prev = NULL; /* Makes 'prev' null - cuts ties with previous node */
        free(removed);
    }
    list->count--;
    return nodeValue;
}



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

void printLinkedList(LinkedList* list, listFunc toString)
{
    ListNode* curr;
    
    if(list->count == 0)
    {
        printf("Linked List is empty. \n");
    }
    else
    {
        curr = list->head;
        printf( "[" );
        while(curr->next != NULL) /* Behaves like an iterator */
        {
            if( curr->next == NULL ) /* If last node */
            {
                printf(" %s ]\n", (char*)(curr->data));
            }
            else
            {
                 printf("%s,",(char*)curr->data);
                 curr = curr->next;
            }
        }
        printf("\n");
    }


}

void freeLinkedList(LinkedList* list, listFunc freeVal)
{
    ListNode* currNd;
    ListNode* nextNd;

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

/* 
    - Convert Q1 to LL


*/