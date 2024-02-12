#include "authentication.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "fstream"

using json = nlohmann::json;

namespace authentication
{
    void singUp(const std::string& username, const std::string &password)
    {
        // Initialize map, where each key is a char and each value is JSON array.
        std::map<char, json> userMap;
        // Add the new user's username and password to the map.
        // The username's first character is used as the key, and the user's data is pushed into a JSON array.
        userMap[username[0]].push_back({ { "username", username }, { "password", password } });

        // JSON object to store all user data.
        json userData;

        // Iterate over the map to transfer users grouped by their first letter into the userData JSON object.
        /*
          "first_letter": [
                {
                    "password": "...",
                    "username": "..."
                }
            ]
         */
        for (const auto &kvp : userMap)
        {
            std::string key(1, kvp.first);  // <-- Convert the char key to a string.
            userData[key] = kvp.second;          // <-- Assign the JSON array to the corresponding key in userData.
        }

        // Define the file path where the user data JSON will be saved.
        // Note: The absolute path is used here, which is not flexible or portable.
        std::ofstream openJson("/Users/maverick/Desktop/ECommerceCore/ECommerceCore/data/authentication_data/auth.json");
        if (!openJson.is_open())
            throw std::runtime_error("Could not open a file");
        else
        {
            openJson << userData.dump(4);
            openJson.close();
        }
    }
}