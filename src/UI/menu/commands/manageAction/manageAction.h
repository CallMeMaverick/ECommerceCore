#ifndef ECOMMERCECORE_MANAGEACTION_H
#define ECOMMERCECORE_MANAGEACTION_H

#include <iostream>
#include <map>
#include <vector>
#include "../../../../classes/Product/Product.h"
#include "../../../../classes/User/Customer/Customer.h"

class manageAction
{
public:
    static void execute(Customer& customer, std::map<std::string, std::vector<Product>>& mapped, const std::string& currentCategory);
    static void addItem(Customer& customer, std::map<std::string, std::vector<Product>>& mapped, const std::string& category);
    static void deleteItem(Customer& customer);

    manageAction() = delete;
    ~manageAction() = default;
};


#endif //ECOMMERCECORE_MANAGEACTION_H
