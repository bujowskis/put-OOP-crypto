#ifndef SERIOUSSTAKE_H
#define SERIOUSSTAKE_H


#include "../abstract/SeriousCoin.h"
#include "../abstract/ProofOfStake.h"


class SeriousStake : public SeriousCoin, public ProofOfStake {
public:
    void toString();
};


#endif //SERIOUSSTAKE_H
