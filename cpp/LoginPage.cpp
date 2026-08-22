#include "LoginPage.h"

void Login::login_page() {
    ConsolePgaes page(
        "Login page",
        50,
        105,
        1,
        5,
        6,
        20
    );
}

bool Login::CheckLogin(string user, string pass) {
    User luser;
    luser.Username = user;
    luser.Password = pass;

    if (dataBASE.CheckUser(luser)) 
    {
        return true;
    }
    else {
        return false;
    }
}

Login::Login() 
{
    User luser = User{};

    system("cls");
    login_page();

    gotoxy(51, 7);
    std::cout << bright_white("Enter your user name : ");
    getline(cin, UserName);

    gotoxy(51, 8);
    std::cout << bright_white("Enter your password : ");
    getline(cin, PassWord);

    if (UserName != "" && PassWord != "") 
    {
        if (CheckLogin(UserName, PassWord)) 
        {
            luser.Username = UserName;
            luser.Password = PassWord;
            system("cls");
            MainPage mainpage(dataBASE.GetUser(luser));
        }
        else 
        {
            gotoxy(51, 9);
            std::cout << light_red("User not found!");
            gotoxy(51, 10);
            std::cout << light_green("press any key to back");
            system("pause > null");
            system("cls");
            LoginOrSignUpOrGuest lsg;
        }
    }
    else 
    {
        gotoxy(51, 9);
        std::cout << light_red("Invailed login") << std::endl;
        gotoxy(51, 10);
        std::cout << light_green("press any key to back");
        system("pause > null");
        system("cls");
        LoginOrSignUpOrGuest lsg;
    }
}