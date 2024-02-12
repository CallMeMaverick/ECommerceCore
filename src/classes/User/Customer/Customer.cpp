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