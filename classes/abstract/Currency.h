#ifndef CURRENCY_H
#define CURRENCY_H


#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
// todo - ask lecturer if it's fine to add assignment pdf into repo

class Currency {
private:
    string* name;
    char* symbol;
    int* amount;
    float* exchange_rate;

public:
    void trade();
    void list();
    virtual void toString() = 0; // this is up to children

    // setters/getters
    string getName() { return *(this->name); }
    char getSymbol() { return *(this->symbol); }
    int getAmount() { return *(this->amount); }
    float getExchangeRate() { return *(this->exchange_rate); }
};


#endif //CURRENCY_H
