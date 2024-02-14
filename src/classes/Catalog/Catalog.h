#ifndef ECOMMERCECORE_CATALOG_H
#define ECOMMERCECORE_CATALOG_H

#pragma once
#include <vector>
#include "../Product/Product.h"
#include <map>

// forward declaration for Product class
class Product;

class Catalog
{
private:
    std::vector<Product> catalog;

public:
    /**
     * @brief Adds a product to the catalog.
     * @param product product A constant reference to the Product instance to be added to the catalog.
     */
    void push_to_database(const Product &product);

    /**
     * @brief Displays all items in the catalog.
     */
    void print_catalog();

    /**
     * @brief Overloaded [] operator, provides access to a product in the catalog by index.
     *        If index < 0, returns the first object in database.
     *        If index > database.size() - 1, return the last element in database
     * @param index The index of the product to access in the catalog.
     * @return A reference to the Product at the given index in the catalog.
     */
    Product& operator [] (int index);

    /**
     * @brief Organizes and returns products sorted by their categories.
     * @return A map with category names as keys and vectors of Product objects as values. Each vector contains
     *         all products belonging to the corresponding category key. If the catalog contains no products,
     *         the returned map will be empty.
     */
    std::map<std::string, std::vector<Product>> sortByCategory();
};


#endif //ECOMMERCECORE_CATALOG_H
