#include "Blockchain.h"

/*
 * Constructor of Blockchain. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authors - authors of this blockchain
 * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
 *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
 */
Blockchain::Blockchain(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create)
: Currency(name, symbol, amount, exchange_rate) {
    this->authors = new string authors;
    this->can_create = new bool can_create;
}

virtual Blockchain::~Blockchain() {
    delete this->authors;
    delete this->can_create;
}