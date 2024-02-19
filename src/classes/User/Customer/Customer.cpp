#include "Customer.h"
#include "../../../authentication/authentication.h"

class User;

Customer::Customer(const std::string &username, const std::string &password): User{ username, password }, username{ username }, password{ password } {}

std::string Customer::getUsername() const { return this->username; }

std::string Customer::getPassword() const { return this->password; }

void Customer::signUp()
{
    authentication::signUp(getUsername(), getPassword());
}

void Customer::logIn()
{
    authentication::logIn(getUsername(), getPassword());
}

void Customer::deleteAccount()
{
    authentication::deleteAccount(getUsername(), getPassword());
}

void Customer::addToBasket(Product& product)
{
    basket.add_to_basket(product);
}

void Customer::printBasket()
{
    basket.view_basket();
}

void Customer::removeFromBasket(uint16_t ID)
{
    basket.remove_from_basket(ID);
}

void Customer::getData() const
{
    std::cout << "username: " << username << std::endl;
    std::cout << "password: " << password << std::endl;
    std::cout << "basket address: " << &basket << std::endl;
}

Basket* Customer::getBasketAddress()
{
    return &basket;
}