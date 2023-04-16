#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <stack>


class RPN{
    std::stack<int> s;

public:
    RPN();
    RPN(char *str);
    ~RPN();

};


#endif