#ifndef ECOMMERCECORE_VALIDATEPASSWORD_H
#define ECOMMERCECORE_VALIDATEPASSWORD_H

#pragma once
#include <string>

/**
 * @brief Validates user password according to the following rulse:
 *        \n*Password must be at least 6 characters long
 *        \n*Password must include at least one special characters ~@@#$%^&*\_
 *        \n*Password must include both lower- and uppercase letters
 *        \n*Password cannot contain spaces
 * @param password std::string (password) to be validated
 * @return boolean value (either true of false), indicating whether name has been validated successfully or not
 */
bool validatePassword(const std::string &password);

#endif //ECOMMERCECORE_VALIDATEPASSWORD_H
