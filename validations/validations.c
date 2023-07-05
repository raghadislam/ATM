#include "validations.h"
#include "../libraries/libraries.h"
#include "../program//program.h"


// Validate Cardholder Name

char* validateName()
{
    char* Name = NULL;
    bool flag;
    int space;
    do{
        space=0;
        flag=1;
        Name = SetString();
        for(int i=0; i<strlen(Name); ++i)
        {
            if(Name[i]==' ') space++;
            else if(!((Name[i] >= 'a' && Name[i] <= 'z') || (Name[i] >= 'A' && Name[i] <= 'Z'))) { flag = 0; break; }
        }
    } while((!space || !flag) && printf("\nInvalid Name, Please try again..\nEnter your name (as written on the card)\n\n"));
    return Name;
}


// Validate ExpiryDate Month


int validateMonth()
{
    int month ; char* temp;
    do {
        temp = SetString();
        month= StringToInt(temp);
    }while( (month < 1 || month > 12) && printf("\nInvalid, Try again..\nEnter month: ") );
    return month;
}


// Validate ExpiryDate Year


int validateYear()
{
    int year ; char* temp;
    do {
        temp = SetString();
        year= StringToInt(temp);
    }while( strlen(temp)>2 && printf("\nInvalid, Try again..\nEnter year: ") );
    return year;
}


// Validate Card PAN


char* validatePAN()
{
    char* PAN;
    bool check;
    do {
        check = true;
        PAN = Encrypt();
        for (int i = 0; i < strlen(PAN); ++i) if(!(isdigit(PAN[i]))) check=false;
    } while ( (strlen(PAN)!=16 || !check) && printf("\nInvalid PAN, Try again..\nEnter your PAN (16 digit): ") );
    return PAN;
}


// Validation for server choice


int validateServiceChoice()
{
    int choice; char* temp=NULL;
    do{
        temp = SetString();
        choice= StringToInt(temp);
    } while ((choice<1 || choice >6) && printf("\nInvalid, Try again..\nYour choice:   ") );

}


//  Validation for Transaction Amount


int validateTransactionAmount()
{
    int Amount; char* temp; bool flag=true;
    do{
        temp = SetString();
        Amount= StringToInt(temp);
    } while ( Amount==-1 && printf("\nInvalid, Try again..\nEnter Transaction amount:   ") );
    return Amount;

}

int validaChoice()
{
    int choice; char* temp=NULL;
    do{
        temp = SetString();
        choice= StringToInt(temp);
    } while ((choice<1 || choice >2) && printf("\nInvalid, Try again..\nYour choice:   ") );

}