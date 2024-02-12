#include "validateName.h"
#include <string>

bool validateName(const std::string &username)
{
    // Username length must be in range [4, 20];
    if (username.length() <= 4 || username.length() >= 20)
        throw std::invalid_argument("--> Username length must be in range [4, 20]");

    // First character must be alphabetical lowercase character exclusively
    if (!isalpha(username[0]) || isdigit(username[0]) || !islower(username[0]))
        throw std::invalid_argument("--> First character must be alphabetical lowercase character exclusively");

    for (size_t i = 0; i < username.length(); i++)
    {
        // If username contains spaces
        if (isspace(username[i]))
            throw std::invalid_argument("--> Username cannot contain spaces");

        // If character is not alphanumeric
        if (!isalnum(username[i]))
        {
            // And not underscore (_) at the same time
            if (username[i] != '_')
                throw std::invalid_argument("--> Username can contain underscore '_' only");
        }
    }

    return true;
}