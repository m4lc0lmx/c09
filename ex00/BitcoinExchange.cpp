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
                    database[key] = value;
//                    std::cout << database[key]  << std::endl;
                }
                else
                {
                    std::cerr << "ERROR IN DATA BASE!!!" << std::endl;
                    exit(1);
                }
            }
        } 
    }
    else
        std::cerr << "ERROR IN DATABASE FILE !!" << std::endl;
}

bool BitcoinExchange::checkvalue(int value, int min, int max) {
    if(value >= min && value <= max)
        return true;
    return false;
}

void BitcoinExchange::calculator(char *file) {
    int p;
    std::ifstream f(file);
    if (f.is_open())
    {
        while(getline(f,line))
        {
            if (line.find("date | value"))
            {
                p = line.find('|');
                if(p != -1)
                {
                    key = line.substr(0,p - 1);
                    value =  std::stod(line.substr(p + 2));
                    std::cerr << key << " | " << value << std::endl;
                    struct tm tm{};
                    if (strptime(key.c_str(), "%Y-%m-%d", &tm)) {
                        int d = tm.tm_mday,
                                m = tm.tm_mon + 1,
                                y = tm.tm_year + 1900;
                        if (checkvalue(y,2011,2023) == false)
                            std::cerr << "Error: BTC date => " << key << std::endl;
                        //else if () TODO check for to large number
                        else
                            std::cout << key
                    }
                    else
                        std::cerr << "Error: Date not valid => " << key << std::endl;
                }
                else
                    std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    }

}

BitcoinExchange::~BitcoinExchange() {

}