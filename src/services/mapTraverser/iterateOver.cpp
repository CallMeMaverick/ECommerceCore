#include "iterateOver.h"
#include <iostream>
#include <map>
#include <vector>
#include "../../../src/classes/Product/Product.h"

void iterateOver(std::map<std::string, std::vector<Product>>& map)
{
    for (auto& category : map) {
        for (auto& data : category.second) {
            std::cout << "Product ID: " << data.getProductID()
                      << ", Name: " << data.getProductName()
                      << ", Price: $" << data.getProductPrice() << std::endl;
        }
    }
}
