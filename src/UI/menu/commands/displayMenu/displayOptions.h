#ifndef ECOMMERCECORE_DISPLAYMENU_H
#define ECOMMERCECORE_DISPLAYMENU_H

#include "../../commandPattern/Command.h"
#include "../../../../classes/User/Customer/Customer.h"

class displayMenu : public Command
{
public:
    void execute() override;
    ~displayMenu() = default;
};


#endif //ECOMMERCECORE_DISPLAYMENU_H
