#include "Customer.h"
#include "../../../authentication/authentication.h"
#include "../../../../include/colorCodes/colorCodes.h"

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

bool Customer::deleteAccount()
{
    return authentication::deleteAccount(getUsername(), getPassword());
}

void Customer::addToBasket(Product& product)
{
    basket.add_to_basket(product);
}

void Customer::printBasket()
{
    basket.view_basket();
}

void Customer::printBasketStyled()
{
    basket.view_basket_for_removing();
}

bool Customer::removeFromBasket(uint16_t ID)
{
    return basket.remove_from_basket(ID);
}

void Customer::getData() const
{
    std::cout << CYAN_COLOR << "\nusername: " << RESET_COLOR << username << std::endl;
    std::cout << CYAN_COLOR << "password: " << RESET_COLOR << password << std::endl;
    std::cout << CYAN_COLOR << "basket address: " << RESET_COLOR << &basket << std::endl;
}

Basket* Customer::getBasketAddress()
{
    return &basket;
}