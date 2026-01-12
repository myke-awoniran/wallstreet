#include "Services.h"
#include "CSVReader.h"

int main()
{
    // Services app{};
    // app.init();
    CSVReader::readCSVFile("../data/test_data.csv");
    return 0;
}