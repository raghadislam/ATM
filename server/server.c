#include "server.h"

// Check presence of the account on the system

bool CheckAccountPresence(CardHolderNode* Head, char* HolderName, char *PAN)
{
    CardHolderNode* ptr = Head;
    while (ptr->link != NULL){
        if(!strcmp(ptr->data.PAN, PAN) && !strcmp(ptr->data.holder_name, HolderName)) return 1;
        ptr=ptr->link;
    }
    return 0;
}


// Update the balance and the mini statement after every transaction


int UpdateAccountBalance(CardHolderNode* Head, char* MyPAN, int Amount, int choice,char* PAN )
{
    CardHolderNode* ptr= Head, *ptr2= Head;
    bool found;
    while (ptr->link != NULL)
    {
        if(!strcmp(ptr->data.PAN,MyPAN)) // 1 2 3
        {
            if(choice == 2)
            {
                ptr->data.balance+=Amount;

                ptr->data.lastThree[2].TransactionDate=ptr->data.lastThree[1].TransactionDate;
                ptr->data.lastThree[2].type=ptr->data.lastThree[1].type;
                ptr->data.lastThree[2].TransactionAmount=ptr->data.lastThree[1].TransactionAmount;

                ptr->data.lastThree[1].TransactionDate=ptr->data.lastThree[0].TransactionDate;
                ptr->data.lastThree[1].type=ptr->data.lastThree[0].type;
                ptr->data.lastThree[1].TransactionAmount=ptr->data.lastThree[0].TransactionAmount;


                ptr->data.lastThree[0].TransactionDate=GetTransactionDate();
                ptr->data.lastThree[0].type="deposit";
                ptr->data.lastThree[0].TransactionAmount= Amount;

            }
            else if(choice == 1)
            {
                ptr->data.balance-=Amount;

                ptr->data.lastThree[2].TransactionDate=ptr->data.lastThree[1].TransactionDate;
                ptr->data.lastThree[2].type=ptr->data.lastThree[1].type;
                ptr->data.lastThree[2].TransactionAmount=ptr->data.lastThree[1].TransactionAmount;

                ptr->data.lastThree[1].TransactionDate=ptr->data.lastThree[0].TransactionDate;
                ptr->data.lastThree[1].type=ptr->data.lastThree[0].type;
                ptr->data.lastThree[1].TransactionAmount=ptr->data.lastThree[0].TransactionAmount;


                ptr->data.lastThree[0].TransactionDate=GetTransactionDate();
                ptr->data.lastThree[0].type="Withdraw";
                ptr->data.lastThree[0].TransactionAmount= Amount;

            }
            else if(choice == 3)
            {
                ptr->data.balance-=Amount;

                ptr->data.lastThree[2].TransactionDate=ptr->data.lastThree[1].TransactionDate;
                ptr->data.lastThree[2].type=ptr->data.lastThree[1].type;
                ptr->data.lastThree[2].TransactionAmount=ptr->data.lastThree[1].TransactionAmount;

                ptr->data.lastThree[1].TransactionDate=ptr->data.lastThree[0].TransactionDate;
                ptr->data.lastThree[1].type=ptr->data.lastThree[0].type;
                ptr->data.lastThree[1].TransactionAmount=ptr->data.lastThree[0].TransactionAmount;


                ptr->data.lastThree[0].TransactionDate=GetTransactionDate();
                ptr->data.lastThree[0].type="Transfer";
                ptr->data.lastThree[0].TransactionAmount= Amount;
                 found = 0;

                while (ptr2->link != NULL)
                {
                    if(!strcmp(ptr2->data.PAN,PAN)) {
                        ptr2->data.balance+=Amount;

                        ptr2->data.lastThree[2].TransactionDate=ptr2->data.lastThree[1].TransactionDate;
                        ptr2->data.lastThree[2].type=ptr2->data.lastThree[1].type;
                        ptr2->data.lastThree[2].TransactionAmount=ptr2->data.lastThree[1].TransactionAmount;

                        ptr2->data.lastThree[1].TransactionDate=ptr2->data.lastThree[0].TransactionDate;
                        ptr2->data.lastThree[1].type=ptr2->data.lastThree[0].type;
                        ptr2->data.lastThree[1].TransactionAmount=ptr2->data.lastThree[0].TransactionAmount;


                        ptr2->data.lastThree[0].TransactionDate=GetTransactionDate();
                        ptr2->data.lastThree[0].type="Transferred to you";
                        ptr2->data.lastThree[0].TransactionAmount= Amount;

                        found = 1;
                    }
                    ptr2= ptr2->link;
                }
            }
        }
        ptr= ptr->link;
    }
    if(choice == 3 && !found) return 0;
    else return 1;
}


