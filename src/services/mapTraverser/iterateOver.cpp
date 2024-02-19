#include "iterateOver.h"
#include <iostream>
#include <map>
#include <vector>
#include "../../../include/colorCodes/colorCodes.h"

void iterateOver(std::map<std::string, std::vector<Product>>& map)
{
    uint32_t counter = 1;
    for (auto& category : map) {
        for (auto& data : category.second) {
            std::cout << GREEN_COLOR << counter++ << ") " << RESET_COLOR;
            std::cout << "Product ID: " << data.getProductID()
                      << ", Name: " << data.getProductName()
                      << ", Price: $" << data.getProductPrice() << std::endl;
        }
    }
}
