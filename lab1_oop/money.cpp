#include <iostream>
#include "money.h"
#include <fstream>
 
void normalise(Money& price) 
{
    if (price.kop >= 100) 
    {
        price.grn += price.kop / 100;
        price.kop %= 100;
    }
}

void display(const Money& price)
{
    std::cout << price.grn << " grn " << price.kop << " kop " << std::endl;
}

void add(Money& first_price, const Money& second_price)
{
    first_price.grn += second_price.grn;
    first_price.kop += second_price.kop;
    normalise(first_price);
}

void multiply(Money& price, int quantity)
{
    price.grn *= quantity;
    price.kop *= quantity;

    normalise(price);
}

void round(Money& price)
{
    int last_digit = price.kop % 10;
    if (last_digit >= 5)
    {
        price.kop = ((price.kop / 10) + 1) * 10;
    } else 
    {
        price.kop = (price.kop / 10) * 10;
    }

    normalise(price);
}

bool process_receipt(const char* filename)
{
    Money total = {0, 0};
    std::ifstream receipt_txt(filename);
    if (!receipt_txt.is_open())
    {
        printf("Cannot open file\n");
        return false;
    }

    int grn;
    short int kop;
    int quantity;
    std::string name;

    while (receipt_txt >> name >> grn >> kop >> quantity) 
    {
        Money price = {grn, kop};
        multiply(price, quantity);
        add(total, price);
    }

    std::cout << "Total price: ";
    display(total);

    std::cout << "Total price (rounded): ";
    round(total);
    display(total);

    return true;
}