#ifndef Users_H
#define Users_H
#include <iostream>
#include "DataBase.h"
#include "Design2.h"
#include "gotoxy.h"
#include "LoginOrSignUpOrGuest.h"
#include "color-console/color.hpp"
#include <conio.h>
#include "currentTime.h"
#include "SwitchMenu.h"

class Admin 
{
    User admin;
public:

    Admin();
    void SwitchMenu();
    void A_showallBooks();
    void A_searchOfBook();
    void A_addBook();
    void A_deleteBook();
    void A_showBorrowingUser();
};

class Visitor 
{
private:
    User visitor;
    History borrowing;

public:
    Visitor();
    Visitor(User visitor);
    void SwitchMenu();
    void V_showallBooks();
    void V_searchOfBook();

    void V_borrowing();
    void V_returning();
    void V_showHistory();


    bool V_checkBorrowing();
    void V_editHistory(Book book);
    void V_setHistory(Book book, string time, string Username);
};


class Guest : public Visitor 
{
public:
    Guest();
    void V_showallBooks();
    void V_searchOfBook();
    void SwitchMenu();
};

#endif