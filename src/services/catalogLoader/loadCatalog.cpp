#include "loadCatalog.h"
#include "../../../config/resources/importConfig.h"
#include "fstream"
#include "sstream"

// forward declaration for Product class
class Product;

// forward declaration for Catalog class
class Catalog;

// forward declaration for the function to add a product to the database
void push_to_database(Product product);

Catalog loadCatalog()
{
    // Load the configuration which includes the catalog path
    config_import::Config config = config_import::importConfig(config_import::GET_CATALOG_PATH());

    // Get the absolute path to the catalog CSV file from the configuration
    std::string path = config.CATALOG_ABSOLUTE_PATH;

    // Open the CSV file using the path from the configuration
    std::fstream currentStream(path);
    if (!currentStream.is_open())
    {
        std::cerr << "Failed to open catalog file at " << path << std::endl;
        throw std::runtime_error("Unable to open catalog file.");
    }

    std::string line;
    // Skip the header line
    std::getline(currentStream, line);

    Catalog catalog;

    // Read and parse the CSV file
    while (getline(currentStream, line))
    {
        std::istringstream ss(line);
        std::string token;
        Product product;

        getline(ss, token, ',');
        product.productID = std::stoi(token);

        getline(ss, product.productName, ',');

        getline(ss, product.productCategory, ',');

        getline(ss, token, ',');
        product.productPrice = stof(token);

        // Here you'd call a method or function to add the product to the catalog.
        // This function or method should be defined elsewhere in your code.
        catalog.push_to_database(product);
    }

    return catalog;
}