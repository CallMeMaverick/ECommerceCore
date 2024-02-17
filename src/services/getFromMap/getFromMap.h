#ifndef ECOMMERCECORE_GETFROMMAP_H
#define ECOMMERCECORE_GETFROMMAP_H

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "../../../src/classes/Product/Product.h"

Product* getFromMap(std::map<std::string, std::vector<Product>> &map, const int &index);

#endif //ECOMMERCECORE_GETFROMMAP_H
