#include "filehandling.h"



void ReadFromFile(CardHolderNode** Head)
{
    FILE* file= fopen("DataBase.txt","r");
    if(file== NULL)
    {
        printf("unable to open file\n"); //
        exit(1);
    }

    CardHolderNode* current = (CardHolderNode*)malloc(sizeof(CardHolderNode));
    do{
        current->data.holder_name =       malloc(MAXLENGTH*sizeof(char) );
        current->data.PAN  =       malloc(MAXLENGTH*sizeof(char) );
        current->data.lastThree[0].type = malloc(MAXLENGTH*sizeof(char) );
        current->data.lastThree[1].type = malloc(MAXLENGTH*sizeof(char) );
        current->data.lastThree[2].type = malloc(MAXLENGTH*sizeof(char) );


    }while(fscanf(file,"%100[^,], %d/%d, %d, %16[^,], %d, %d/%d/%d, %100[^,], %d, %d/%d/%d, %100[^,], %d, %d/%d/%d, %100[^,],\n", current->data.holder_name,
                  &current->data.expiration_date.month,            &current->data.expiration_date.year, &current->data.balance, current->data.PAN,
                  &current->data.lastThree[0].TransactionAmount,   &current->data.lastThree[0].TransactionDate.day,&current->data.lastThree[0].TransactionDate.month,
                  &current->data.lastThree[0].TransactionDate.year, current->data.lastThree[0].type,
                  &current->data.lastThree[1].TransactionAmount,   &current->data.lastThree[1].TransactionDate.day,&current->data.lastThree[1].TransactionDate.month,
                  &current->data.lastThree[1].TransactionDate.year, current->data.lastThree[1].type,
                  &current->data.lastThree[2].TransactionAmount,   &current->data.lastThree[2].TransactionDate.day,&current->data.lastThree[2].TransactionDate.month,
                  &current->data.lastThree[2].TransactionDate.year, current->data.lastThree[2].type) > 0 && AddNewNode(Head,current->data));
    fclose(file);
    free(current);
}

void WriteToFile(CardHolderNode* ptr)
{
    FILE* file= fopen("DataBase.txt","w");

    if(file== NULL) printf("unable to open file\n");

    CardHolderNode* current = ptr;
    while(current!= NULL)
    {
        fprintf(file,"%s, %d/%d, %d, %s, %d, %.2d/%.2d/%.2d, %s, %d, %.2d/%.2d/%.2d, %s, %d, %.2d/%.2d/%.2d, %s,\n", current->data.holder_name,
                current->data.expiration_date.month,             current->data.expiration_date.year, current->data.balance, current->data.PAN,
                current->data.lastThree[0].TransactionAmount,    current->data.lastThree[0].TransactionDate.day,current->data.lastThree[0].TransactionDate.month,
                current->data.lastThree[0].TransactionDate.year, current->data.lastThree[0].type,
                current->data.lastThree[1].TransactionAmount,    current->data.lastThree[1].TransactionDate.day,current->data.lastThree[1].TransactionDate.month,
                current->data.lastThree[1].TransactionDate.year, current->data.lastThree[1].type,
                current->data.lastThree[2].TransactionAmount,    current->data.lastThree[2].TransactionDate.day,current->data.lastThree[2].TransactionDate.month,
                current->data.lastThree[2].TransactionDate.year, current->data.lastThree[2].type);
        current = current->link;
    }
    fclose(file);
    free(current);
}