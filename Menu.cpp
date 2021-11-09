#include "Menu.h"

Menu::Menu(const Theatre t) : theatre(t)
{
    userInput = Answer(menuCount);
}

void Menu::start()
{
    std::cout << "\n\nWelcome to the " << theatre.getName() << " theatre!\n\n";
}

void Menu::showMainMenu()
{
    std::cout << "Choose an action: \n";

    std::cout << "1. Show perfomances\n";
    std::cout << "0. Exit\n";
}

void Menu::showPerfomancesMenu()
{
    theatre.refresh();
    std::vector<Perfomance> perfs = theatre.getPerfomances();

    std::cout << "\n\nSelect a perfomance: \n";

    for (int i = 0; i < perfs.size(); i++)
    {
        std::cout << i + 1 << ". " << perfs[i].getName() << '\n';
    }

    std::cout << "0. Exit\n";

    getAndHandle(PERFOMANCES_MENU, perfs.size() + 1);
}

void Menu::showTicketMenu()
{
    std::cout << "\n\n1. Order a ticket\n";
    std::cout << "0. Exit\n";

    getAndHandle(TICKET_MENU, TICKET_MAX);
}

void Menu::getAnswer(const int index, const int max)
{
    int ans;

    while (!scanf(" %d", &ans) || (ans >= max) || (ans < 0))
    {
        std::cout << "Wrong answer!\n";
        while(getchar() != '\n');
    }

    userInput.setAnswer(ans, index);
}

void Menu::handleUserInput(const int index)
{
    switch(index)
    {
        case MAIN_MENU:
            handleMainMenu();
            break;
        case PERFOMANCES_MENU:
            handlePerfomancesMenu();
            break;
        case TICKET_MENU:
            handleTicketMenu();
            break;
    }
}

void Menu::getAndHandle(const int index, const int max)
{
    getAnswer(index, max);
    handleUserInput(index);
}

void Menu::handleMainMenu()
{
    switch(userInput.getAnswer(MAIN_MENU))
    {
        case 1:
            showPerfomancesMenu();
            break;
        case 0:
            return;
    }
}

void Menu::handlePerfomancesMenu()
{
    int ans = userInput.getAnswer(PERFOMANCES_MENU);

    if (!ans)
    {
        run();
        return;
    }

    theatre.refresh();
    std::cout << '\n' << theatre.getPerfomances()[ans - 1] << "\n\n";

    showTicketMenu();
}

void Menu::handleTicketMenu()
{
    switch(userInput.getAnswer(TICKET_MENU))
    {
        case 1:
            orderTicket(userInput.getAnswer(PERFOMANCES_MENU) - 1);
            break;
        case 0:
            showPerfomancesMenu();
            return;
    }
}

void Menu::orderTicket(int perfomance)
{
    Perfomance perf = theatre.getPerfomances()[perfomance];
    std::string name = perf.getName();
    int orders;

    try
    {
        std::string n = readFromFile(name);
        orders = std::stoi(n);
    }
    catch (...)
    {
        orders = 0;
    }

    writeToFile(name, std::to_string(++orders));

    std::cout << "\nTicket ordered!\n\n";
    std::cout << "The ticket was ordered " << orders << " times.\n\n";

    run();
    return;
}

void Menu::run()
{
    start();
    showMainMenu();
    getAndHandle(MAIN_MENU, MAIN_MAX);
}

