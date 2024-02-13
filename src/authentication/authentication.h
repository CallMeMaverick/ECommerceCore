#ifndef ECOMMERCECORE_AUTHENTICATION_H
#define ECOMMERCECORE_AUTHENTICATION_H

#pragma once
#include "string"

namespace authentication
{
    /**
     * @brief Registers a new user by adding their credentials to a JSON file.
     * @param username The username of the new user. It must be unique among all users.
     * @param password The password for the new user. It should meet the security criteria.
     */
    void signUp(const std::string &username, const std::string &password);

    /**
     * @brief Authenticates a user by comparing the provided credentials against those in a JSON file.
     * @param username The username of the user attempting to log in.
     * @param password The password provided by the user for login.
     */
    bool logIn(const std::string &username, const std::string &password);
}


#endif //ECOMMERCECORE_AUTHENTICATION_H
