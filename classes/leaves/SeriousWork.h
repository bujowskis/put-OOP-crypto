#ifndef SERIOUSWORK_H
#define SERIOUSWORK_H


#include "../abstract/SeriousCoin.h"
#include "../abstract/ProofOfWork.h"


class SeriousWork : public SeriousCoin, public ProofOfWork {
public:
    void toString();
};


#endif //SERIOUSWORK_H
