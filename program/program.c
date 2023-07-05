#include "program.h"

// Calculate String length


int Strlen(const char* str)
{
    const char* p = str;
    while(*p)
    {
        p++;
    }
    return p-str;
}


// Take string from user


char* SetString(){
    char *str = (char *)calloc(1,sizeof(char));
    int len = 1;
    *str = '\0';
    char ch;
    ch = getchar();
    int cnt = 1;
    while(ch != '\n'){
        if(cnt == len)
        {
            str = (char *)realloc(str, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(str + cnt - 1) = ch;
        *(str + cnt) = '\0';
        cnt++;
        ch = getchar();
    }
    fflush(stdin);
    if(len == 1 ) return SetString();
    return str;
}

// conver string to integer

int StringToInt(char* StringNum){
   // if(Strlen(StringNum) > 10) return -1;
    int num = 0;
    for(int i = 0; i < strlen(StringNum); i++)
    {
        if(!isdigit(StringNum[i])) return -1;
        num *= 10;
        num += StringNum[i] - '0';
    }
    return num;
}

// take PAN from User

char* Encrypt()
{

    char *password = NULL, ch ;
    password = (char *)malloc(100 * sizeof(char));

    int cnt = 0;

    while((ch = (char)getch()) != 13 ){
        if(cnt < 0) cnt = 0;
        if(ch == 8 && cnt){
            putch('\b');
            putch('\0');
            putch('\b');
            cnt--;
            continue;
        }
        if(ch == 8 && cnt == 0) continue;
        password[cnt++] = ch;
        putch('*');
    }
    password[cnt] = '\0';

    return password;
}