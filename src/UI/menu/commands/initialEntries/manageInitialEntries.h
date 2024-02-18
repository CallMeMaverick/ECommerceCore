#ifndef ECOMMERCECORE_MANAGEINITIALENTRIES_H
#define ECOMMERCECORE_MANAGEINITIALENTRIES_H

#include <string>
#include "../../../../classes/User/Customer/Customer.h"

/**
 * @class manageInitialEntries
 * @brief Manages the initial entry points for user interaction.
 *
 * This class is designed to handle the initial actions a user can take after
 * starting the application or completing the authentication process. It provides
 * static methods to execute different initial entry options, such as selecting
 * shopping options or managing account settings. The class is structured to not
 * allow instantiation, serving purely as a namespace for the related static
 * functions that represent actions a user can take.
 *
 * Usage of this class involves calling its static methods directly to initiate
 * different actions, such as shopping or account management, based on the user's
 * choices.
 */
class manageInitialEntries
{
public:
    /**
     * @brief Executes the main logic for managing initial entries.
     *
     * This method presents the user with the initial set of options or actions
     * they can take and handles the user's selection. It returns an integer
     * representing the outcome of the execution, which can be used to determine
     * the next steps in the application flow.
     *
     * @return int An integer code representing the result of the execution, which
     *         may correspond to specific actions or states to transition to.
     */
    static int execute();

    /**
     * @brief Presents shopping options to the user and handles their selection.
     *
     * This method allows the user to browse or select shopping options. It returns
     * a string representing the user's choice, which can be used to navigate the
     * shopping functionality of the application.
     *
     * @return std::string A string indicating the user's selected shopping option.
     */
    static std::string manageOptionShop();

    /**
     * @brief Manages account options for the given customer.
     *
     * This method provides the user with account management options such as
     * updating personal information or logging out. Actions taken within this
     * method affect the provided Customer object directly.
     *
     * @param customer A reference to the Customer object for whom the account
     *        management options should be managed. This object may be modified
     *        based on the user's selections.
     */
    static void manageOptionManageAccount(Customer& customer);

    /* Prevent instantiation of the class */
    manageInitialEntries() = delete;

    /* The destructor is defaulted, meaning no special clean-up is required */
    ~manageInitialEntries() = default;
};


#endif //ECOMMERCECORE_MANAGEINITIALENTRIES_H
