#ifndef WALLET_H
#define WALLET_H


#include <string>
#include <iostream>
#include "abstract/Currency.h"

using namespace std;


class Wallet {
private:
    string* owner;
    Currency* currencies;
    Currency* main_currency;
    float* prob_sell;
    float* prob_buy;

public:
    void tradeAll();
    void listAll();
    void toString();

    // setters/getters
    float pSell();
    float pBuy();
};


#endif //WALLET_H
