#include "displayOptions.h"
#include <iostream>

void displayMenu::execute()
{
    uint16_t optionChosen;

    std::cout << "1. Shop\n2. Manage Account\n==> ";
    std::cin >> optionChosen;

    while (optionChosen < 1 || optionChosen > 2)
    {
        std::cout <<
    }
}