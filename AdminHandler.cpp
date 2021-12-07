#include "AdminHandler.h"

AdminHandler::AdminHandler(AdminMenu menu, int responce)
{
    this->responce = responce;
    this->menu = menu;
    next = NULL;
}

void AdminHandler::setNext(AdminHandler* next)
{
    this->next = next;
}

AddPerfomanceHandler::AddPerfomanceHandler(AdminMenu menu, int responce) : AdminHandler(menu, responce) { }

void AddPerfomanceHandler::handle(int responce)
{
    if (responce == this->responce)
    {
        menu.addPerfomanceMenu();
    }
    else if (next)
    {
        next->handle(responce);
    }
}

EditPerfomanceHandler::EditPerfomanceHandler(AdminMenu menu, int responce) : AdminHandler(menu, responce) { }

void EditPerfomanceHandler::handle(int responce)
{
    if (responce == this->responce)
    {
        menu.editPerfomanceMenu();
    }
    else if (next)
    {
        next->handle(responce);
    }
}

RemovePerfomanceHandler::RemovePerfomanceHandler(AdminMenu menu, int responce) : AdminHandler(menu, responce) { }

void RemovePerfomanceHandler::handle(int responce)
{
    if (responce == this->responce)
    {
        menu.removePerfomanceMenu();
    }
    else if (next)
    {
        next->handle(responce);
    }
}

