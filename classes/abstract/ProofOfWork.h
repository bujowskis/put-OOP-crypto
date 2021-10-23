#ifndef PROOFOFWORK_H
#define PROOFOFWORK_H


#include "Blockchain.h"


// extends 'virtual public' because of diamond problem in multiple inheritance
class ProofOfWork : virtual public Blockchain {
private:
    string* proof_system;
public:
    virtual void toString() = 0; // implemented in leaves
    string getProofSystem() { return *(this->proof_system); }
};


#endif //PROOFOFWORK_H
