#include "Catalog.h"

void Catalog::push_to_database(const Product &product) { catalog.push_back(product); }

void Catalog::print_catalog()
{
    for (auto& product : catalog)
    {
        std::cout << "Name: " << product.getProductName() << ", ";
        std::cout << "ID: " << product.getProductID() << ", ";
        std::cout << "Category: " << product.getProductCategory() << ", ";
        std::cout << "Price: " << product.getProductPrice() << std::endl;
    }
}

Product& Catalog::operator[](int index)
{
    if (index < 0) return catalog[0];
    else if (index > catalog.size() - 1) return catalog[catalog.size() - 1];
    else return catalog[index];
}