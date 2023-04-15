

#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
    if (ac == 2)
    {
        (void)av;
        BitcoinExchange LL;
        LL.calculator(av[1]);
    }
    else
        std::cerr << "usage : ./btc second_database" << std::endl;
}