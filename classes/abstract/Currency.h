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
    float* amount;
    float* exchange_rate;

public:
    /*
     * Constructor of Currency. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     */
    Currency(string name, char symbol, float amount, float exchange_rate) {
        this->name = new string;
        *(this->name) = name;
        this->symbol = new char;
        *(this->symbol) = symbol;
        if (amount <= 0)
            throw invalid_argument("initial amount must be greater than 0");
        this->amount = new float;
        *(this->amount) = amount;
        this->exchange_rate = new float;
        *(this->exchange_rate) = exchange_rate;
    }

    virtual ~Currency() {
        delete this->name;
        delete this->symbol;
        delete this->amount;
        delete this->exchange_rate;
    }

    /* Trades all coins, i.e. iterates over all coins and decides whether to buy, sell or do nothing with each one,
     * based on probabilities defined in Wallet */
    void trade() {
        // todo
    }

    /* Lists the most important info about this currency */
    void list() {
        // todo
    }

    virtual void toString() = 0; // this is up to children

    // setters/getters
    string getName() { return *(this->name); }
    char getSymbol() { return *(this->symbol); }
    float getAmount() { return *(this->amount); }
    float getExchangeRate() { return *(this->exchange_rate); }
};


#endif //CURRENCY_H
