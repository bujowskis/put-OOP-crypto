#include "MemeCoin.h"


/*
 * Constructor of MemeCoin. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authors - authors of this blockchain
 * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
 *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
 * string named_after - name of the meme it's named after
 */
MemeCoin::MemeCoin(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create,
                   string named_after) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
    this->named_after = new string named_after;
}

virtual MemeCoin::~MemeCoin() {
    delete this->named_after;
}