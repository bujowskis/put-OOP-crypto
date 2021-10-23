#include "ProofOfStake.h"


/*
 * Constructor of ProofOfStake. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authors - authors of this blockchain
 * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
 *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
 * int tokens_val - amount of tokens needed to be a validator
 */
ProofOfStake::ProofOfStake(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create,
                           int tokens_val) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
    this->tokens_val = new int tokens_val;
}

virtual ProofOfStake::~ProofOfStake() {
    delete this->tokens_val;
}