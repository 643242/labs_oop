#include "money.h"
int main (void) 
{
    if (!process_receipt("receipt.txt"))
    {
        return 1;
    }   
}