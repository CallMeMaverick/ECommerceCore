#include "loadCatalog.h"
#include "../../../config/resources/importConfig.h"
#include "fstream"
#include "sstream"

Catalog loadCatalog()
{
    Catalog catalog;

    std::fstream currentStream(config_import::GET_CATALOG_PATH());

    if (!currentStream.is_open())
    {
        return catalog;
    }

    std::string line;
    getline(currentStream, line);

    while (getline(currentStream, line))
    {
        Product product;

        std::istringstream ss(line);
        std::string token;

        getline(ss, token, ',');
        product.productID = stoi(token);

        getline(ss, product.productName, ',');

        getline(ss, product.productCategory, ',');

        getline(ss, token, ',');
        product.productPrice = stof(token);

        catalog.push_to_database(product);
    }

    return catalog;
}