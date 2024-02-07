#ifndef ECOMMERCECORE_PRODUCT_H
#define ECOMMERCECORE_PRODUCT_H

#pragma once
#include <iostream>
#include "../../services/catalogLoader/loadCatalog.h"

class Product
{
private:
    std::string productName;
    double productPrice;
    uint16_t productID;
    std::string productCategory;

public:
    /**
     * @brief getter for product's name
     * @return string, product's name
     */
    std::string getProductName();

    /**
     * @brief getter for product's price
     * @return double, price of a product
     */
    double getProductPrice();

    /**
     * @brief getter for product's ID
     * @return unsigned integer 16 bytes, product's ID
     */
    uint16_t getProductID();

    /**
     * @brief getter for product's category
     * @return string, product's category
     */
    std::string getProductCategory();

    /**
     * @brief Overloads the << operator to output the details of a Product object.
     * @param out Reference to the output stream (e.g., std::cout or any std::ostream object).
     * @param obj Reference to the Product object whose details are to be printed.
     * @return std::ostream& Reference to the output stream for chaining output operations.
     */
    friend std::ostream& operator << (std::ostream& out, Product& obj);

    friend Catalog loadCatalog();
};


#endif //ECOMMERCECORE_PRODUCT_H
