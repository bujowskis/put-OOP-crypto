#include "NonBlockchain.h"

/*
 * Constructor of NonBlockchain. NonBlockchain is a leaf class. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authority - name of the authority over given currency
 */
NonBlockchain::NonBlockchain(string name, char symbol, int amount, float exchange_rate, string authority)
: Currency(name, symbol, amount, exchange_rate) {
    this->authority = new string authority;
}

NonBlockchain::~NonBlockchain() {
    delete this->authority;
}

/* Prints detailed info about given currency */
void NonBlockchain::toString() {
    cout << this->getName() << ", a NonBlockchain currency:" <<
    "\n\tsymbol of this currency is \'" << this->getSymbol() << "\'," <<
    "\n\tcurrent amount: " << this->getAmount() << " coins," <<
    "\n\tcurrent exchange rate: " << this->getExchangeRate() << "," <<
    "\n\tname of the authority: " << this->authority << "\n\n";
}