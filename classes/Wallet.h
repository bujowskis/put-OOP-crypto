#include <string>
#include "abstract/Currency.h"


#ifndef WALLET_H
#define WALLET_H


class Wallet {
private:
    string owner;
    Currency *currencies;
    Currency *main_currency;

public:
    void tradeAll();
    void listAll();
    void toString();
};


#endif //WALLET_H
