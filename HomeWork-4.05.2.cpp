#include <iostream>
#include "table.h"

int main()
{
    auto test = table<int>(2, 3);
    auto test2 = table<int>(5, 8);
    test2[0][0] = 234;
    std::cout << "Size table2: " << test2.Size() << std::endl;
    std::cout << "table2[0][0]: " << test2[0][0] << std::endl;;
    test[0][0] = 4;
    test2 = test;
    std::cout << "Size table2 after '=': " << test2.Size() << std::endl;
    std::cout << "table2[0][0]: " << test2[0][0] << std::endl;
    table<int> test3(test);
    std::cout << "Size table3 '=': " << test3.Size() << std::endl;
    std::cout << "table3[0][0]: " << test3[0][0] << std::endl;
}
