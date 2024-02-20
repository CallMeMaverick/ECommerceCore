#include "manageAccount.h"
#include "../../../../../include/colorCodes/colorCodes.h"

void manageAccount::execute(Customer& customer, bool& flag)
{
    uint16_t manageAccountOptionChosen;

    std::cout << BLUE_COLOR << BOLD_TEXT << "1. " << RESET_COLOR << RESET_COLOR << "Log out" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "2. " << RESET_COLOR << RESET_COLOR << "Delete account" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "3. " << RESET_COLOR << RESET_COLOR << "Get account information" << std::endl;
    std::cout << "==> ";
    std::cin >> manageAccountOptionChosen;

    switch (manageAccountOptionChosen) {
        case 1:
            std::cout << CYAN_COLOR << BOLD_TEXT << "\nLogging out" << RESET_COLOR << RESET_COLOR << std::endl;
            flag = false;
            break;
        case 2:
            customer.deleteAccount();
            flag = false;
            break;
        case 3:
            customer.getData();
            break;
        default: {};
    }
}