#pragma once
#include "OrderBookEntry.h"
#include <fstream>


class CSVReader {
	public:
  		CSVReader();
 		static std::vector<OrderBookEntry> readCSVFile(const std::string& csvFilePath);
 	private:
   		static std::vector<std::string> tokenise(const std::string& csvLine, char separator);
	    static OrderBookEntry stringsToOrderBookEntry(std::vector<std::string> tokens);
};
