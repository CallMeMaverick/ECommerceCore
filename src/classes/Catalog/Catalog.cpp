#include "Catalog.h"

void Catalog::push_to_database(const Product &product) { catalog.push_back(product); }

void Catalog::print_catalog()
{
    for (auto& category : this->sortByCategory()) {
        std::cout << "\n\nCategory: " << category.first << std::endl;
        for (auto& product : category.second) {
            std::cout << "Product ID: " << product.getProductID()
                      << ", Name: " << product.getProductName()
                      << ", Price: $" << product.getProductPrice() << std::endl;
        }
    }
}

void Catalog::print_catalog(const std::string &categoryToPrint)
{
    // Convert to capitalized string
    std::string lowercaseInput;
    for (size_t i = 0; i < categoryToPrint.size(); i++)
    {
        char c = categoryToPrint[i];

        if (i == 0)
        {
            if (!(c >= 'A' && c <= 'Z'))
                lowercaseInput += (char)(c - 32);
            else
                lowercaseInput += c;
        }
        else
        {
            if ((c >= 'A' && c <= 'Z'))
                lowercaseInput += (char)(c + 32);
            else
                lowercaseInput += c;
        }
    }

    for (auto& category : this->sortByCategory()) {
        if (category.first == lowercaseInput)
        {
            for (auto& product : category.second) {
                std::cout << "Product ID: " << product.getProductID()
                          << ", Name: " << product.getProductName()
                          << ", Price: $" << product.getProductPrice() << std::endl;
            }
        }
    }
}

Product& Catalog::operator[](int index)
{
    if (index < 0) return catalog[0];
    else if (index > catalog.size() - 1) return catalog[catalog.size() - 1];
    else return catalog[index];
}

std::map<std::string, std::vector<Product>> Catalog::sortByCategory()
{
    // Create a map to store products categorized by their category name.
    std::map<std::string, std::vector<Product>> productsByCategory;
    // Traverse the entire catalog vector that contains the initial set of products.
    for (auto& product : catalog) {
        // Access (or create if it doesn't exist) the vector of products for the current product's category,
        // and add the current product to this vector. The map key is the product's category,
        // and the value is a vector containing all products within that category.
        productsByCategory[product.getProductCategory()].push_back(product);
    }
    return productsByCategory;
}