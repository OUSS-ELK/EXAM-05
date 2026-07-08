#include "bigint.hpp"
#include <iostream>

bigint::bigint() : digits(1,0) {}
bigint::bigint(unsigned long long nb){
    do{
        digits.push_back(nb % 10);
        nb /= 10;
    } while (nb);
}
