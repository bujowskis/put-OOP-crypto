#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H


#include "Currency.h"


class Blockchain : public Currency {
private:
    string* authors;
    bool* can_create;
public:
    virtual void toString() = 0; // it's up to the leaves
    string getAuthors() { return *(this->authors); }
    bool getCanCreate() { return *(this->can_create); }
};


#endif //BLOCKCHAIN_H
