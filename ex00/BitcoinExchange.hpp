//
// Created by ANASS on 4/12/2023.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
#include <ctime>


class BitcoinExchange {
    std::map<std::string,double> database;
    std::string                  line;
    std::string                  key;
    double                       value;

public:
    BitcoinExchange();
//    BitcoinExchange(Convert &copy);
    BitcoinExchange& operator=(BitcoinExchange &copy);
    ~BitcoinExchange();

    void    calculator(char *file);
    bool    checkvalue(int value,int min, int max);
};


#endif //C09_BITCOINEXCHANGE_HPP
