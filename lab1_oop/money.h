#ifndef MONEY_H
#define MONEY_H

struct Money {
    int grn;
    short int kop;
}; 

void display(const Money& price);
void add(Money& first_price, const Money& second_price);
void multiply(Money& price, int quantity);
void round(Money& price);
void normalise(Money& price);
bool process_receipt(const char* filename, Money& total);

#endif