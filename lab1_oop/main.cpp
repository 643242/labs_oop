#include <iostream>
#include <fstream>
#include "money.h"

int main (void)
{
    std::ifstream receipt_txt("receipt.txt");
    if (!receipt_txt.is_open())
    {
        printf("Cannot open file\n");
        return 1;
    }

    int grn;
    short int kop;
    int quantity;

    Money total = {0, 0};

    while (receipt_txt >> grn >> kop >> quantity) 
    {
        Money price;
        price.grn = grn;
        price.kop = kop;

        price.multiply(quantity);
        total.add(price);
    }

    std::cout << "Total price: ";
    total.display();

    std::cout << "Total price (rounded): ";
    total.round();
    total.display();

    receipt_txt.close();
}