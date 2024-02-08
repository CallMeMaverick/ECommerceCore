#include "classes/Catalog/Catalog.h"
#include "services/catalogLoader/loadCatalog.h"

int main()
{
    Catalog catalog = loadCatalog();
    catalog.print_catalog();

    return 0;
}