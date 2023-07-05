#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#define MAXLENGTH 100
#include "../libraries/libraries.h"
#include "struct.h"


typedef struct CardHolderNode{
    CardHolderInfo data;
    struct CardHolderNode* link;
}CardHolderNode;


int AddNewNode(CardHolderNode**, CardHolderInfo);
void DeallocateLinkedList(CardHolderNode**);


#endif