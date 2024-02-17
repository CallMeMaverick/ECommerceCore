#include "getFromMap.h"
#include <iostream>
#include <vector>
#include <map>

Product* getFromMap(std::map<std::string, std::vector<Product>> &map, const int &index)
{
    unsigned int counter = 0;
    Product* product = nullptr;

    for (auto& category : map) {
        for (auto& data : category.second) {
            if (counter == index - 1) {
                product = &data;
            }
            counter++;
        }
        if (product) break;
    }

    return product;
}