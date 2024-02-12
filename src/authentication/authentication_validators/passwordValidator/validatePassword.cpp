#include "validatePassword.h"
#include <string>

bool validatePassword(const std::string &password)
{
    // Password must contain at least 6 characters
    if (password.length() < 6)
        throw std::invalid_argument("--> Password length must be >= 6");

    // Variables for counting properties
    uint16_t lowerCaseCounter        = 0;
    uint16_t upperCaseCounter        = 0;
    uint16_t specialCharsCounter     = 0;
    uint16_t digitsCounter           = 0;
    uint16_t otherThanSpecialCounter = 0;

    for (size_t i = 0; i < password.length(); i++)
    {
        char c = password[i];
        // Check if character is lowercase
        if (islower(c)) {
            lowerCaseCounter++;
        }
            // Check if character is uppercase
        else if (isupper(c)) {
            upperCaseCounter++;
        }
            // Check if character is digit
        else if (isdigit(c)) {
            digitsCounter++;
        }
            // Check if character is one of the specified special characters
        else if (c == '~' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '\\' || c == '_') {
            specialCharsCounter++;
        }
            // Check if character is a space
        else if (isspace(c)) {
            throw std::invalid_argument("--> Password cannot contain spaces");
        }
            // If character does not match any of the above categories, it is considered "other"
        else {
            otherThanSpecialCounter++;
        }
    }

    if (otherThanSpecialCounter)
        throw std::invalid_argument("--> Password must contain at least one special character (~@#$%^&*\\)");
    if (lowerCaseCounter == 0 || upperCaseCounter == 0)
        throw std::invalid_argument("--> Password must contain both lower- and uppercase characters");
    if (digitsCounter == 0)
        throw std::invalid_argument("--> Password must contain digits");
    if (specialCharsCounter == 0)

    return true;
}