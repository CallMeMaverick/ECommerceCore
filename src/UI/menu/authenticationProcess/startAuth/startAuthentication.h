#ifndef ECOMMERCECORE_STARTAUTHENTICATION_H
#define ECOMMERCECORE_STARTAUTHENTICATION_H

#include <iostream>
#include <optional>
#include "../../../../classes/User/Customer/Customer.h"

/**
 * @struct AuthenticationResult
 * @brief Represents the results of authentication attempt
 *
 * This structure is used to encapsulate the outcome of an authentication process,
 * including whether the authentication was successful and, if so, an instance of
 * the authenticated Customer. It is designed to provide a convenient way to return
 * both the status of the authentication and the authenticated user's information
 * from functions or methods that perform authentication.
 *
 * @note This structure uses std::optional to represent the Customer instance.
 */
struct AuthenticationResult {
    bool result;                        // <-- either true of false (success / failure)
    std::optional<Customer> customer;   // <-- Customer object
};

/**
 * @class startAuthentication
 * @brief Handles the authentication process for the application.
 *
 * This class encapsulates the functionality required for authenticating users. It supports
 * operations necessary for the authentication process, such as logging in or signing up users.
 * The authentication outcome determines how the application proceeds, either granting access
 * to further functionalities or denying it based on the authentication result.
 */
class startAuthentication
{
public:
    /**
     * @brief Executes the authentication process.
     * @return True if the user successfully signs up or logs in, false otherwise. A return value
     * of true indicates that the user has been authenticated, and the application can proceed
     * to the next stage. A return value of false suggests that the authentication failed, which
     * could be due to invalid credentials, user cancellation, or other errors during the
     * authentication process.
     */
    static AuthenticationResult execute();

    /**
     * @brief Destructor for the startAuthentication class.
     *
     * The default destructor is specified to ensure proper cleanup of resources when instances
     * of the class (if any are ever created despite the static nature of the intended usage) are
     * destroyed.
     */
    ~startAuthentication() = default;
};


#endif //ECOMMERCECORE_STARTAUTHENTICATION_H
