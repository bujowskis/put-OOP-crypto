#ifndef PROOFOFSTAKE_H
#define PROOFOFSTAKE_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class ProofOfStake : virtual public Blockchain {
private:
    int* tokens_val;
public:
    /*
     * Constructor of ProofOfStake. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     * string authors - authors of this blockchain
     * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
     *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
     * int tokens_val - amount of tokens needed to be a validator
     */
    ProofOfStake(string name, char symbol, float amount, float exchange_rate, string authors, bool can_create,
                 int tokens_val) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
        this->tokens_val = new int;
        *(this->tokens_val) = tokens_val;
    }

    virtual ~ProofOfStake() {
        delete this->tokens_val;
    }

    virtual void toString() = 0; // it's up to leaves
    int getTokensVal() { return *(this->tokens_val); }
};


#endif //PROOFOFSTAKE_H
