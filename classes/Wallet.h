#ifndef WALLET_H
#define WALLET_H


#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "abstract/Currency.h"
using namespace std;

template <class T>
class Wallet {
private:
    string* owner;
    int* iteration;
    vector<T*>* currencies;
    T* main_currency;
    float* prob_sell;
    float* prob_buy;

public:
    /*
     * Constructor of Wallet. Parameters:
     * string owner - name of the Wallet's owner
     * vector<T*> &currencies - pointer to vector of pointers of all available currencies
     * T* main_currency - currency with exchange_rate = 1; i.e. used as anchor point to buy other currencies with
     *      and to sell other currencies for
     * float prob_sell - probability of selling a coin
     * float prob_buy - probability of buying a coin
     */
    Wallet(string owner, vector<T*> &currencies, T* main_currency, float prob_sell, float prob_buy) {
        if ((prob_buy < 0) || (1 < prob_buy) || (prob_sell < 0) || (1 < prob_sell))
            throw invalid_argument("probability out of (0.0 - 1.0) range\n");
        if (prob_sell <= prob_buy) {
            cout << "\n\tWARNING - trying to run program with prob_sell <= prob_buy\n"
                    "\t\tthat means the program is not necessarily convergent and can run forever\n"
                    "\t\tdo you still want to run it? (y/n)\n\t\t";
            char should_run;
            cin >> should_run;
            while ((should_run != 'n') && (should_run != 'y') && (should_run != 'N') && (should_run != 'Y')) {
                cout << "\nSorry, I didn't understand that. Please use (y/n) answers.\n"
                        "\t\tdo you still want to run it? (y/n)\n\t\t";
                cin >> should_run;
            }
            if ((should_run == 'n') || (should_run == 'N'))
                throw "non-convergent";
        }
        this->owner = new string;
        *(this->owner) = owner;
        this->iteration = new int;
        *(this->iteration) = 1;

        this->currencies = &currencies;
        this->main_currency = main_currency;

        // probabilities converted to %
        this->prob_sell = new float;
        *(this->prob_sell) = prob_sell * 100;
        this->prob_buy = new float;
        *(this->prob_buy) = prob_buy * 100;
    }

    ~Wallet() {
        delete this->owner;
        for (int i = 0; i < this->currencies->size(); i++)
            delete this->currencies->at(i);
        currencies->clear();
        delete this->iteration;
        delete this->prob_sell;
        delete this->prob_buy;
    }

    /* Runs trade() on all coins in the wallet, returns if there are still coins of other currencies than main one */
    bool tradeAll() {
        bool no_coins_left = true;
        // loop over all currencies
        for (int i = 0; i < this->currencies->size(); i++) {
            if (this->currencies->at(i) == this->main_currency) {
                // skip the main currency - it's not being traded for itself
                continue;
            }
            if (!(this->currencies->at(i)->getAmount())) {
                // no coins of this currency in the wallet - skip it
                continue;
            }
            // loop over all coins of this currency
            for (int j = 0; j < (int) this->currencies->at(i)->getAmount(); j++) {
                // buying phase
                if ((rand() % 100) < this->pBuy()) {
                    if (this->main_currency->getAmount() > this->currencies->at(i)->getExchangeRate()) {
                        this->main_currency->subAmount(this->currencies->at(i)->getExchangeRate());
                        this->currencies->at(i)->addAmount(1);
                    }
                }
                // selling phase
                if ((rand() % 100) < this->pSell()) {
                    this->currencies->at(i)->subAmount(1);
                    this->main_currency->addAmount(this->currencies->at(i)->getExchangeRate());
                }
            }
            // simulate new exchange rate
            this->currencies->at(i)->Currency::simExchange();
            no_coins_left = false;
        }
        return no_coins_left;
    }

    /*
     * Lists most important information of all currencies in the wallet
     * returns the total worth of all coins in the wallet
     */
    float listAll() {
        float worth_total = 0;
        cout << "iteration " << *(this->iteration) << ":\n";
        for (int i =0; i < this->currencies->size(); i++) {
            this->currencies->at(i)->list();
            worth_total += this->currencies->at(i)->getAmount() * this->currencies->at(i)->getExchangeRate();
        }
        cout << "total worth in this iteration: " << worth_total << " " << this->main_currency->getSymbol() << "\n\n";
        *(this->iteration) += 1;
        return worth_total;
    }

    /* Runs the Wallet's simulation */
    void simulate() {
        float worth_min, worth_max, worth_initial, worth_current;

        worth_initial = 0;
        for (int i = 0; i < this->currencies->size(); i++)
            worth_initial += this->currencies->at(i)->getAmount() * this->currencies->at(i)->getExchangeRate();
        worth_min = worth_initial;
        worth_max = worth_initial;

        this->toString();
        cout << "The main currency is: " << this->main_currency->getName() << "\n";
        {
            bool useless;
            cout << "(type anything or Ctrl+D to start)\n";
            cin >> useless;
        }

        // main loop of the simulation
        bool should_run = true;
        while (should_run) {
            should_run = !(this->tradeAll());
            if (should_run)
                worth_current = this->listAll();
            if (worth_current < worth_min)
                worth_min = worth_current;
            if (worth_current > worth_max)
                worth_max = worth_current;
        }

        // At this point, there should be no other currencies than the main one
        if (worth_current != this->main_currency->getAmount())
            throw "SOMETHING WENT REALLY WRONG\n";

        cout << "\n******************\n" << "the simulation ended. Summary:\n" <<
        "\tfinal worth, after selling all other coins is: " << worth_current << " " <<this->main_currency->getSymbol()
        << ",\n" <<
        "\tminimal worth reached was: " << worth_min << " " << this->main_currency->getSymbol() << ",\n" <<
        "\tmaximal worth reached was: " << worth_max << " " << this->main_currency->getSymbol() << ",\n" <<
        "\t\tso, it was possible to gain " << worth_max - worth_current << " " << this->main_currency->getSymbol() <<
        " more,\n";
        float worth_relative = worth_current - worth_initial;
        if (worth_relative < 0) {
            worth_relative *= -1;
            cout << "\toverall, the owner lost " << worth_relative << " " << this->main_currency->getSymbol() << "\n" <<
            "\t\t(that's about " << round((worth_relative / worth_initial) * 100) << "% loss)\n";
        } else {
            cout << "\toverall, the owner gained " << worth_relative << " " << this->main_currency->getSymbol() <<
            "\n" << "\t\t(that's about " << round((worth_relative / worth_initial) * 100) << "% gain)\n";
        }
        cout << "\n******************\n";
    }

    /* Prints detailed information of all currencies in the wallet */
    void toString() {
        cout << "This wallet belongs to " << *(this->owner) << ", the owner:\n" <<
        "\tis willing to BUY  coins with " << this->pBuy() << "% probability,\n" <<
        "\tis willing to SELL coins with " << this->pSell() << "% probability,\n" <<
        "\tuses " << this->main_currency->getName() << " as their main currency\n" <<
        "\tis interested in and will trade the following currencies:\n\n";

        for (int i = 0; i < this->currencies->size(); i++)
            this->currencies->at(i)->toString();
            //this->currencies[i]->toString();
    }

    /* Returns probability of selling a coin */
    float pSell() { return *(this->prob_sell); }

    /* Returns probability of buying a coin */
    float pBuy() { return *(this->prob_buy); }
};


#endif //WALLET_H
