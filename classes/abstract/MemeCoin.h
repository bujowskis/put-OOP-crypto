#ifndef MEMECOIN_H
#define MEMECOIN_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class MemeCoin : virtual public Blockchain {
private:
    string* named_after;
public:
    /*
     * Constructor of MemeCoin. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     * string authors - authors of this blockchain
     * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
     *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
     * string named_after - name of the meme it's named after
     */
    MemeCoin(string name, char symbol, float amount, float exchange_rate, string authors, bool can_create,
             string named_after) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
        this->named_after = new string;
        *(this->named_after) = named_after;
    }

    virtual ~MemeCoin() {
        delete this->named_after;
    }

    virtual void toString() = 0; // it's up to leaves
    string getNamedAfter() { return *(this->named_after); }
};


#endif //MEMECOIN_H
