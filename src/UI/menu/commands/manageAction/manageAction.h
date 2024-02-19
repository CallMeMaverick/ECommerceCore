#ifndef ECOMMERCECORE_MANAGEACTION_H
#define ECOMMERCECORE_MANAGEACTION_H

#include <iostream>
#include <map>
#include <vector>
#include "../../../../classes/Product/Product.h"
#include "../../../../classes/User/Customer/Customer.h"

/**
 * @class manageAction
 * @brief Provides static methods to manage customer actions such as executing an action, adding items, and deleting items.
 * @note The manageAction class relies on external definitions for the `Customer` and `Product` types, and it is assumed that these types are defined appropriately .
 */
class manageAction
{
public:
    /**
     * @brief Executes and manages the choices user makes after initial entries (for ref. see manageInitialEntries.h).
     * @param customer Reference to the customer on whom the action will be executed.
     * @param mapped Reference to the map of products.
     * @param currentCategory The category specifically for adding.
     */
    static void execute(Customer& customer, std::map<std::string, std::vector<Product>>& mapped, const std::string& currentCategory);

    /**
     * @brief Adds an item to the customer's vector of items based on the specified category
     * @param customer Reference to the customer whose vector will be modified
     * @param mapped Reference to the map of products
     * @param category The category to find vector's size
     */
    static void addItem(Customer& customer, std::map<std::string, std::vector<Product>>& mapped, const std::string& category);

    /**
     * @brief Deletes an item from the customer's vector.
     * @param customer Reference to the customer whose item will be deleted.
     */
    static void deleteItem(Customer& customer);

    manageAction() = delete;    // <-- Prevents instantiation of the class.
    ~manageAction() = default;  // <-- Defaulted destructor, allows derived classes to clean up.
};


#endif //ECOMMERCECORE_MANAGEACTION_H
