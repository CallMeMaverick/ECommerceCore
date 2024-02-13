#ifndef ECOMMERCECORE_VALIDATENAME_H
#define ECOMMERCECORE_VALIDATENAME_H

#pragma once
#include <string>

/**
 * @brief Validates username according to the following rules:
 *        \n* Name length must be in range [4, 20];
 *        \n* First character must be alphabetical lowercase character
 *        \n* Username cannot contain spaces
 *        \n* Out of spacial characters only '_' (underscore) can be used
 * @param username std::string (username) to be validated
 * @return boolean value (either true of false), indicating whether name has been validated successfully or not
 */
bool validateName(const std::string &username);

#endif //ECOMMERCECORE_VALIDATENAME_H
