#ifndef NONBLOCKCHAIN_H
#define NONBLOCKCHAIN_H


#include "../abstract/Currency.h"


class NonBlockchain : public Currency {
private:
    string* authority;
public:
    /*
     * Constructor of NonBlockchain. NonBlockchain is a leaf class. Parameters:
     * string name - name of the currency
     * char symbol - symbol that will represent the currency
     * float amount - initial amount of currency's coins
     * float exchange_rate - initial exchange rate while converting to/from main currency
     * string authority - name of the authority over given currency
     */
    NonBlockchain(string name, char symbol, float amount, float exchange_rate, string authority)
            : Currency(name, symbol, amount, exchange_rate) {
        this->authority = new string;
        *(this->authority) = authority;
    }

    ~NonBlockchain() {
        delete this->authority;
    }

    /* Prints detailed info about given currency */
    void toString() {
        cout << this->getName() << ", a NonBlockchain currency:" <<
             "\n\tsymbol of this currency is \'" << this->getSymbol() << "\'," <<
             "\n\tcurrent amount: " << this->getAmount() << " coins," <<
             "\n\tcurrent exchange rate: " << this->getExchangeRate() << "," <<
             "\n\tname of the authority: " << *(this->authority) << "\n\n";
    }
};


#endif //NONBLOCKCHAIN_H
