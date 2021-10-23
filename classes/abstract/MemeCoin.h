#ifndef MEMECOIN_H
#define MEMECOIN_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class MemeCoin : virtual public Blockchain {
private:
    string* named_after;
public:
    virtual void toString() = 0; // it's up to leaves
    string getNamedAfter() { return *(this->named_after); }
};


#endif //MEMECOIN_H
