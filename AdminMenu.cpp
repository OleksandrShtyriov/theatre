#include "AdminMenu.h"
#include "AdminHandler.h"

AdminMenu::AdminMenu() { }

void AdminMenu::checkPassword()
{
    std::string str;

    std::cout << "Input the password: \n";
    std::cin >> str;

    if (str != password)
    {
        std::cout << "Wrong password!\n";

        throw 1;
    }
}

AdminMenu::AdminMenu(const std::string file, const std::string perfFile, Theatre theatre) : Menu(theatre)
{
    checkPassword();

    this->file = file;
    this->perfFile = perfFile;

    userInput = Answer(menuCountAdmin);
}

void AdminMenu::start()
{
    std::cout << "You have entered as an administrator.\n";
}

void AdminMenu::showMainMenu()
{
    std::cout << "\n\nChoose an action: \n";

    std::cout << "1. Add a perfomance\n";
    std::cout << "2. Edit a perfomance\n";
    std::cout << "3. Remove a perfomance\n";
    std::cout << "0. Exit\n";
}

void AdminMenu::addPerfomanceMenu()
{
    std::string name;

    std::cout << "Input the name of the perfomance: ";
    std::cin >> name;

    appendToFile(perfFile, name);

    std::cout << "Perfomance added!\n";
}

void AdminMenu::editPerfomanceMenu()
{
    std::cout << "\n\nSelect an option: \n";

    std::cout << "1. Add an actor\n";
    std::cout << "2. Remove an actor\n";
    std::cout << "0. Exit\n";

    getAndHandle(EDIT_PERFOMANCE_MENU, EDIT_PERFOMANCE_MAX);
}

void AdminMenu::addActorMenu()
{
    std::string name;
    std::string role;
    std::string perfName;

    std::cout << "Input the name of the actor: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Input the role of the actor: ";
    std::getline(std::cin, role);

    std::cout << "Input the name of the perfomance: ";
    std::getline(std::cin, perfName);

    std::vector<Perfomance> perfs = theatre.getPerfomances();
    bool found = 0;

    for (int i = 0; i < perfs.size(); i++)
    {
        if (perfName == perfs[i].getName())
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        throw -1;
    }

    appendToFile(file, name + "\n" + role + "\n" + perfName);
}

void AdminMenu::removeActorMenu()
{
    std::string name;
    std::string role;
    std::string perf;

    std::cin.ignore();
    std::cout << "Input the actor's name: ";
    std::getline(std::cin, name);

    std::cout << "Input his role: ";
    std::getline(std::cin, role);

    std::cout << "Input the perfomance where he is playing: ";
    std::getline(std::cin, perf);

    writeToFile(file, readActorFileWithout(file, name, role, perf));

    std::cout << "Actor removed!\n";
}

void AdminMenu::removePerfomanceMenu()
{
    std::string perf;

    std::cin.ignore();
    std::cout << "Input the name of the perfomance you want to remove: ";
    std::getline(std::cin, perf);

    writeToFile(perfFile, readPerfFileWithout(perfFile, perf));
    writeToFile(file, readActorFileWithout(file, perf));

    std::cout << "Perfomance removed!";
}

void AdminMenu::handleUserInput(const int index)
{
    switch(index)
    {
        case MAIN_ADMIN_MENU:
            handleMainMenu();
            break;
        case EDIT_PERFOMANCE_MENU:
            handleEditMenu();
            break;
    }
}

void AdminMenu::handleMainMenu()
{
    AddPerfomanceHandler* add = new AddPerfomanceHandler(*this, ADD);
    EditPerfomanceHandler* edit = new EditPerfomanceHandler(*this, EDIT);
    RemovePerfomanceHandler* remove = new RemovePerfomanceHandler(*this, REMOVE);

    edit->setNext(remove);
    add->setNext(edit);

    add->handle(userInput.getAnswer(MAIN_ADMIN_MENU));
    //switch(userInput.getAnswer(MAIN_ADMIN_MENU))
    //{
    //    case 1:
    //        addPerfomanceMenu();
    //        break;
    //    case 2:
    //        editPerfomanceMenu();
    //        break;
    //    case 3:
    //        removePerfomanceMenu();
    //        break;
    //}
}

void AdminMenu::handleEditMenu()
{
    switch(userInput.getAnswer(EDIT_PERFOMANCE_MENU))
    {
        case 1:
            addActorMenu();
            break;
        case 2:
            removeActorMenu();
            break;
    }
}

void AdminMenu::run()
{
    start();
    showMainMenu();
    getAndHandle(MAIN_ADMIN_MENU, MAIN_ADMIN_MAX);
}

