#ifndef PROOFOFWORK_H
#define PROOFOFWORK_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class ProofOfWork : virtual public Blockchain {
private:
    string* proof_system;
public:
    /*
     * Constructor of ProofOfWork. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     * string authors - authors of this blockchain
     * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
     *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
     * string proof_system - name of the system used to prove miner's work
     */
    ProofOfWork(string name, char symbol, float amount, float exchange_rate, string authors, bool can_create,
                string proof_system) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
        this->proof_system = new string;
        *(this->proof_system) = proof_system;
    }

    virtual ~ProofOfWork() {
        delete this->proof_system;
    }

    virtual void toString() = 0; // implemented in leaves
    string getProofSystem() { return *(this->proof_system); }
};


#endif //PROOFOFWORK_H