// withdraw process


char* Withdraw(CardHolderNode* Head, char* PAN)
{
    int Amount;
    Amount = getTransactionAmount( 1 );
    if(!IsBelowMaxAmount(Amount) || !IsAmountAvailable(Head,PAN,Amount)) return"";
    UpdateAccountBalance(Head,PAN,Amount,1,"");
    printf("\nPlease wait a second..\n\n");
    Sleep(2000);
    return "\n\nWithdrawal Done successfully! Please Take yor cash below\n\n";
}


// Deposit process


char* Deposit(CardHolderNode* Head, char* PAN)
{
    int Amount;
    Amount = getTransactionAmount( 2 );
    if(!IsBelowMaxAmount(Amount)) return"";
    UpdateAccountBalance(Head,PAN,Amount,2,"");
    printf("\nPlease wait a second..\n\n");
    Sleep(2000);
    return "\nDeposition Done successfully!\n";

}


// Transfer process


char* Transfer(CardHolderNode* Head, char* PAN)
{
    int Amount;
    Amount = getTransactionAmount( 3 );
    if(!IsBelowMaxAmount(Amount) || !IsAmountAvailable(Head,PAN,Amount)) return"";
    char* PAN2=NULL;
    printf("\n\nEnter PAN to which cash is Transferred : ");
    PAN2 = validatePAN();
   if ( UpdateAccountBalance(Head,PAN,Amount,3,PAN2)) {
       printf("\nPlease wait a second..\n\n");
       Sleep(2000);
       return "\nTransfer Done successfully!\n";
   }
   else return "\nSorry, the PAN you trying to transfer money to isn't found ";
}


// Printing MiniStatement


void MiniStatement(CardHolderNode* Head, char* PAN)
{
    CardHolderNode* ptr = Head;
    while (ptr->link != NULL){
        if(!strcmp(ptr->data.PAN, PAN)){
            printf("\n\n*-------------------------------- Last Three Transaction --------------------------------*"
                   "\n\nTransaction Amount : %d\tTransaction Date : %d/%d/%d\tTransaction Type : %s"
                   "\n\nTransaction Amount : %d\tTransaction Date : %d/%d/%d\tTransaction Type : %s"
                   "\n\nTransaction Amount : %d\tTransaction Date : %d/%d/%d\tTransaction Type : %s\n",
                   ptr->data.lastThree[0].TransactionAmount, ptr->data.lastThree[0].TransactionDate.day,
                   ptr->data.lastThree[0].TransactionDate.month, ptr->data.lastThree[0].TransactionDate.year,
                   ptr->data.lastThree[0].type,
                   ptr->data.lastThree[1].TransactionAmount, ptr->data.lastThree[1].TransactionDate.day,
                   ptr->data.lastThree[1].TransactionDate.month, ptr->data.lastThree[1].TransactionDate.year,
                   ptr->data.lastThree[1].type,
                   ptr->data.lastThree[2].TransactionAmount, ptr->data.lastThree[2].TransactionDate.day,
                   ptr->data.lastThree[2].TransactionDate.month, ptr->data.lastThree[2].TransactionDate.year,
                   ptr->data.lastThree[2].type);
                break;
        }
    }
}


