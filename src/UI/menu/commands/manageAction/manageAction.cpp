#include "manageAction.h"
#include "../../../../../include/colorCodes/colorCodes.h"
#include "../../../../services/getFromMap/getFromMap.h"
#include "../../../../services/mapTraverser/iterateOver.h"

void manageAction::execute(Customer& customer, std::map<std::string, std::vector<Product>>& mapped, const std::string& currentCategory)
{
    uint16_t action;

    std::cout << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "1. " << RESET_COLOR << RESET_COLOR << "Add item" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "2. " << RESET_COLOR << RESET_COLOR << "Delete item from basket" << std::endl;
    std::cout << BLUE_COLOR << BOLD_TEXT << "3. " << RESET_COLOR << RESET_COLOR << "Leave the page\n==> ";
    std::cin >> action;

    while (action < 1 || action > 3)
    {
        std::cout << RED_COLOR << "Choose carefully: " << RESET_COLOR;
        std::cin >> action;
    }

    if (action == 1)
    {
        addItem(customer, mapped, currentCategory);
        customer.printBasket();
        std::cout << BOLD_TEXT << "Overall amount: " << RESET_COLOR << GREEN_COLOR << Basket::get_overall_amount_to_pay() << RESET_COLOR << std::endl;
    }
    else if (action == 2) { customer.printBasket(); deleteItem(customer); }
    else if (action == 3) { return; }

}

void manageAction::addItem(Customer &customer, std::map<std::string, std::vector<Product>> &mapped, const std::string& category)
{
    size_t vectorSize;

    if (mapped.find(category) != mapped.end())
        vectorSize = mapped[category].size();

    int index;
    std::cout << "\nNumber of item in list to add: ";
    std::cin >> index;


    while (index < 1 || index > vectorSize)
    {
        std::cout << RED_COLOR << "Choose carefully " << RESET_COLOR;
        std::cin >> index;
    }

    Product* productToAdd = getFromMap(mapped, index);
    customer.addToBasket(*productToAdd);

    std::cout << BLUE_COLOR << BOLD_TEXT << "\nItem has been successfully added\n" << RESET_COLOR << RESET_COLOR << std::endl;
}

void manageAction::deleteItem(Customer &customer)
{
    Basket *test = customer.getBasketAddress();
    if (test->getBasketSize() == 0)
    {
        std::cout << MAGENTA_COLOR << BOLD_TEXT << "\nBasket is empty; Nothing to manage" << RESET_COLOR << RESET_COLOR << std::endl;
        return;
    }

    int ID;
    std::cout << "Enter ID of item to delete: ";
    std::cin >> ID;

    if (customer.removeFromBasket(ID))
        std::cout << MAGENTA_COLOR << BOLD_TEXT << "\nItem has been successfully deleted" << RESET_COLOR << RESET_COLOR << std::endl;

    customer.printBasket();
}