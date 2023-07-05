#include "terminal.h"
#define MAX_AMOUNT 5000

Date GetTransactionDate()
{
    Date TransactionDate;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    TransactionDate.year=tm.tm_year -100;
    TransactionDate.month=tm.tm_mon + 1;
    TransactionDate.day=tm.tm_mday;
    return TransactionDate;
}

bool IsCardExpired()
{
    Date currentDate = GetTransactionDate();
    Date CardDate    = GetCardExpiryDate();
    if( (currentDate.month <= CardDate.month && currentDate.year <= CardDate.year)  || currentDate.year < CardDate.year)  return true;
    else return false;
}

int getTransactionAmount(int choice )
{
    int Amount ;
    switch (choice) {
        case 1: printf("\nEnter the withdrawal amount : "); break;
        case 2: printf("\nEnter the deposit amount : "   ); break;
        case 3: printf("\nEnter the transfer amount : "  ); break;
    }
    Amount = validateTransactionAmount();
    return Amount;
}

bool IsBelowMaxAmount(int Amount)
{
    if(Amount>MAX_AMOUNT)
    {
        printf("\n\nAmount Exceeded!\n\n");
        return false;
    }
    else return true;
}

bool IsAmountAvailable(CardHolderNode* Head, char* PAN, int Amount)
{
    CardHolderNode* ptr = Head;
    while (ptr->link!=NULL)
    {
        if(!strcmp(ptr->data.PAN,PAN))
        {
            if(ptr->data.balance >= Amount) return true;
            else {
                printf("\n\nAmount not Available\n\n");
                return false;
            }
        }
        ptr= ptr->link;
    }
}


