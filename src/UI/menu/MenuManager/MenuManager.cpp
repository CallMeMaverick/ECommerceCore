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
    auto auth = startAuthentication::execute();
    if (auth.result)
    {
        Catalog                                      catalog;
        int                                          entry;
        std::string                                  category;
        std::map<std::string, std::vector<Product>>  mappedCatalog;

        Customer                                     customer = *auth.customer;
        bool                                         continueExecution = true;

        while (continueExecution)
        {
            entry = manageInitialEntries::execute();
            catalog = loadCatalog();

            if (entry == 1)
            {
                category = manageInitialEntries::manageOptionShop();
                mappedCatalog = catalog.sortByCategory(category);
                std::cout << std::endl;
                iterateOver(mappedCatalog);

                manageAction::execute(customer, mappedCatalog, category);
            }
            else if (entry == 2)
                manageInitialEntries::manageBasket(customer);
            else if (entry == 3)
                manageInitialEntries::manageOptionManageAccount(customer, continueExecution);
            else if (entry == 4)
                continueExecution = false;
        }
    }

}