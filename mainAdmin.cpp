#include "AdminMenu.h"
#include "Configurations.h"

int main()
{
    AdminMenu amenu = AdminMenu(actorsFile, perfomancesFile, theatre);
    amenu.run();

    return 0;
}

