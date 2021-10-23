#ifndef SERIOUSCOIN_H
#define SERIOUSCOIN_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class SeriousCoin : virtual public Blockchain {
private:
    int* seriousness_class;
public:
    virtual void toString() = 0; // it's up to leaves
    int getSeriousnessClass() { return *(this->seriousness_class); }
};


#endif //SERIOUSCOIN_H
