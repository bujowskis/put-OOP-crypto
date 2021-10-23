#include "all_headers.h"


int main() {
    MemeStake* ptr1 = new MemeStake("SomeCoin", 'D', 20, 10.54, "John Smith", false, "This funny meme", 20);
    ptr1->toString();
    delete ptr1;

    MemeWork* ptr2 = new MemeWork("SomeOtherCoin", 'M', 15, 3.41, "Samuel Lux", true, "That other funny meme", "hash-bf");
    ptr2->toString();
    delete ptr2;

    SeriousStake* ptr3 = new SeriousStake("SomeSeriousCoin", 'S', 7, 7.21, "Ron Martin", true, 6, 50);
    ptr3->toString();
    delete ptr3;

    SeriousWork* ptr4 = new SeriousWork("SomeOtherSeriousCoin", '#', 74, 0.87, "Dot. inc.", false, 2, "sha-256 lock-in");
    ptr4->toString();
    delete ptr4;

    NonBlockchain* ptr5 = new NonBlockchain("TraditionalCoin", 'T', 20.47, 1, "This Country");
    ptr5->toString();
    delete ptr5;

    cout << "it seems it works!\n";

    return 0;
}
