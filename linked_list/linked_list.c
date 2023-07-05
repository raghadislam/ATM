#include "linked_list.h"

// Add New Node in Linked List


int AddNewNode(CardHolderNode** Head,CardHolderInfo Data)
{
    CardHolderNode* ptr   =(CardHolderNode*)malloc(sizeof(CardHolderNode));
    CardHolderNode* current = *Head;
    if(ptr==NULL)
    {
        exit(1);
    }

    ptr->link=NULL;
    ptr->data = Data;
    if(*Head == NULL)
    {
        *Head = ptr;
        return 1;
    }
    while(current->link != NULL)
    {
        current = current->link;
    }
    current->link = ptr;
    return 1;
}


// Clear All Nodes


void DeallocateLinkedList(CardHolderNode** Head)
{
    CardHolderNode * ptr = *Head;
    while (ptr != NULL) {
        CardHolderNode * ptr2 = ptr;
        ptr = ptr->link;
        free(ptr2);
    }
    *Head = NULL;
}