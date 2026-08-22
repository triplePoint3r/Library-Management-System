#include "MainPage.h"

MainPage::MainPage(User user) 
{
    if (user.Permission == 'A') 
    {
        Admin admin;
        admin.SwitchMenu();
    }
    if (user.Permission == 'U') 
    {
        Visitor visitor(user);
    }
}
