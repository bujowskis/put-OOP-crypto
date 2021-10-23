#include "MemeStake.h"


/*
 *  note - parent constructor called directly because of the diamond problem of multiple inheritance
 *  for explanation, see the following article: https://www.geeksforgeeks.org/multiple-inheritance-in-c/
 */

/*
 * Constructor of MemeStake. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authors - authors of this blockchain
 * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
 *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
 * string named_after - name of the meme it's named after
 * int tokens_val - amount of tokens needed to be a validator
 */
//MemeStake::MemeStake(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create,
//                     string named_after, int tokens_val) :
//        Blockchain(name, symbol, amount, exchange_rate, authors, can_create),
//        MemeCoin(name, symbol, amount, exchange_rate, authors, can_create, named_after),
//        ProofOfStake(name, symbol, amount, exchange_rate, authors, can_create, tokens_val) { }

/* Prints detailed info about given currency */
void MemeStake::toString() {
    cout << this->getName() << ", a MemeStake currency:" <<
         "\n\tsymbol of this currency is \'" << this->getSymbol() << "\'," <<
         "\n\tcurrent amount: " << this->getAmount() << " coins," <<
         "\n\tcurrent exchange rate: " << this->getExchangeRate() << "," <<
         "\n\tauthors: " << this->getAuthors() << "," <<
         "\n\tcan new coins be created: " << this->getCanCreate() << "," <<
         "\n\tis named after " << this->getNamedAfter() << " meme," <<
         "\n\tno. of tokens needed to be a validator: " << this->getTokensVal() << "\n\n";
}