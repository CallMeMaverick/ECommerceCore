#include "manageInitialEntries.h"
#include "../manageAccount/manageAccount.h"
#include "../shop/shop.h"
#include "../../../../../include/colorCodes/colorCodes.h"
#include "../manageAction/manageAction.h"


int manageInitialEntries::execute()
{
    uint16_t initialEntry;

    std::cout << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "1. " << RESET_COLOR << RESET_COLOR << "Shop" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "2. " << RESET_COLOR << RESET_COLOR << "Manage basket" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "3. " << RESET_COLOR << RESET_COLOR << "Manage account" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "4. " << RESET_COLOR << RESET_COLOR << "Exit" << std::endl;

    std::cout << "==> ";
    std::cin >> initialEntry;

    while (initialEntry < 1 || initialEntry > 4)
    {
        std::cout << RED_COLOR << "Choose carefully: " << RESET_COLOR;
        std::cin >> initialEntry;
    }

    if (initialEntry == 1) return 1;
    if (initialEntry == 2) return 2;
    if (initialEntry == 3) return 3;
    if (initialEntry == 4) return 4;

}


std::string manageInitialEntries::manageOptionShop() { return shop::execute(); }

void manageInitialEntries::manageBasket(Customer &customer)
{
    Basket* currentBasket = customer.getBasketAddress();

    if (currentBasket->getBasketSize() == 0)
    {
        std::cout << MAGENTA_COLOR << BOLD_TEXT << "\nBasket is empty; Nothing to manage" << RESET_COLOR << RESET_COLOR << std::endl;
    }
    else
    {
        uint16_t basketOption;

        std::cout << BLUE_COLOR << BOLD_TEXT << "\n1. " << RESET_COLOR << RESET_COLOR << "Remove item" << std::endl;
        std::cout << BLUE_COLOR << BOLD_TEXT << "2. " << RESET_COLOR << RESET_COLOR << "Get basket's address" << std::endl;
        std::cout << BLUE_COLOR << BOLD_TEXT << "3. " << RESET_COLOR << RESET_COLOR << "Leave the section" << std::endl;
        std::cout << "==> ";
        std::cin >> basketOption;

        while (basketOption < 1 || basketOption > 3)
        {
            std::cout << RED_COLOR << "Choose carefully: " << RESET_COLOR;
            std::cin >> basketOption;
        }

        if (basketOption == 1)
        {
            customer.printBasketStyled();
            manageAction::deleteItem(customer);
        }
        else if (basketOption == 2)
            std::cout << CYAN_COLOR << "\nBasket's address --> " << RESET_COLOR << customer.getBasketAddress() << std::endl;
        else if (basketOption == 3)
            return;

    }
}

void manageInitialEntries::manageOptionManageAccount(Customer& customer, bool& flag) { manageAccount::execute(customer, flag); }