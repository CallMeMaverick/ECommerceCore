#include "authentication.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "fstream"
#include "authentication_validators/nameValidator/validateName.h"
#include "authentication_validators/passwordValidator/validatePassword.h"

using json = nlohmann::json;

namespace authentication
{
    void signUp(const std::string& username, const std::string &password)
    {
        // Validate name before proceeding
        try {
            validateName(username);
        }
        catch (std::invalid_argument& nameException) {
            std::cout << nameException.what() << std::endl;
            throw;
        }

        try {
            validatePassword(password);
        }
        catch (std::invalid_argument& passwordException) {
            std::cout << passwordException.what() << std::endl;
            throw;
        }


        // Define the file path where the user data JSON is stored.
        std::string filePath = "/Users/maverick/Desktop/ECommerceCore/ECommerceCore/data/authentication_data/auth.json";

        // JSON object to store all user data.
        json userData;

        // Try to open the existing JSON file.
        std::ifstream inputJson(filePath);
        if (inputJson.is_open())
        {
            try
            {
                inputJson >> userData;
                inputJson.close();
            }
            catch (json::parse_error& e)
            {
                // If there's a parse error, assume the file was empty or corrupted and start with a new JSON object.
                userData = json::object(); // Initialize userData as an empty object.
            }
        }

        // Check if the username's first letter exists as a key, if not -> initialize it as an empty array.
        if (!userData.contains(std::string(1, username[0])))
        {
            userData[std::string(1, username[0])] = json::array();
        }

        // Add the new user's username and password to the userData.
        userData[std::string(1, username[0])].push_back({ { "username", username }, { "password", password } });

        // Open the file in write mode to save the updated userData.
        std::ofstream outputJson(filePath);
        if (!outputJson.is_open())
            throw std::runtime_error("Could not open file for writing");

        // Write the updated userData back to the file.
        outputJson << userData.dump(4);
        outputJson.close();
    }
}