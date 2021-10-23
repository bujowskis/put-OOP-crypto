#include "all_headers.h"


int main() {
    MemeStake* ptr = new MemeStake("SomeCoin", 'D', 20, 10.54, "John Smith", false, "This funny meme", 20);
    ptr->toString();
    delete ptr;
    cout << "it seems it works?\n";

    return 0;
}
