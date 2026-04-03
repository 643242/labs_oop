#include <iostream>
#include "money.h"

int main (void)
{
    Money total = {0, 0};
    if (!process_receipt("receipt.txt", total))
    {
        return 1;
    }

    std::cout << "Total price: ";
    display(total);

    std::cout << "Total price (rounded): ";
    round(total);
    display(total);
}