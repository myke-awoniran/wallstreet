#include "CSVReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include<vector>

CSVReader::CSVReader()
{
};

std::vector<OrderBookEntry> CSVReader::readCSVFile(const std::string& csvFilePath)
{
    try
    {
        std::vector<OrderBookEntry> entries;
        std::ifstream csvFile(csvFilePath);
        std::string line;
        char delimiter = ',';
        if (!csvFile.is_open())
        {
            std::cout << "Unable to open file: " << csvFilePath << std::endl;
            throw std::exception{};
        }
        while (std::getline(csvFile, line))
        {
            try
            {
                entries.push_back(stringsToOrderBookEntry(tokenise(line, delimiter)));
            }
            catch (const std::exception& e)
            {
                std::cout << "CSVReader::readCSVFile: Bad data" << line << std::endl;
            }
        }
        csvFile.close();

        // std::cout << "CSVReader::readCSVFile " << entries.size() << " entries" << std::endl;
        return entries;
    }
    catch (const std::exception& e)
    {
        throw e;
    }
};


std::vector<std::string> CSVReader::tokenise(const std::string& csvLine, char delimiter)
{
    std::vector<std::string> tokens;
    signed int end;
    std::string token;
    signed int start = csvLine.find_first_not_of(delimiter, 0);

    do
    {
        end = csvLine.find_first_of(delimiter, start);
        if (start == end || end == csvLine.length()) break;

        if (end >= 0)token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);
        start = end + 1;
    }
    while (end > 0);
    // std::cout << "CSVReader::tokenise " << tokens.size() << " tokens" << std::endl;

    return tokens;
}

OrderBookEntry CSVReader::stringsToOrderBookEntry(const std::vector<std::string>& tokens)
{
    double price, amount;
    if (tokens.size() != 5)
    {
        std::cout << "CSVReader::stringsToOrderBookEntry->Error parsing line" << std::endl;
        throw std::exception{};
    }

    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception& e)
    {
        std::cout << "Bad float: " << price << std::endl;
        std::cout << "Bad float: " << amount << std::endl;
        throw e;
    }

    OrderBookEntry entry{
        price,
        amount,
        tokens[0],
        tokens[1],
        OrderBookEntry::stringToOrderBookType(tokens[2])
    };
    return entry;
}
