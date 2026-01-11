#pragma once
#include<string>

enum class OrderType
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
                   OrderType _orderType);
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderType orderType;
};
