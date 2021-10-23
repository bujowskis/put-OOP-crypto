#include "Currency.h"


/*
 * Constructor of Currency. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 */
Currency::Currency(string name, char symbol, int amount, float exchange_rate) {
    this->name = new string name;
    this->symbol = new char symbol;
    if (amount <= 0)
        throw invalid_argument("initial amount must be greater than 0");
    this->amount = new int amount;
    this->exchange_rate = new float exchange_rate;
}

virtual Currency::~Currency() {
    delete this->name;
    delete this->symbol;
    delete this->amount;
    delete this->exchange_rate;
}

/* Trades all coins, i.e. iterates over all coins and decides whether to buy, sell or do nothing with each one,
 * based on probabilities defined in */
void Currency::trade() {
    // todo
}

/* Lists the most important info about this currency */
void Currency::list() {
    // todo
}