#include "app.h"
#include "../card/card.h"
#include "../terminal/terminal.h"
#include "../server/server.h"

void StartApp(CardHolderNode* Head){
    printf("\n*------------------------------------ Welcome! ------------------------------------*\n ");
    char* HolderName = GetCardHolderName();
    char *PAN;
    bool check1=1, check2=1;
    int choice;
    while(check1 || check2) {
        check1=1, check2=1;
         PAN = GetCardPAN();
        if (!CheckAccountPresence(Head, HolderName, PAN)) {
            printf("\n\nInvalid Account. \n\n");
            printf("\n1- try Again\t\t\t2- quit\t\t");

            choice = validaChoice();
            if(choice==2)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                continue;
            }
        }
        else check1=0;

        if (!IsCardExpired()) {
            printf("\n\nThe Card has expired.\n\n");
            printf("\n1- try Again\t\t\t2- quit\t\t");

            choice = validaChoice();
            if(choice==2)
            {
                system("cls");
                return;
            }
            else
            {
                system("cls");
                continue;
            }

        }
        else check2=0;
    }
    ChooseServiceType(Head,PAN);


}