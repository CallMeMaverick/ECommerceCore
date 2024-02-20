#ifndef ECOMMERCECORE_MANAGEACCOUNT_H
#define ECOMMERCECORE_MANAGEACCOUNT_H

#include "../../../../classes/User/Customer/Customer.h"

class manageAccount
{
public:
    static void execute(Customer& customer, bool& flag);
    manageAccount() = delete;
    ~manageAccount() = default;
};


#endif //ECOMMERCECORE_MANAGEACCOUNT_H
