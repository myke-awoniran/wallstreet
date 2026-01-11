#pragma once
#include "OrderBookEntry.h"
#include <vector>

class Services
{
public:
    Services();
    void init();

private:
    void loadOrderBook();
    void printHelp();
    void printMenu();
    void printExchangeStats();
    void printWallet();
    int getUserOption();
    void goToNextTimeFrame();
    void processUserInput(int userOption);
    void enterOffer();
    void enterBid();
    std::vector<OrderBookEntry> orders;
};
