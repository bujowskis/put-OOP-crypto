#ifndef MEMEWORK_H
#define MEMEWORK_H


#include "../abstract/MemeCoin.h"
#include "../abstract/ProofOfWork.h"


class MemeWork : public MemeCoin, public ProofOfWork {
public:
    /*
     *  note - parent constructor called directly because of the diamond problem of multiple inheritance
     *  for explanation, see the following article: https://www.geeksforgeeks.org/multiple-inheritance-in-c/
     */

    /*
     * Constructor of MemeWork. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     * string authors - authors of this blockchain
     * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
     *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
     * string named_after - name of the meme it's named after
     * string proof_system - name of the system used to prove miner's work
     */
    MemeWork(string name, char symbol, float amount, float exchange_rate, string authors, bool can_create,
                       string named_after, string proof_system) :
            Blockchain(name, symbol, amount, exchange_rate, authors, can_create),
            MemeCoin(name, symbol, amount, exchange_rate, authors, can_create, named_after),
            ProofOfWork(name, symbol, amount, exchange_rate, authors, can_create, proof_system) { }

    virtual ~MemeWork() { }

    /* Prints detailed info about given currency */
    void toString() {
        cout << this->getName() << ", a MemeStake currency:" <<
             "\n\tsymbol of this currency is \'" << this->getSymbol() << "\'," <<
             "\n\tcurrent amount: " << this->getAmount() << " coins," <<
             "\n\tcurrent exchange rate: " << this->getExchangeRate() << "," <<
             "\n\tauthors: " << this->getAuthors() << "," <<
             "\n\tcan new coins be created: " << this->getCanCreate() << "," <<
             "\n\tis named after \"" << this->getNamedAfter() << "\" meme," <<
             "\n\tproof system used: " << this->getProofSystem() << "\n\n";
    }
};


#endif //MEMEWORK_H
