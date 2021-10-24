#include "all_headers.h"


int main() {
    srand(time(NULL));
    Wallet* wallet;

    // Prepare the wallet
    { // to declare scope of input arguments
        string owner;
        cout << "Who's the owner of the wallet?\n\t";
        cin >> owner;
        int currencies_count;
        cout << "\nHow many currencies there should be (not counting the main currency, at least 1)?\n\t";
        cin >> currencies_count;
        while (currencies_count < 1) {
            cout << "\n\tno. of currencies other than main one must be at least 1, please try again:\n\t";
            cin >> currencies_count;
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
        Currency* currencies[currencies_count];
        MemeStake* ptr1 = new MemeStake("SomeCoin", 'D', 20, 10.54, "John Smith", false, "This funny meme", 20);
        currencies[0] = ptr1;
        MemeWork* ptr2 = new MemeWork("SomeOtherCoin", 'M', 15, 3.41, "Samuel Lux", true, "That other funny meme", "hash-bf");
        currencies[1] = ptr1;
        SeriousStake* ptr3 = new SeriousStake("SomeSeriousCoin", 'S', 7, 7.21, "Ron Martin", true, 6, 50);
        currencies[2] = ptr1;
        SeriousWork* ptr4 = new SeriousWork("SomeOtherSeriousCoin", '#', 74, 0.87, "Dot. inc.", false, 2, "sha-256 lock-in");
        currencies[3] = ptr1;
        NonBlockchain* ptr5 = new NonBlockchain("TraditionalCoin", 'T', 20.47, 1, "This Country");
        currencies[4] = ptr1;

        currencies[4]->toString();

        try {
            wallet = new Wallet(owner, currencies, currencies[0], prob_sell, prob_buy);
        }
        catch (...) {
            cout << "\nprogram aborted\n";
            return 0;
        }
    }

    delete wallet;

    cout << "it seems it works!\n";

    return 0;
}
