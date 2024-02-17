#include "authentication.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "fstream"
#include "authentication_validators/nameValidator/validateName.h"
#include "authentication_validators/passwordValidator/validatePassword.h"

using json = nlohmann::json;

namespace authentication
{
    bool signUp(const std::string& username, const std::string &password)
    {
        // Validate name before proceeding
        try {
            validateName(username);
        }
        catch (std::invalid_argument& nameException) {
            throw nameException;
        }

        try {
            validatePassword(password);
        }
        catch (std::invalid_argument& passwordException) {
            throw passwordException;
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
        {
            throw std::runtime_error("Could not open file for writing");
        }


        // Write the updated userData back to the file.
        outputJson << userData.dump(4);
        outputJson.close();

        return true;
    }

    bool logIn(const std::string &username, const std::string &password)
    {
        // Validate both username and password
        try {
            validateName(username);
            validatePassword(password);
        }
        catch (const std::invalid_argument& exception) {
            // Here it states that user doesn't exist because if, when signing up,
            // user didn't pass the validation, they could not register,
            // so invalid usernames or passwords are not in auth.json
            throw std::invalid_argument("User does not exist");
        }

        std::ifstream jsonFileRead("/Users/maverick/Desktop/ECommerceCore/ECommerceCore/data/authentication_data/auth.json");
        json readData;
        if (jsonFileRead.is_open())
        {
            try {
                jsonFileRead >> readData;
                jsonFileRead.close();
            }
            catch (json::parse_error& e) {
                std::cout << e.what() << std::endl;
                throw;
            }

            // If data has been read, proceed by iterating over JSON object
            for (auto& [key, user] : readData.items())
            {
                // Compare the key (which is the letter we group users by),
                // with the first letter of given username
                if (key[0] == username[0])
                {
                    // If found, now iterate over JSON object,
                    // and compare username and password given with those object has
                    for (auto& userData : user)
                    {
                        if (userData["username"] == username && userData["password"] == password)
                        {
                            return true;  // <-- return true if user has been found
                        }
                    }

                    std::cout << "User hasn't been found" << std::endl;
                    return false;  // <-- return false if user hasn't been found
                }
            }
        }
        return false;  // <-- return false if user hasn't been found
    }

    bool deleteAccount(const std::string &username, const std::string &password)
    {
        // Validate both username and password
        try {
            validateName(username);
            validatePassword(password);
        }
        catch (const std::invalid_argument& exp) {
            throw std::invalid_argument("User does not exist");
        }

        std::ifstream jsonFile("/Users/maverick/Desktop/ECommerceCore/ECommerceCore/data/authentication_data/auth.json");
        json data;

        if (jsonFile.is_open())
        {
            bool deleted = false;

            try {
                jsonFile >> data;
                jsonFile.close();
            }
            catch (json::parse_error& exp) {
                std::cout << exp.what() << std::endl;
                throw;
            }


            for (auto& [key, user] : data.items())
            {
                if (key[0] == username[0])
                {
                    // Traverse the array with iterator
                    for (auto it = user.begin(); it != user.end(); ++it)
                    {
                        if ((*it)["username"] == username && (*it)["password"] == password)
                        {
                            // Removes the element 'it' points to
                            user.erase(it);
                            deleted = true;
                            break;
                        }
                    }
                    if (deleted) break;
                }
            }

            // Update JSON file
            if (deleted)
            {
                std::ofstream outFile("/Users/maverick/Desktop/ECommerceCore/ECommerceCore/data/authentication_data/auth.json");
                if (!outFile.is_open()) {
                    std::cerr << "Failed to open the JSON file for writing." << std::endl;
                    return false;
                }
                outFile << data.dump(4);
                outFile.close();
                return true;
            }
            return false;
        }

        return false;
    }
}