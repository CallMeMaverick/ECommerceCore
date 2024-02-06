#include "Product.h"

std::string Product::getProductName()      { return productName; }

double Product::getProductPrice()          { return productPrice; }

uint16_t Product::getProductID()           { return productID; }

std::string Product::getProductCategory()  { return productCategory; }

std::ostream &operator << (std::ostream &out, Product &object)
{
    out << "Name: " << object.getProductName() << ", ";
    out << "ID: " << object.getProductID() << ", ";
    out << "Category: " << object.getProductCategory() << ", ";
    out << "Price: " << object.getProductPrice() << std::endl;
    return out;

}