#ifndef MEMEWORK_H
#define MEMEWORK_H


#include "../abstract/MemeCoin.h"
#include "../abstract/ProofOfWork.h"


class MemeWork : public MemeCoin, public ProofOfWork {
public:
    void toString();
};


#endif //MEMEWORK_H
