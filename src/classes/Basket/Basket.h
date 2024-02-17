#ifndef ECOMMERCECORE_BASKET_H
#define ECOMMERCECORE_BASKET_H

#pragma once
#include <vector>
#include "../Product/Product.h"

class Basket
{
private:
    std::vector<Product> basket;

public:
    static double amountToPay;

    /**
     * @brief Adds a product to the shopping basket.
     * @param product A constant reference to the Product to be added to the basket.
     */
    void add_to_basket(Product &product);

    /**
     * @brief Overloaded method to remove a product from the shopping basket by ID.
     *        In case product isn't in the basket, shows an appropriate message.
     * @param productID The ID of the product to be removed from the basket.
     */
    void remove_from_basket(uint16_t productID);

    /**
     * @brief Displays the contents of the shopping basket.
     */
    void view_basket();

    /**
     * @brief Calculates the total cost of the items in the shopping basket.
     * @return The total cost of all products in the basket as a double.
     */
    static double get_overall_amount_to_pay();
};


#endif //ECOMMERCECORE_BASKET_H
