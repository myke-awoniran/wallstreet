#include "iostream"
#include "Services.h"
#include "OrderBookEntry.h"

Services::Services()
{
}

void Services::init()
{
    loadOrderBook();
    while (true)
    {
        printMenu();
        const int userInput = getUserOption();
        processUserInput(userInput);
    }
}

void Services::printHelp()
{
    std::cout << "Help- Your aim is to make money. Analyse the market and make bids and offers" << std::endl;
}

void Services::printMenu()
{
    std::cout << "1: Print Help" << std::endl;
    std::cout << "2: Print Exchange stats" << std::endl;
    std::cout << "3: Make an offer" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print Wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "===============" << std::endl;
}

int Services::getUserOption()
{
    std::cout << "Type in 1 - 6" << std::endl;
    int option;
    std::cin >> option;
    std::cout << "You chose option " << option << std::endl;
    return option;
}

void Services::loadOrderBook()
{
    orders.emplace_back(
        1000, 0.02, "2020-01-01", "BTC/USDT", OrderBookType::ASK
    );
}

void Services::printExchangeStats()
{
    std::cout << "Order Book contains " << orders.size() << " entries" << std::endl;
}

void Services::printWallet()
{
    std::cout << "Wallet" << std::endl;
}

void Services::enterOffer()
{
    // todo
}

void Services::enterBid()
{
    // todo
}

void Services::goToNextTimeFrame()
{
    std::cout << "Going to the next time" << std::endl;
}


void Services::processUserInput(const int userOption)
{
    switch (userOption)
    {
    case 1:
        {
            printHelp();
            return;
        }
    case 2:
        {
            printExchangeStats();
            return;
        }
    case 3:
        {
            enterOffer();
            return;
        }
    case 4:
        {
            enterBid();
            return;
        }
    case 5:
        {
            printWallet();
            return;
        }
    case 6:
        {
            goToNextTimeFrame();
            return;
        }
    default:
        {
            std::cout << "Invalid option" << std::endl;
        }
    }
}
