#ifndef ECOMMERCECORE_USER_H
#define ECOMMERCECORE_USER_H

#include "string"

/**
 * The User class serves as an abstract class for users.
 * It provides interface for managing both account and basket.
 */
class User
{
private:
    std::string username;  // unique user identifier
    std::string password;  // user password

public:
    /**
     * @brief Constructs a new User with a given nickname and password.
     * @param username The username for the new user.
     * @param password The password for the new user.
     */
    User(const std::string &username, const std::string &password);

    /**
     * @brief Retrieves the username of the user.
     * @return std::string representing username
     */
    virtual std::string getUsername() const = 0;

    /**
     * @brief Retrieves the password of the user.
     * @return std::string representing password
     */
    virtual std::string getPassword() const = 0;

    /**
     * @brief A pure virtual function that handles the user sign-up process.
     * Implementations registers a new user account using the authentication namespace.
     */
    virtual void signUp() = 0;

    /**
     * @brief A pure virtual function that handles the user log-in process.
     * Implementations authenticates a user using the authentication namespace.
     */
    virtual void logIn() = 0;

    /**
     * @brief A pure virtual function that allows a user to delete their account.
     * Implementations removes all user data and associated records from the system.
     */
    virtual void deleteAccount() = 0;
//
//
//    /**
//     * @brief A pure virtual function for adding items to the user's shopping basket.
//     * Implementations allows a user to add an item to their basket using Basket class.
//     */
//    virtual void addToBasket() = 0;
//
//    /**
//     * @brief A pure virtual function for removing items from the user's shopping basket.
//     * Implementations should allow a user to remove an item from their basket using Basket class.
//     */
//    virtual void removeFromBasket() = 0;
//
//    /**
//     * A pure virtual function that provides user data.
//     * Implementations returns the user's data in a read-only format.
//     */
//    virtual void getData() const = 0;
};


#endif //ECOMMERCECORE_USER_H
