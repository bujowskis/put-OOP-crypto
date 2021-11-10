#ifndef CURRENCY_H
#define CURRENCY_H


#include <string>
#include <iostream>
#include <stdexcept>
#include <random>
#include <time.h>
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

    /* Lists the most important info about this currency */
    void list() {
        cout << "\t" << this->getName() << " (" << this->getSymbol() << ")\n" <<
        "\t\t" << this->getAmount() << " coins, 1 coin = " << this->getExchangeRate() << "\n";
    }

    virtual void toString() = 0; // this is up to children

    // setters/getters
    string getName() { return *(this->name); }
    char getSymbol() { return *(this->symbol); }
    float getAmount() { return *(this->amount); }
    float getExchangeRate() { return *(this->exchange_rate); }

    /*
     * Adds given amount to the Currency's amount.
     * - adding negative amount works like subtraction
     * - throws invalid_argument if the resulting amount will be negative
     */
    void addAmount(int amount) {
        if (this->getAmount() + amount < 0)
            throw invalid_argument("resulting amount will be negative\n");
        *(this->amount) += amount;
    }

    /*
     * Subtracts given amount to the Currency's amount.
     * - subtracting negative amount works like addition
     * - throws invalid_argument if the resulting amount will be negative
     */
    void subAmount(int amount) {
        if (this->getAmount() - amount < 0)
            throw invalid_argument("resulting amount will be negative\n");
        *(this->amount) -= amount;
    }

    /*
     * Simulates exchange rate change by multiplying current exchange rate by amount from range (0.25-4.0).
     * - numbers in the middle of the range occur more often than on the outside of the range
     */
    void simExchange() {
        int which_range = rand() % 10;
        if (which_range < 1) {
            // 0 -> 0.25-0.50
            *(this->exchange_rate) *= (float) ((rand() % 26) + 25) / 100;
        } else if (which_range < 3) {
            // 1-2 -> 0.51-0.75
            *(this->exchange_rate) *= (float) ((rand() % 25) + 51) / 100;
        } else if (which_range < 5) {
            // 3-4 -> 0.76-1.00
            *(this->exchange_rate) *= (float) ((rand() % 25) + 76) / 100;
        } else if (which_range < 7) {
            // 5-6 -> 1.01-2.00
            *(this->exchange_rate) *= (float) ((rand() % 100) + 101) / 100;
        } else if (which_range < 9) {
            // 7-8 -> 2.01-3.00
            *(this->exchange_rate) *= (float) ((rand() % 100) + 201) / 100;
        } else {
            // 9 -> 3.01-4.00
            *(this->exchange_rate) *= (float) ((rand() % 100) + 301) / 100;
        }
    }
};


#endif //CURRENCY_H
