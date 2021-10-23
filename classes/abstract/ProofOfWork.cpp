#include "ProofOfWork.h"


/*
 * Constructor of ProofOfWork. Parameters:
 * string name - name of the currency
 * char symbol - symbol that will represent the currency
 * int amount - initial amount of currency's coins
 * float exchange_rate - initial exchange rate while converting to/from main currency
 * string authors - authors of this blockchain
 * bool can_create - specifies whether total amount of coins in the world is fixed or they can be created
 *      NOTE - this doesn't affect adding new coins of this currency to the Wallet
 * string proof_system - name of the system used to prove miner's work
 */
ProofOfWork::ProofOfWork(string name, char symbol, int amount, float exchange_rate, string authors, bool can_create,
                         string proof_system) : Blockchain(name, symbol, amount, exchange_rate, authors, can_create) {
    this->proof_system = new string proof_system;
}

virtual ProofOfWork::~ProofOfWork() {
    delete this->proof_system;
}