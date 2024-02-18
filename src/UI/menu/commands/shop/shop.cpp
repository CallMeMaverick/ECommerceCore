#include "shop.h"
#include "../../../../../include/colorCodes/colorCodes.h"
#include <iostream>

std::string shop::execute()
{
    uint16_t categoryChosen;

    std::cout << BLUE_COLOR << BOLD_TEXT << "1. " << RESET_COLOR << RESET_COLOR << "Books" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "2. " << RESET_COLOR << RESET_COLOR << "Toys" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "3. " << RESET_COLOR << RESET_COLOR << "Clothing" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "4. " << RESET_COLOR << RESET_COLOR << "Groceries" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "5. " << RESET_COLOR << RESET_COLOR << "Furniture" << std::endl;
    std::cout << "==> ";
    std::cin >> categoryChosen;

    while (categoryChosen < 1 || categoryChosen > 5)
    {
        std::cout << RED_COLOR << "Choose carefully: " << RESET_COLOR;
        std::cin >> categoryChosen;
    }

    switch (categoryChosen) {
        case 1: return "Books";
        case 2: return "Toys";
        case 3: return "Clothing";
        case 4: return "Groceries";
        case 5: return "Furniture";
        default: {};
    }
}