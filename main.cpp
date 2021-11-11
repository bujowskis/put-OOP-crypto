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
    float coins_main;
    cout << "\nHow much of the main currency the owner starts with?\n\t";
    cin >> coins_main;
    cout << "\n";

    const char *countries[16] = {"Russia", "Germany", "USA", "Poland", "Netherlands", "Nigeria", "Canada", "France",
                                 "Australia", "China", "Japan", "Egypt", "Greece", "Mexico", "Spain", "Austria"};
    const char *traditional_names[6] = {"Dollar", "Euro", "Pound", "Cent", "Yen", "Zloty"};
    const char *meme_names[9] = {"Doge", "Snek", "Boomer", "Karen", "Shrek", "Joker", "Stonks", "Sanic", "Spoderman"};
    const char *serious_names[9] = {"Bit", "Byte", "Ether", "Bi", "Teth", "Lite", "Uni", "Chain", "Algo"};
    const char *blockchain_endings[16] = {"coin", " Coin", "eum", "nance", "er", "dot", "on", "swap",
                                          "link", "rand", " Computer", "Ta", "tom", "era", " Graph", "pring"};
    const char *names[16] = {"John", "Samantha", "Maria", "Dennis", "Adam", "Mavis", "George", "Stan",
                                    "James", "Simon", "Olivia", "Charlotte", "Emma", "Oliver", "Robert", "Patricia"};
    const char *surnames[16] = {"Smith", "Johnson", "Miller", "Williams", "Anderson", "Brown", "Hernandez", "Martinez",
                                "Young", "Collins", "Murphy", "Cruz", "Patel", "Myers", "Long", "Ross"};
    const char *proof_systems[8] = {"sha-256", "ZK-proof", "MA protocol", "MIP protocols",
                                    "PCP system", "Bilinear grouping", "NI-system", "Empty miner"};

    // generate currencies
    vector<Currency*> currencies;

    // one traditional currency as main
    int country_idx = rand() % 16;
    currencies.push_back( new NonBlockchain(
            (string) traditional_names[rand() % 6] + " of " + (string) countries[country_idx],
            (char) 64 + (rand() % 59),
            coins_main,
            1,
            countries[country_idx]));

    // the rest randomly
    int meme_idx;
    int which_type;
    for (int i = 0; i < currencies_count; i++) {
        which_type = rand() % 5;
        cout << "randomized: " << which_type << "\n";
        switch (which_type) {
            case 0:
                // MemeStake
                meme_idx = rand() % 9;
                currencies.push_back( new MemeStake(
                        (string) meme_names[meme_idx] + (string) blockchain_endings[rand() % 16],
                        (char) (64 + (rand() % 59)),
                        (float) 1 + rand() % coins_max,
                        (float) (rand() % 6 + (float) (rand() % 100 + 1) / 100),
                        (string) names[rand() % 16] + " " + (string) surnames[rand() % 16],
                        (bool) (rand() % 2),
                        meme_names[meme_idx],
                        rand() % 51));
                break;
            case 1:
                // MemeWork
                meme_idx = rand() % 9;
                currencies.push_back( new MemeWork(
                        (string) meme_names[meme_idx] + (string) blockchain_endings[rand() % 16],
                        (char) (64 + (rand() % 59)),
                        (float) 1 + rand() % coins_max,
                        (float) (rand() % 6 + (float) (rand() % 100 + 1) / 100),
                        (string) names[rand() % 16] + " " + surnames[rand() % 16],
                        (bool) (rand() % 2),
                        meme_names[meme_idx],
                        proof_systems[rand() % 8]));
                break;
            case 2:
                // SeriousStake
                currencies.push_back( new SeriousStake(
                        (string) serious_names[rand() % 9] + (string) blockchain_endings[rand() % 16],
                        (char) (64 + (rand() % 59)),
                        (float) 1 + rand() % coins_max,
                        (float) (rand() % 21 + (float) (rand() % 100 + 1) / 100),
                        (string) names[rand() % 16] + " " + (string) surnames[rand() % 16],
                        (bool) (rand() % 2),
                        1 + rand() % 10,
                        rand() % 51));
                break;
            case 3:
                // SeriousWork
                currencies.push_back( new SeriousWork(
                        (string) serious_names[rand() % 9] + (string) blockchain_endings[rand() % 16],
                        (char) (64 + (rand() % 59)),
                        (float) 1 + rand() % coins_max,
                        (float) (rand() % 21 + (float) (rand() % 100 + 1) / 100),
                        (string) names[rand() % 16] + " " + (string) surnames[rand() % 16],
                        (bool) (rand() % 2),
                        1 + rand() % 10,
                        proof_systems[rand() % 8]));
                break;
            case 4:
                // NonBlockchain
                country_idx = rand() % 16;
                currencies.push_back( new NonBlockchain(
                        (string) traditional_names[rand() % 6] + " of " + (string) countries[country_idx],
                        (char) (64 + (rand() % 59)),
                        (float) 1 + rand() % coins_max,
                        (float) (rand() % 6 + (float) (rand() % 100 + 1) / 100),
                        countries[country_idx]));
                break;
            default:
                throw "the impossible happened";
        }
    }

    Wallet<Currency> *wallet;
    try {
        wallet = new Wallet<Currency>(owner, currencies, currencies.at(0), prob_sell, prob_buy);
    }
    catch (...) {
        cout << "\nprogram aborted\n";
        return 0;
    }

    wallet->simulate();
    delete wallet;

    return 0;
}