// Printing AccountDetails


void AccountDetails(CardHolderNode* Head, char* PAN)
{
    CardHolderNode* ptr = Head;
    while (ptr->link != NULL){
        if(!strcmp(ptr->data.PAN, PAN)){
            printf("\n\n*------------------------------------ Account Details -----------------------------------*"
                   "\n\nHolder Name : %s\t\tPAN : %s\n\nExpiration Date : %.2d/%.2d\t\t\tBalance Amount : %d"
                   "\n\n*---------------------------------- Last Three Transaction ----------------------------------*"
                   "\n\nTransaction Amount : %d\tTransaction Date : %d/%.2d/%.2d\tTransaction Type : %s"
                   "\n\nTransaction Amount : %d\tTransaction Date : %d/%.2d/%.2d\tTransaction Type : %s"
                   "\n\nTransaction Amount : %d\tTransaction Date : %d/%.2d/%.2d\tTransaction Type : %s\n",
                   ptr->data.holder_name, ptr->data.PAN, ptr->data.expiration_date.month,ptr->data.expiration_date.year, ptr->data.balance,
                   ptr->data.lastThree[0].TransactionAmount, ptr->data.lastThree[0].TransactionDate.day,
                   ptr->data.lastThree[0].TransactionDate.month, ptr->data.lastThree[0].TransactionDate.year,
                   ptr->data.lastThree[0].type,
                   ptr->data.lastThree[1].TransactionAmount, ptr->data.lastThree[1].TransactionDate.day,
                   ptr->data.lastThree[1].TransactionDate.month, ptr->data.lastThree[1].TransactionDate.year,
                   ptr->data.lastThree[1].type,
                   ptr->data.lastThree[2].TransactionAmount, ptr->data.lastThree[2].TransactionDate.day,
                   ptr->data.lastThree[2].TransactionDate.month, ptr->data.lastThree[2].TransactionDate.year,
                   ptr->data.lastThree[2].type);
            break;
        }
    }
}


// Choose Your Service


void ChooseServiceType(CardHolderNode* Head, char* PAN)
{
    int choice, flag=1;
    while (flag) {
        printf("\nSelect a service: \n\n"
               "1- Withdrawal of cash\t2- Deposit of cash\t\t3- Transfer of cash\n\n4- Mini statement\t5- Account & Balance details\t6- Log out\n\n"
               "Enter your choice number:  ");
        choice = validateServiceChoice();
        switch (choice) {
            case 1 :
                printf("%s",Withdraw(Head, PAN));
                WriteToFile(Head);
                printf("\nPress ENTER to return to home page");
                if(getchar()=='\n') {
                    system("cls");
                    break;
                }
                break;
            case 2 :
                printf("%s",Deposit(Head, PAN));
                WriteToFile(Head);
                printf("\nPress ENTER to return to home page");
                if(getchar()=='\n') {
                    system("cls");
                    break;
                }
            case 3 :
                printf("%s",Transfer(Head, PAN));
                WriteToFile(Head);
                printf("\nPress ENTER to return to home page");
                if(getchar()=='\n') {
                    system("cls");
                    break;
                }
                break;
            case 4 :
                MiniStatement(Head, PAN);
                Sleep(1000);
                printf("\nPress ENTER to return to home page");
                if(getchar()=='\n') {
                    system("cls");
                    break;
                }
            case 5 :
                AccountDetails(Head, PAN);
                printf("\nyou'll be automatically returned to home page in 5 seconds, or just press any key");
                int seconds = 5;
                while (seconds > 0 && !_kbhit()) {
                    Sleep(1000);
                    seconds--;
                }
                if (_kbhit()) {
                    system("cls");
                    break;
                }
                else {
                    system("cls");
                    break;
                }
            case 6 :
                flag = 0;
                break;
        }
    }
}