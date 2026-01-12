#include "OrderBookEntry.h"

#include <iostream>
#include <ostream>

OrderBookEntry::OrderBookEntry(
    double _price,
    double _amount,
    std::string _timestamp,
    std::string _product,
    OrderBookType _orderType
) : price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType)
{
}

OrderBookType OrderBookEntry::stringToOrderBookType(const std::string& orderType)
{
    if (orderType == "ask") return OrderBookType::ASK;
    if (orderType == "bid") return OrderBookType::BID;
    std::cout << "Unknown order type: " << orderType << std::endl;
    throw std::exception{};
    // return orderType == "ask" ? OrderBookType::ASK : OrderBookType::BID;
}
