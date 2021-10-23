#ifndef SERIOUSWORK_H
#define SERIOUSWORK_H


#include "../abstract/SeriousCoin.h"
#include "../abstract/ProofOfWork.h"


class SeriousWork : public SeriousCoin, public ProofOfWork {
public:
    /*
     *  note - parent constructor called directly because of the diamond problem of multiple inheritance
     *  for explanation, see the following article: https://www.geeksforgeeks.org/multiple-inheritance-in-c/
     */

    /*
     * Constructor of SeriousStake. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     * string authors - authors of this blockchain
     * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
     *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
     * int seriousness_class - specifies how serious this currency is (the more, the more serious)
     * string proof_system - name of the system used to prove miner's work
     */
    SeriousWork(string name, char symbol, float amount, float exchange_rate, string authors, bool can_create,
                             int seriousness_class, string proof_system) :
            Blockchain(name, symbol, amount, exchange_rate, authors, can_create),
            SeriousCoin(name, symbol, amount, exchange_rate, authors, can_create, seriousness_class),
            ProofOfWork(name, symbol, amount, exchange_rate, authors, can_create, proof_system) { }

    virtual ~SeriousWork() { }

    /* Prints detailed info about given currency */
    void toString() {
        cout << this->getName() << ", a MemeStake currency:" <<
             "\n\tsymbol of this currency is \'" << this->getSymbol() << "\'," <<
             "\n\tcurrent amount: " << this->getAmount() << " coins," <<
             "\n\tcurrent exchange rate: " << this->getExchangeRate() << "," <<
             "\n\tauthors: " << this->getAuthors() << "," <<
             "\n\tcan new coins be created: " << this->getCanCreate() << "," <<
             "\n\tseriousness class: " << this->getSeriousnessClass() << "," <<
             "\n\tproof system used: " << this->getProofSystem() << "\n\n";
    }
};


#endif //SERIOUSWORK_H
