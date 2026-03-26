#ifndef MONEY_H
#define MONEY_H

struct Money {
    int grn;
    short int kop;

    void display();
    void add(Money second_price);
    void multiply(int quantity);
    void round();
    void normalise();
}; 

#endif