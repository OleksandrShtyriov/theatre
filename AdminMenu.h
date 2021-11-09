#ifndef ADMINMENU_H_
#define ADMINMENU_H_

#include <iostream>

#include "Answer.h"
#include "Log.h"
#include "Menu.h"

const std::string password = "AdminPass";
const int menuCountAdmin = 2;

enum AnswersAdmin
{
    MAIN_ADMIN_MENU,
    EDIT_PERFOMANCE_MENU,
};

enum MaxAnswersAdmin
{
    MAIN_ADMIN_MAX = 4,
    EDIT_PERFOMANCE_MAX = 3,
};

class AdminMenu : public Menu
{
    private:
        std::string file;
        std::string perfFile;

        void checkPassword();

        void start();

        void showMainMenu();
        void addPerfomanceMenu();
        void editPerfomanceMenu();
        void addActorMenu();
        void removeActorMenu();
        void removePerfomanceMenu();

        void handleUserInput(const int index);

        void handleMainMenu();
        void handleEditMenu();
    public:
        AdminMenu(const std::string file, const std::string perfFile, Theatre theatre);

        void run();
};

#endif

