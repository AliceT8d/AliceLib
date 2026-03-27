#include "ali/ali.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> vec;
    for (const auto& x : ali::tool::random_vector(vec, ali::random::email, 200)) {
        std::cout << x << std::endl;
    }
}