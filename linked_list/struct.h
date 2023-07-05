#ifndef STRUCT_H
#define STRUCT_H

typedef struct Date{
    int day;
    int month;
    int year;
}Date;

typedef struct Transactions{
    int TransactionAmount;
    Date TransactionDate;
    char* type;
}Transactions;

typedef struct CardHolderInfo{
    char* holder_name;
    Date expiration_date;
    char* PAN;
    int balance;
    Transactions lastThree[3];
}CardHolderInfo;

#endif