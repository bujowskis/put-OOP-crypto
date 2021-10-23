#include "SeriousCoin.h"


/*
 * Constructor of Blockchain. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authors - authors of this blockchain
 * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
 *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
 * int seriousness_class - specifies how serious this currency is (the more, the more serious)
 */
SeriousCoin::SeriousCoin(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create,
                         int seriousness_class) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
    this->seriousness_class = new int seriousness_class;
}

virtual SeriousCoin::~SeriousCoin() {
    delete this->seriousness_class;
}