#include <iostream>
#include "money.h"

void Money::normalise() 
{
    if (kop >= 100) 
    {
        grn += kop / 100;
        kop %= 100;
    }
}

void Money::display()
{
    std::cout << grn << " grn " << kop << " kop " << std::endl;
}

void Money::add(Money second_price)
{
    grn += second_price.grn;
    kop += second_price.kop;
    normalise();
}

void Money::multiply(int quantity)
{
    grn *= quantity;
    kop *= quantity;

    normalise();
}

void Money::round()
{
    int last_digit = kop % 10;
    if (last_digit >= 5)
    {
        kop = ((kop / 10) + 1) * 10;
    } else 
    {
        kop = (kop / 10) * 10;
    }

    normalise();
}


