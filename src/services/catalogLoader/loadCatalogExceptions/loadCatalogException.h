#ifndef ECOMMERCECORE_LOADCATALOGEXCEPTION_H
#define ECOMMERCECORE_LOADCATALOGEXCEPTION_H

#include <exception>
#include <string>

/**
 * loadCatalogException is an exception that indicates that there was an error while loading the product catalog.
 *
 * This exception is thrown when the catalog data cannot be read properly, if the file is not found,
 * or the data format does not match the expected format.
 *
 * Parameters:
 *   - errorMessage: A string detailing the error. This message is returned when what() is called.
 *
 * Usage:
 *   throw loadCatalogException("Could not load the catalog file");
 *
 * Inheritance: Inherits from std::exception, with an override of the what() function to provide a custom error message.
 */
class loadCatalogException : public std::exception
{
private:
    std::string errorMessage;

public:
    explicit loadCatalogException(std::string errorMessage): errorMessage{std::move( errorMessage )} {}

    const char* what() const noexcept override { return errorMessage.c_str(); }
};


#endif //ECOMMERCECORE_LOADCATALOGEXCEPTION_H
