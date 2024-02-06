#ifndef ECOMMERCECORE_LOADCATALOG_H
#define ECOMMERCECORE_LOADCATALOG_H

#pragma once
#include "../../classes/Catalog/Catalog.h"

/**
 * @brief Loads the product data from a CSV file and constructs a Catalog object.
 * @return Catalog A Catalog object fully populated with Product data from the CSV file.
 */
Catalog loadCatalog();

#endif //ECOMMERCECORE_LOADCATALOG_H
