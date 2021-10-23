#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H


#include "Currency.h"


class Blockchain : public Currency {
private:
    string* authors;
    bool* can_create;
public:
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
    Blockchain(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create)
            : Currency(name, symbol, amount, exchange_rate) {
        this->authors = new string;
        *(this->authors) = authors;
        this->can_create = new bool;
        *(this->can_create) = can_create;
    }

    virtual ~Blockchain() {
        delete this->authors;
        delete this->can_create;
    }

    virtual void toString() = 0; // it's up to the leaves
    string getAuthors() { return *(this->authors); }
    bool getCanCreate() { return *(this->can_create); }
};


#endif //BLOCKCHAIN_H
