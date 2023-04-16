
#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(char *str)
{

    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
            continue;
        if (str[i] >= '0' && str[i] <= '9')
                s.push(atoi(&str[i]));
    }
    while (!s.empty())
    {
        std::cout << '-' << s.top();
        s.pop();
    }
    
}

RPN::~RPN(){

}