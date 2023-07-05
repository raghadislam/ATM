#ifndef TERMINAl_H
#define TERMINAl_H
#include "../libraries/libraries.h"
#include "../program/program.h"
#include "../linked_list/linked_list.h"
#include "../card/card.h"


Date GetTransactionDate();
bool IsCardExpired();
bool IsBelowMaxAmount(int);
int getTransactionAmount(int);
bool IsAmountAvailable(CardHolderNode* , char* , int );



#endif