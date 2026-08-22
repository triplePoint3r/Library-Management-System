#include "Users.h"

Guest::Guest()
{    
    SwitchMenu();
}

void Guest::SwitchMenu()
{
    system("cls");
    ConsolePgaes page(
        "Visitor",
        50,
        105,
        1,
        5,
        6,
        16
    );
    auto position = page.PositionsOfPage();
    vector<SwitchMenu::Action> actions =
    {
        {
            1,
            "Show all books",
            [this]() {
                V_showallBooks();
            }
        },
        {
            2,
            "Search for a book",
            [this]() {
                V_searchOfBook();
            }
        },
        {
            3,
            "Back to main page",
            []() {
                LoginOrSignUpOrGuest lsg;
            }
        }
    };
    ::SwitchMenu menu(
        actions,
        actions.size(),
        position.centerOfPw,
        position.StartHightPage,
        position.EndHightPage
    );    
}

void Guest::V_showallBooks() 
{
    system("cls");
    drawRectangle(60, 3);
    gotoxy(70, 2);
    std::cout << bright_white("Show all books");
    std::cout << std::endl;
    std::cout << std::endl;

    for (int index = 0; index < 45; index++) 
    {
        Book book = dataBASE.GetBook(index);
        if (book.NameOfBook != "") 
        {

            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Classification: ") << light_aqua(book.BookClassification);
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Book Name: ") << light_aqua(book.NameOfBook);
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Author: ") << light_aqua(book.NameOfAuthor);
            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
            std::cout << std::endl;
        }

    }

    std::cout << dye::light_green("\n\t\t\t\t\t\t\tPress any key to go main page.");
    system("pause > null");
    system("cls");
    Guest::Guest();
}

void Guest::V_searchOfBook() 
{
    string BookOfClassification, NameOfBook, NameOfauthor;
    bool Book_ClassIfication_FO = false, Name_Book_FO = false, Name_author_FO = false;
    char searching_choice;

    system("cls");
    drawRectangle(60, 3);
    gotoxy(75, 2);
    std::cout << bright_white("Search");

    std::cout << std::endl << std::endl << std::endl;
    drawRectangle(65, 7);
    gotoxy(50, 6);
    std::cout << light_yellow("C (Classification)") << bright_white(" | ") << light_aqua("B (Book name)") << bright_white(" | ") << light_green("A (Author name)") << bright_white(" | ") << light_red("0 (Back)") << std::endl;
    cin.clear();
    cin.ignore(100, '\n');
    gotoxy(50, 8);
    std::cout << bright_white("Enter search type : ");

    cin >> searching_choice;

    switch (searching_choice) 
    {
    case 'C':
        cin.clear();
        cin.ignore(100, '\n');
        gotoxy(50, 9);
        std::cout << bright_white("Enter Classification :");
        getline(cin, BookOfClassification);
        if (BookOfClassification == "") 
        {
            gotoxy(50, 10);
            std::cout << light_red("invalid input");
            gotoxy(50, 11);
            std::cout << light_green("Press any key to go search.");
            system("pause > null");
            system("cls");
            V_searchOfBook();
        }
        else
        {
            std::cout << std::endl << std::endl << std::endl;
            for (int index = 0; index < 45; index++) 
            {
                if (dataBASE.GetBook(index).BookClassification == BookOfClassification) 
                {

                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << bright_white("\n\t\t\t\t\t\t|Book Name : ") << light_aqua(dataBASE.GetBook(index).NameOfBook);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Classification: ") << light_aqua(dataBASE.GetBook(index).BookClassification);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Author: ") << light_aqua(dataBASE.GetBook(index).NameOfAuthor);
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << std::endl;
                    Book_ClassIfication_FO = true;
                }
            }
            if (!Book_ClassIfication_FO) 
            {
                std::cout << light_red("\n\t\t\t\t\t\tThis classification is not found !");
                std::cout << light_green("\n\t\t\t\t\t\tPress any key to go search.");
                system("pause > null");
                system("cls");
                V_searchOfBook();
            }
            std::cout << dye::light_green("\n\t\t\t\t\t\tPress any key to go search.");
            system("pause > null");
            system("cls");
            V_searchOfBook();
        }
        break;
    case'B':
        cin.clear();
        cin.ignore(100, '\n');
        gotoxy(50, 9);
        std::cout << bright_white("Enter name of book :");
        getline(cin, NameOfBook);
        if (NameOfBook == "") 
        {
            gotoxy(50, 10);
            std::cout << light_red("invalid input");
            gotoxy(50, 11);
            std::cout << light_green("Press any key to go search.");
            system("pause > null");
            system("cls");
            V_searchOfBook();
        }
        else
        {
            std::cout << std::endl << std::endl << std::endl;
            for (int index = 0; index < 45; index++) 
            {
                if (dataBASE.GetBook(index).NameOfBook == NameOfBook) 
                {
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << bright_white("\n\t\t\t\t\t\t|Book Name : ") << light_aqua(dataBASE.GetBook(index).NameOfBook);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Classification: ") << light_aqua(dataBASE.GetBook(index).BookClassification);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Author: ") << light_aqua(dataBASE.GetBook(index).NameOfAuthor);
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << std::endl;
                    Name_Book_FO = true;
                }
            }
            if (!Name_Book_FO) 
            {
                std::cout << light_red("\n\t\t\t\t\t\tThis book is not found !");
                std::cout << light_green("\n\t\t\t\t\t\tPress any key to go search.");
                system("pause > null");
                system("cls");
                V_searchOfBook();
            }
            std::cout << dye::light_green("\n\t\t\t\t\t\tPress any key to go search.");
            system("pause > null");
            system("cls");
            V_searchOfBook();
        }
        break;
    case'A':
        cin.clear();
        cin.ignore(100, '\n');
        gotoxy(50, 9);
        std::cout << bright_white("Enter name of author :");
        getline(cin, NameOfauthor);
        if (NameOfauthor == "") 
        {
            gotoxy(50, 10);
            std::cout << light_red("Invalid input");
            gotoxy(50, 11);
            std::cout << light_green("Press any key to go search.");
            system("pause > null");
            system("cls");
            V_searchOfBook();
        }
        else
        {
            std::cout << std::endl << std::endl << std::endl;
            for (int index = 0; index < 45; index++) 
            {
                if (dataBASE.GetBook(index).NameOfAuthor == NameOfauthor) 
                {
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << bright_white("\n\t\t\t\t\t\t|Book Name : ") << light_aqua(dataBASE.GetBook(index).NameOfBook);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Classification: ") << light_aqua(dataBASE.GetBook(index).BookClassification);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Author: ") << light_aqua(dataBASE.GetBook(index).NameOfAuthor);
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << std::endl;
                    Name_author_FO = true;
                }
            }
            if (!Name_author_FO) 
            {
                std::cout << light_red("\n\t\t\t\t\t\tThis author is not found !");
                std::cout << light_green("\n\t\t\t\t\t\tPress any key to go search.");
                system("pause > null");
                system("cls");
                V_searchOfBook();
            }
            std::cout << dye::light_green("\n\t\t\t\t\t\tPress any key to go search.");
            system("pause > null");
            system("cls");
            V_searchOfBook();
        }
        break;
    case '0':
        system("cls");
        Guest();
        break;
    default:
        system("cls");
        V_searchOfBook();
        break;
    }
}