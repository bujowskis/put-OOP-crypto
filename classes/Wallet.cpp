#include "Wallet.h"


/*
 * Constructor of Wallet. Parameters:
 * string owner - name of the Wallet's owner
 * Currency *currencies - list of all available currencies
 * Currency *main_currency - currency with exchange_rate = 1; i.e. used as anchor point to buy other currencies with
 *      and to sell other currencies for
 */
// todo - what's "noexcept" here for?
Wallet::Wallet(string owner, Currency *currencies, Currency *main_currency) noexcept {
    this->owner = owner;
    this->currencies = currencies;
    this->main_currency = main_currency;
}

/* Starts a loop over all currencies in the wallet, invoking currency.trade() */
void Wallet::tradeAll() {
    // todo
}

/* Lists most important information of all currencies in the wallet */
void Wallet::listAll() {
    // todo
}

/* Prints detailed information of all currencies in the wallet */
void Wallet::toString() {
    // todo
}