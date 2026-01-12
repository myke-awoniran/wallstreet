#pragma once
#include<string>

enum class OrderBookType
{
    BID, ASK
};

class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);
    static OrderBookType stringToOrderBookType(const std::string& orderType);
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
