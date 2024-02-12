#include "User.h"
#include <string>

User::User(const std::string &username, const std::string &password):
    username{ username }, password{ password } {}
