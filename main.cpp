#include "all_headers.h"


int main() {
    srand(time(NULL));

    // Prepare the wallet
    string owner;
    cout << "Who's the owner of the wallet?\n\t";
    cin >> owner;
    int currencies_count;
    cout << "\nHow many currencies there should be (not counting the main currency, at least 1)?\n\t";
    cin >> currencies_count;
    while (currencies_count < 1) {
        cout << "\n\tno. of currencies other than main one must be at least 1, please try again:\n\t";
        cin >> currencies_count;
        // non-integer argument cause funny loop, but we assume the input is right
    }
    float prob_sell;
    cout << "\nWhat's the probability of selling a coin? (0.0 - 1.0):\n\t";
    cin >> prob_sell;
    float prob_buy;
    cout << "\nWhat's the probability of buying a coin? (0.0 - 1.0):\n\t";
    cin >> prob_buy;
    int coins_max;
    cout << "\nWhat's the initial max no. of coins to be randomized for a single currency?:\n\t";
    cin >> coins_max;
    while (coins_max <= 0) {
        cout << "\n\tinitial max no. of coins must be greater than 0, please try again:\n\t";
        cin >> coins_max;
    }

    // todo -  generate currencies
    vector<Currency*> currencies;
    MemeStake* ptr1 = new MemeStake("SomeCoin", 'D', 20, 10.54, "John Smith", false, "This funny meme", 20);
    MemeWork* ptr2 = new MemeWork("SomeOtherCoin", 'M', 15, 3.41, "Samuel Lux", true, "That other funny meme", "hash-bf");
    SeriousStake* ptr3 = new SeriousStake("SomeSeriousCoin", 'S', 7, 7.21, "Ron Martin", true, 6, 50);
    SeriousWork* ptr4 = new SeriousWork("SomeOtherSeriousCoin", '#', 74, 0.87, "Dot. inc.", false, 2, "sha-256 lock-in");
    NonBlockchain* ptr5 = new NonBlockchain("TraditionalCoin", 'T', 20.47, 1, "This Country");

    currencies.push_back(ptr1);
    currencies.push_back(ptr2);
    currencies.push_back(ptr3);
    currencies.push_back(ptr4);
    currencies.push_back(ptr5);

    Wallet<Currency> *wallet;
    try {
        wallet = new Wallet<Currency>(owner, currencies, ptr5, prob_sell, prob_buy);
    }
    catch (...) {
        cout << "\nprogram aborted\n";
        return 0;
    }

    wallet->simulate();
    delete wallet;

    return 0;
}
