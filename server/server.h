#ifndef SERVER_H
#define SERVER_H
#include "../libraries/libraries.h"
#include "../program/program.h"
#include "../card/card.h"
#include "../terminal/terminal.h"
#include "../linked_list/linked_list.h"
#include "../validations/validations.h"
#include "../filehandling//filehandling.h"


bool CheckAccountPresence(CardHolderNode* , char* , char *);
int UpdateAccountBalance(CardHolderNode* Head, char* MyPAN, int Amount, int choice,char* PAN );
void ChooseServiceType(CardHolderNode*, char* );

char* Deposit(CardHolderNode* Head, char* );
char* Withdraw(CardHolderNode*, char* );
char* Transfer(CardHolderNode* , char*);
void AccountDetails(CardHolderNode* , char* );
void MiniStatement(CardHolderNode*  , char* );





#endif