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
                    struct tm tm;
                    if (strptime(key.c_str(), "%Y-%m-%d", &tm)) {
                        int y = tm.tm_year + 1900;
                        if (checkvalue(y,2011,2023) == false)
                            std::cerr << "Error: BTC date => " << key << std::endl;
                        else
                        {
                            if (checkvalue(value,0,1000))
                            {
                                if (database[key])
                                    std::cout << key << " => " << value << " = " << value * database[key] << std::endl;
                                else
                                {
                                    std::map<std::string,double>::iterator it;
                                    it = database.upper_bound(key);
                                    it--;
                                    it--;
                                    std::cout << key << " => " << value << " = " << value * it->second << std::endl;
                                }
                            }
                            else if (value > 1000)
                                std::cerr << "Error: too large a number." << std::endl;
                            else
                                std::cerr << "Error: not a positive number." << std::endl;
                        }
                    }
                    else
                        std::cerr << "Error: Date not valid => " << key << std::endl;
                }
                else
                    std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    }
    else
        std::cerr << "Error: file !!" << line << std::endl;

}

BitcoinExchange::~BitcoinExchange() {

}