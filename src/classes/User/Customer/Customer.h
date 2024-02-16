#ifndef ECOMMERCECORE_CUSTOMER_H
#define ECOMMERCECORE_CUSTOMER_H

#include <string>
#include "../User.h"
#include "../../Basket/Basket.h"

// Forward declaration of User class to avoid circular dependency
class User;

/**
 * Customer class, derived from User, represents a customer.
 * It manages customer-specific attributes and behaviors such as signing up, logging in,
 * managing their account, and handling their shopping basket.
 */
class Customer : public User
{
private:
    std::string username;
    std::string password;
    Basket basket;

public:
    Customer(const std::string &username, const std::string &password);

    std::string getUsername() const override;

    std::string getPassword() const override;

    void signUp() override;

    void logIn() override;

    void deleteAccount() override;

    void addToBasket(Product& product) override;

    void printBasket() override;

    void removeFromBasket(uint16_t ID) override;
//
//    void getData() const override;
};


#endif //ECOMMERCECORE_CUSTOMER_H
