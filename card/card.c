#include "card.h"




char* GetCardHolderName()
{
    char* Name = NULL;
    printf("\nEnter your name(as written on the card) :  ");
    Name = validateName();
    return Name;
}

Date GetCardExpiryDate()
{
    Date ExpiryDate;
    printf("\n\nEnter expiration month : ");
    ExpiryDate.month = validateMonth();
    printf("\n\nEnter expiration year(two digits max) : ");
    ExpiryDate.year = validateYear();
    return ExpiryDate;
}

char* GetCardPAN()
{
    char* PAN=NULL;
    printf("\n\nEnter your PAN (16 digits) : ");
    PAN = validatePAN();
    return PAN;
}