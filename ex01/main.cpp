
#include "RPN.hpp"

int main(int ac,char **av)
{
    if (ac == 2)
    {
        RPN p(av[1]);
    }
    else
        std::cerr << "Error" << std::endl;
}