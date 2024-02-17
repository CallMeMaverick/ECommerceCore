#include "Basket.h"

double Basket::amountToPay{ 0 };  // Initialize static variable

void Basket::add_to_basket(Product &product)
{
    basket.push_back(product);                // push the product
    amountToPay += product.getProductPrice(); // and add it price
}


void Basket::remove_from_basket(uint16_t productID)
{
    for (int i = 0; i < basket.size(); i++)
    {
        if (basket[i].getProductID() == productID)    // Find the product
        {
            basket.erase(basket.begin() + i); // Delete it from vector
            return;                                   // Immediately stop the execution
        }
    }

    // Message in case product hasn't been found
    std::cerr << "Product with such an ID hasn't been found" << std::endl;
}

void Basket::view_basket()
{
    for (int i = 0; i < basket.size(); i++)
    {
        std::cout << i + 1 << ") ";
        std::cout << "Name: " << basket[i].getProductName() << ", ";
        std::cout << "ID: " << basket[i].getProductID() << ", ";
        std::cout << "Category: " << basket[i].getProductCategory() << ", ";
        std::cout << "Price: " << basket[i].getProductPrice() << std::endl;
    }
}

double Basket::get_overall_amount_to_pay() { return amountToPay; }