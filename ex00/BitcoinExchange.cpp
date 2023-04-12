//
// Created by ANASS on 4/12/2023.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    int p;
    std::ifstream file("data.csv");
    if (file.is_open())
    {
        while(getline(file,line))
        {
            if (line.find("date,exchange_rate"))
            {
                p = line.find(',');
                if(p != -1)
                {
                    key = line.substr(0,p);
                    value =  std::stod(line.substr(p + 1));
                    std::cout << key << " ==> " << value << std::endl;
                }

            }
        }
    }
    else
        std::cerr << "ERROR IN DATABASE FILE !!" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {

}