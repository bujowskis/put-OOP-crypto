#ifndef NONBLOCKCHAIN_H
#define NONBLOCKCHAIN_H


#include "Currency.h"


class NonBlockchain : public Currency {
private:
    string* authority;
public:
    void toString(); // this will be implemented here
};


#endif //NONBLOCKCHAIN_H
