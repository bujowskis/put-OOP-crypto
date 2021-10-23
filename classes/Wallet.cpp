#include "Wallet.h"


/*
 * Constructor of Wallet. Parameters:
 * string owner - name of the Wallet's owner
 * Currency* currencies - list of all available currencies
 * Currency* main_currency - currency with exchange_rate = 1; i.e. used as anchor point to buy other currencies with
 *      and to sell other currencies for
 * float prob_sell
 */
// todo - what's "noexcept" here for?
Wallet::Wallet(string owner, Currency* currencies, Currency* main_currency, float prob_sell, float prob_buy) {
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
            // todo - is that correct way to do this?
            throw "non-convergent";
            return;
        }
    }
    this->owner = new string owner; // todo - check if it works like this
    this->currencies = currencies;
    this->main_currency = main_currency;
    this->prob_sell = new float prob_sell;
    this->prob_buy = new float prob_buy;
}

Wallet::~Wallet() {
    delete this->owner;
    delete this->prob_sell;
    delete this->prob_buy;
}

/* Iterates over all currencies in the wallet, invoking currency.trade() */
void Wallet::tradeAll() {
    // todo
}

/* Lists most important information of all currencies in the wallet */
void Wallet::listAll() {
    // todo
}

/* Prints detailed information of all currencies in the wallet */
void Wallet::toString() {
    // todo
}

/* returns probability of selling a coin */
float Wallet::pSell() { return *(this->prob_sell); }

/* returns probability of buying a coin */
float Wallet::pBuy() { return *(this->prob_buy); }