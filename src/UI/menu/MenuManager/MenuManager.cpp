#include "MenuManager.h"
#include "../authenticationProcess/startAuth/startAuthentication.h"
#include "../commands/initialEntries/manageInitialEntries.h"
#include "../commands/manageAction/manageAction.h"
#include "../../../services/catalogLoader/loadCatalog.h"
#include "../../../services/mapTraverser/iterateOver.h"
#include <string>
#include <vector>
#include <map>


void MenuManager::execute()
{
    // Authentication process, returns struct { boolean, CustomerObject }
    auto auth = startAuthentication::execute();
    if (auth.result)  // if authentication is successful
    {
        // Initialize all variables required for the execution
        Catalog                                      catalog;                   // <-- Catalog object to have full products loaded
        int                                          entry;                     // <-- Entry to manage
        std::string                                  category;                  // <-- Category to sort catalog by
        std::map<std::string, std::vector<Product>>  mappedCatalog;             // <-- Mapped Catalog to store map object of categorized catalog

        Customer                                     customer = *auth.customer; // <-- Customer object from authentication
        bool                                         continueExecution = true;  // <-- Flag for while loop

        while (continueExecution)
        {
            // Get the entry from the user
            entry = manageInitialEntries::execute();
            // Load catalog
            catalog = loadCatalog();

            if (entry == 1)  // <-- process the entry obtained
            {
                // Get the category to categorize catalog by from the user
                category = manageInitialEntries::manageOptionShop();
                // Create categorized map object of products
                mappedCatalog = catalog.sortByCategory(category);
                // Print categorized map object of products
                std::cout << std::endl;
                iterateOver(mappedCatalog);

                // Process further actions done on catalog
                manageAction::execute(customer, mappedCatalog, category);
            }
            else if (entry == 2)
                manageInitialEntries::manageBasket(customer);                                    // <-- Manage options for basket
            else if (entry == 3)
                manageInitialEntries::manageOptionManageAccount(customer, continueExecution); // <-- Manage options for account
            else if (entry == 4)
                continueExecution = false;                                                          // <-- Stop the execution
        }
    }

}