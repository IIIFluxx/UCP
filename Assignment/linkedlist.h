#ifndef LINKEDLIST_H
#define LINKEDLIST_H


    /* Header guard for functions within file. */

    /* Generic doubly-linked list node */
    typedef struct ListNode
    {
        void* data;
        struct ListNode* next;
        struct ListNode* prev;
    } ListNode;


    /* Double Ended Linked List */
    typedef struct
    {
        ListNode* head;
        ListNode* tail;
        int count;
    } LinkedList;

    /* Function pointer used in printLinkedList() & freeLinkedList()*/
    typedef void (*listFunc)(void*);


    /* Function forward declarations */

    LinkedList* createLinkedList();

    void insertStart(LinkedList*, void*);
    void insertLast(LinkedList*, void*);

    void* removeStart(LinkedList* list);
    void* removeLast(LinkedList* list);

    void printList(LinkedList*,void (*fptr)(void *));
    
    void printLinkedList(LinkedList*, listFunc);
    void freeLinkedList(LinkedList*, listFunc);


#endif