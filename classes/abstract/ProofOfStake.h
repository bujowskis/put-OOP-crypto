#ifndef PROOFOFSTAKE_H
#define PROOFOFSTAKE_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class ProofOfStake : virtual public Blockchain {
private:
    int* tokens_val;
public:
    virtual void toString() = 0; // it's up to leaves
    int getTokensVal() { return *(this->tokens_val); }
};


#endif //PROOFOFSTAKE_H
