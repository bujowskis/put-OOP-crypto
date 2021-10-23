#ifndef WALLET_H
#define WALLET_H


#include <string>
#include <iostream>
#include "abstract/Currency.h"

using namespace std;


class Wallet {
private:
    string* owner;
    Currency* currencies;
    Currency* main_currency;
    float* prob_sell;
    float* prob_buy;

public:
    /*
     * Constructor of Wallet. Parameters:
     * string owner - name of the Wallet's owner
     * Currency* currencies - list of all available currencies
     * Currency* main_currency - currency with exchange_rate = 1; i.e. used as anchor point to buy other currencies with
     *      and to sell other currencies for
     * float prob_sell - probability of selling a coin
     * float prob_buy - probability of buying a coin
     */
    Wallet(string owner, Currency* currencies, Currency* main_currency, float prob_sell, float prob_buy) {
        if (prob_sell <= prob_buy) {
            cout << "\n\tWARNING - trying to run program with prob_sell <= prob_buy\n"
                    "\t\tthat means the program is not necessarily convergent and can run forever\n"
                    "\t\tdo you still want to run it? (y/n)\n\t\t";
            char should_run;
            cin >> should_run;
            while ((should_run != 'n') && (should_run != 'y') && (should_run != 'N') && (should_run != 'Y')) {
                cout << "\nSorry, I didn't understand that. Please use (y/n) answers.\n"
                        "\t\tdo you still want to run it? (y/n)\n\t\t";
                cin >> should_run;
            }
            if ((should_run == 'y') || (should_run == 'Y')) {
                throw "non-convergent";
                return;
            }
        }
        this->owner = new string;
        *(this->owner) = owner;

        // todo - should these two be passed as pointers or objects?
        this->currencies = currencies;
        this->main_currency = main_currency;

        this->prob_sell = new float;
        *(this->prob_sell) = prob_sell;
        this->prob_buy = new float;
        *(this->prob_buy) = prob_buy;
    }

    ~Wallet() {
        delete this->owner;
        delete this->prob_sell;
        delete this->prob_buy;
    }

    /* Invokes trade() for all coins in the wallet */
    void tradeAll() {
        // todo
    }

    /* Lists most important information of all currencies in the wallet */
    void listAll() {
        // todo
    }

    /* Prints detailed information of all currencies in the wallet */
    void toString() {
        // todo
    }

    /* Returns probability of selling a coin */
    float pSell() { return *(this->prob_sell); }

    /* Returns probability of buying a coin */
    float pBuy() { return *(this->prob_buy); }
};


#endif //WALLET_H
