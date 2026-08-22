#include "SignUpPage.h"

void Signup::printHeaderSignup() 
{
    ConsolePgaes page
    (
        "Signup page",
        50,
        105,
        1,
        5,
        6,
        25
    );
}

void Signup::SetVisitorName() 
{
    try
    {
        cin.clear();
        string name = string{};
        gotoxy(51, 7);
        std::cout << bright_white("Set your name : ");
        getline(cin, name);

        if (name.length() > 8 || name.length() < 5)
        {
            throw name;
        }

        sUser.Username = name;

        if (dataBASE.GetUser(sUser).Username == name)
        {
            gotoxy(51, 8);
            std::cout << light_red("Invalid Username");
            gotoxy(51, 9);
            std::cout << light_green("press any key to back.");
            system("pause > null ");
            system("cls");
            backtoMainpage();
        }
        else
        {
            sUser.Username = name;
        }
    }
    catch (string name) {
        gotoxy(51, 8);
        std::cout << light_red("Invalid length");
        gotoxy(51, 9);
        std::cout << light_red("should the length between 5 and 8");
        gotoxy(51, 10);
        std::cout << light_green("press any key to back.");
        system("pause > null ");
        system("cls");
        backtoMainpage();
    }
}

void Signup::SetVisitorAge() 
{
    int age;
    try
    {
        cin.clear();        
        gotoxy(51, 8);
        std::cout << bright_white("Set your age : ");

        cin >> age;

        if (cin.fail() || (age < 18 || age > 100))
        {
            throw age;
        }
        else
        {
            sUser.Age = age;
        }

    }
    catch (int)
    {
        gotoxy(51, 9);
        std::cout << light_red("You must be 18 or older or check your input");
        gotoxy(51, 10);
        std::cout << light_green("press any key to back.");
        system("pause > null ");
        system("cls");
        backtoMainpage();
    }

}

void Signup::SetVisitorEmail() 
{
    try 
    {
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        string email;
        cin.clear();
        gotoxy(51, 9);
        std::cout << bright_white("Set your email : ");

        cin >> email;
        if (!regex_match(email, pattern))
        {
            throw(email);
        }
        else
        {
            sUser.Email = email;
        }
    }
    catch (string email) 
    {
        gotoxy(51, 10);
        std::cout << light_red("Invalid email !");
        gotoxy(51, 11);
        std::cout << light_green("press any key to back.");
        system("pause > null ");
        system("cls");
        backtoMainpage();
    }
}

void Signup::SetVisitorPassword() 
{
    try 
    {
        string password;
        cin.clear();
        cin.ignore(100, '\n');
    
        gotoxy(50, 9);
        std::cout << bright_white("Set your password : ");
        cin >> password;
        if (password.length() < 8 || password.length() > 10) 
        {
            throw(password);
        }
        else 
        {
            sUser.Password = password;
        }
    }
    catch (string password) 
    {
        gotoxy(50, 10);
        std::cout << light_red("The length of an invalid password must be between 8 and 10");
        gotoxy(50, 11);
        std::cout << light_green("press any key to back.");
        system("pause > null ");
        system("cls");
        backtoMainpage();;
    }
}

void Signup::SetVisitorPermission() 
{
    sUser.Permission = 'U';
}

void Signup::doneSignup() 
{
    dataBASE.AddUser(sUser);
    gotoxy(50, 10);
    std::cout << light_green("Sign up is done.");
    gotoxy(50, 11);
    std::cout << light_green("press any key to back.");
    system("pause > null");
    system("cls");
}

void Signup::backtoMainpage() 
{
    LoginOrSignUpOrGuest main;
    main;
}

Signup::Signup() 
{
    sUser = User{};
    system("cls");
    printHeaderSignup();
    SetVisitorName();
    SetVisitorAge();
    SetVisitorEmail();
    SetVisitorPassword();
    SetVisitorPermission();
    doneSignup();
    backtoMainpage();
}