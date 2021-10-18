#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>

#include "Theatre.h"
#include "Answer.h"
#include "Log.h"

const int menuCount = 3;

enum Answers
{
    MAIN_MENU,
    PERFOMANCES_MENU,
    TICKET_MENU,
};

enum MaxAnswers
{
    MAIN_MAX = 2,
    TICKET_MAX = 2,
};

class Menu
{
    private:
        Theatre theatre;
        Answer userInput;

        void start();

        void showMainMenu();
        void showPerfomancesMenu();
        void showTicketMenu();

        void getAnswer(const int index, const int max);
        void handleUserInput(const int index);
        void getAndHandle(const int index, const int max);

        void handleMainMenu();
        void handlePerfomancesMenu();
        void handleTicketMenu();

        void orderTicket(int perfomance);
    public:
        Menu(const Theatre t);

        void run();
};

#endif
