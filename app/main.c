#include "../libraries/libraries.h"
#include "../filehandling/filehandling.h"
#include "../card/card.h"
#include "../terminal/terminal.h"
#include "../app/app.h"




int main()
{
        CardHolderNode* Head = NULL;
        ReadFromFile(&Head);
        StartApp(Head);
        WriteToFile(Head);
        DeallocateLinkedList(&Head);

    return 0;
}