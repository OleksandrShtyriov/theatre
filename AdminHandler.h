#ifndef ADMINHANDLER_H_
#define ADMINHANDLER_H_

#include "AdminMenu.h"

enum Responces
{
    ADD = 1,
    EDIT,
    REMOVE,
};

class AdminHandler
{
    protected:
        int responce;
        AdminHandler* next;
        AdminMenu menu;
    public:
        AdminHandler(AdminMenu menu, int responce);

        virtual void setNext(AdminHandler* next);
        virtual void handle(int responce) = 0;
};

class AddPerfomanceHandler : public AdminHandler
{
    public:
        AddPerfomanceHandler(AdminMenu menu, int responce);

        void handle(int responce);
};

class EditPerfomanceHandler : public AdminHandler
{
    public:
        EditPerfomanceHandler(AdminMenu menu, int responce);

        void handle(int responce);
};

class RemovePerfomanceHandler : public AdminHandler
{
    public:
        RemovePerfomanceHandler(AdminMenu menu, int responce);

        void handle(int responce);
};

#endif

