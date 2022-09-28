#ifndef LINKEDLIST_H
#define LINKEDLIST_H


/* Header guard for functions within file. */

typedef struct ListNode
{
    void* data;
    struct ListNode* next;
    struct ListNode* prev;
} ListNode;

typedef struct LinkedList
{
    ListNode* head;
    ListNode* tail;
    int count;
} LinkedList;

LinkedList* createLinkedList();

void insertStart(LinkedList*, void*);
void insertLast(LinkedList*, void*);

void* removeStart(LinkedList* list);
void* removeLast(LinkedList* list);



/* Function pointer used in freeLinkedList() & printLinkedList() */
typedef void (*listFunc)(void*);

void printLinkedList(LinkedList*, listFunc);

void freeLinkedList(LinkedList*, listFunc);


#endif