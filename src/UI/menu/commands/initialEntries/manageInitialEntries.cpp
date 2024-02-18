#include "manageInitialEntries.h"
#include "../manageAccount/manageAccount.h"
#include "../shop/shop.h"
#include "../../../../../include/colorCodes/colorCodes.h"


int manageInitialEntries::execute()
{
    uint16_t initialEntry;

    std::cout << BLUE_COLOR << BOLD_TEXT << "1. " << RESET_COLOR << RESET_COLOR << "Shop" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "2. " << RESET_COLOR << RESET_COLOR << "Manage account" << std::endl;
    std::cout << "==> ";
    std::cin >> initialEntry;

    while (initialEntry < 1 || initialEntry > 2)
    {
        std::cout << RED_COLOR << "Choose carefully: " << RESET_COLOR;
        std::cin >> initialEntry;
    }

    if (initialEntry == 1) return 1;
    if (initialEntry == 2) return 2;

}


std::string manageInitialEntries::manageOptionShop() { return shop::execute(); }

void manageInitialEntries::manageOptionManageAccount(Customer& customer) { manageAccount::execute(customer); }