#include "startAuthentication.h"
#include "../../../../authentication/authentication.h"
#include "../../../../../include/colorCodes/colorCodes.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string>


AuthenticationResult startAuthentication::execute()
{
    // Variable for option chose by the user
    uint16_t optionChosen;

    std::string username;  // <-- to store username
    std::string password;  // <-- to store password

    std::cout << "1. Log In\n2. Sign Up\n0. Exit\n==> ";
    std::cin >> optionChosen;

    // Keep prompting the user to choose an option from those suggested above
    while (optionChosen < 0 || optionChosen > 2) {
        std::cout << RED_COLOR << "Choose correctly: " << RESET_COLOR;
        std::cin >> optionChosen;
    }

    if (optionChosen == 0)  // <-- stop executing and return false
        return { false, {} };
    else if (optionChosen == 1)
    {
        std::cout << "\nUsername: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        try
        {
            // call logIn function from authentication namespace
            if (authentication::logIn(username, password))
                std::cout << GREEN_COLOR <<  "Successfully logged in" << RESET_COLOR << std::endl;
            else
                return { false, {} };

            Customer customer = { username, password };
            // if exception hasn't yet been thrown, return true and stop the executing
            return { true, customer };
        }
        catch (const std::invalid_argument& exp)
        {
            // return false otherwise
            std::cout << RED_COLOR <<  "---> " << exp.what() << " <---" << RESET_COLOR << std::endl;
            return { false, {} };
        }
    }
    else if (optionChosen == 2)
    {
        /*
         * Show the requirements to the user in case of signing up;
         * Requirements can be found in "authentication/authentication_validators/..." functions
         * */
        std::cout << std::endl;
        std::cout << BOLD_TEXT << MAGENTA_COLOR << "*** Requirements: ***" << RESET_COLOR << RESET_COLOR << "\nUsername:" << std::endl;
        std::cout << MAGENTA_COLOR << " ---> Name length must be in range [4, 20];\n"
                                      " ---> First character must be alphabetical lowercase character\n"
                                      " ---> Username cannot contain spaces\n"
                                      " ---> Out of spacial characters only '_' (underscore) can be used " << RESET_COLOR << std::endl;
        std::cout << "\n\nPassword:" << std::endl;
        std::cout << MAGENTA_COLOR << " ---> Password must be at least 6 characters long\n"
                                      " ---> Password must include at least one special characters ~@#$%^&*\\_\n"
                                      " ---> Password must include both lower- and uppercase letters\n"
                                      " ---> Password cannot contain spaces" << RESET_COLOR << std::endl;

        std::cout << "\nUsername: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        try
        {
            // call signUp function from authentication namespace
            if (authentication::signUp(username, password))
                std::cout << GREEN_COLOR <<  "Successfully signed up" << RESET_COLOR << std::endl;
            else
                return { false, {} };

            Customer customer = { username, password };
            // if exception hasn't yet been thrown, return true and stop the executing
            return { true, customer };
        }
        catch (const std::invalid_argument& exp)      // <-- process invalid_argument exception
        {
            std::cout << RED_COLOR <<  "---> " << exp.what() << " <---" << RESET_COLOR << std::endl;
            return { false, {} };
        }
        catch (const std::runtime_error& exp)         // <-- process runtime_error exception
        {
            std::cout << RED_COLOR <<  "---> " << exp.what() << " <---" << RESET_COLOR << std::endl;
            return { false, {} };
        }
        catch (nlohmann::json::parse_error& jsonExp)  // <-- process json::parse_error exception
        {
            std::cout << RED_COLOR <<  "---> " << jsonExp.what() << " <---" << RESET_COLOR << std::endl;
            return { false, {} };
        }

        /*
         * For more reference on exceptions handled see the implementation of authentication::signUp function
         * */
    }
}