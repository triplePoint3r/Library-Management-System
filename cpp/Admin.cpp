#include "Users.h"

Admin::Admin() {}

void Admin::SwitchMenu() {
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
                A_showallBooks();
            }
        },
        {
            2,
            "Search for a book",
            [this]() {
                A_searchOfBook();
            }
        },
        {
            3,
            "Add book",
            [this]() {
                A_addBook();
            }
        },
        {
            4,
            "Delete book",
            [this]() {
                A_deleteBook();
            }
        },
        {
            5,
            "Show borrowing user",
            [this]() {
                A_showBorrowingUser();
            }
        },
        {
            6,
            "Exit",
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

void Admin::A_showallBooks() 
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
        if (book.NameOfBook != "") {

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
    SwitchMenu();
}

void Admin::A_searchOfBook() 
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
            A_searchOfBook();
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
                A_searchOfBook();
            }
            std::cout << dye::light_green("\n\t\t\t\t\t\tPress any key to go search.");
            system("pause > null");
            system("cls");
            A_searchOfBook();
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
            A_searchOfBook();
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
                A_searchOfBook();
            }
            std::cout << dye::light_green("\n\t\t\t\t\t\tPress any key to go search.");
            system("pause > null");
            system("cls");
            A_searchOfBook();
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
            A_searchOfBook();
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
                A_searchOfBook();
            }
            std::cout << dye::light_green("\n\t\t\t\t\t\tPress any key to go search.");
            system("pause > null");
            system("cls");
            A_searchOfBook();
        }
        break;
    case '0':
        system("cls");
        SwitchMenu();
        break;
    default:
        system("cls");
        A_searchOfBook();
        break;
    }
}

void Admin::A_addBook() 
{
    string ClassOFbook, NameOFbook, NameOFauthor;
    Book newBook;

    system("cls");
    drawRectangle(60, 3);
    gotoxy(75, 2);
    std::cout << bright_white("Add Book");

    std::cout << "\n\n\n\n";
    drawRectangle(60, 10);
    cin.clear();
    cin.ignore(100, '\n');
    
    gotoxy(50, 7);
    std::cout << bright_white("Enter name of the book: ");
    getline(cin, NameOFbook);
    newBook.NameOfBook = NameOFbook;

    gotoxy(50, 8);
    std::cout << bright_white("Enter classification of the book: ");
    getline(cin, ClassOFbook);
    newBook.BookClassification = ClassOFbook;
    gotoxy(50, 9);
    std::cout << bright_white("Enter name of the author: ");
    getline(cin, NameOFauthor);
    newBook.NameOfAuthor = NameOFauthor;

    if (newBook.NameOfBook != "" && newBook.BookClassification != "" && newBook.NameOfAuthor != "") 
    {
        if (dataBASE.CheckBook(newBook)) 
        {
            gotoxy(50, 10);
            std::cout << light_red("the book alredy add");
            gotoxy(50, 11);
            std::cout << light_green("Press any key to go main page.");
            system("pause > null");
            system("cls");
            SwitchMenu();
        }
        else 
        {
            dataBASE.Addbook(newBook);
            gotoxy(50, 10);
            std::cout << light_green("the book is add");
            gotoxy(50, 11);
            std::cout << light_green("Press any key to go main page.");
            system("pause > null");
            system("cls");
            SwitchMenu();
        }
    }
    else 
    {
        gotoxy(50, 10);
        std::cout << light_red("invalid input");
        gotoxy(50, 11);
        std::cout << light_green("Press any key to go main page.");
        system("pause > null");
        system("cls");
        SwitchMenu();
    }
}

void Admin::A_deleteBook() 
{
    string NameOfBook, ClassificationOfBook, NameOfAuthr;
    char ValidationOfDelete;
    Book deBook;

    system("cls");
    drawRectangle(60, 3);
    gotoxy(73, 2);
    std::cout << bright_white("delete book");


    std::cout << std::endl << std::endl << std::endl;
    drawRectangle(80, 10);
    cin.clear();
    cin.ignore(100, '\n');
    gotoxy(50, 6);
    std::cout << bright_white("Enter name of the book : ");
    getline(cin, NameOfBook);
    deBook.NameOfBook = NameOfBook;

    cin.clear();
    cin.ignore(100, '\n');
    gotoxy(50, 7);
    std::cout << bright_white("Enter classification of the book : ");
    getline(cin, ClassificationOfBook);
    deBook.BookClassification = ClassificationOfBook;

    cin.clear();
    cin.ignore(100, '\n');
    gotoxy(50, 8);
    std::cout << bright_white("Enter name of the author : ");
    getline(cin, NameOfAuthr);
    deBook.NameOfAuthor = NameOfAuthr;

    if (deBook.NameOfBook != "" && deBook.BookClassification != "" && deBook.NameOfAuthor != "") 
    {
        if (dataBASE.CheckBook(deBook)) 
        {
            gotoxy(50, 9);
            std::cout << bright_white("Enter Y to delete the book or enter N in order not to delete : ");
            cin.ignore(0, '\n');
            cin >> ValidationOfDelete;
            if (ValidationOfDelete == 'y' || ValidationOfDelete == 'Y') 
            {
                dataBASE.Deletebook(deBook);
                gotoxy(50, 10);
                std::cout << light_green("The book has been successfully deleted.");
                gotoxy(50, 11);
                std::cout << light_green("Press any key to go main page.");
                system("pause > null");
                system("cls");
                SwitchMenu();
            }
            if (ValidationOfDelete == 'n' || ValidationOfDelete == 'N') 
            {
                gotoxy(50, 10);
                std::cout << light_green("The book has not been deleted.");
                gotoxy(50, 11);
                std::cout << light_green("Press any key to go main page.");
                system("pause > null");
                system("cls");
                SwitchMenu();
            }
        }
        if (!dataBASE.CheckBook(deBook)) 
        {
            gotoxy(50, 9);
            std::cout << light_red("This book is not found !");
            gotoxy(50, 10);
            std::cout << light_green("Press any key to go main page.");
            system("pause > null");
            system("cls");
            SwitchMenu();
        }
    }
    else 
    {
        gotoxy(50, 9);
        std::cout << light_red("invalid input");
        gotoxy(50, 10);
        std::cout << light_green("Press any key to go main page.");
        system("pause > null");
        system("cls");
        SwitchMenu();
    }
}

void Admin::A_showBorrowingUser() 
{
    system("cls");
    drawRectangle(60, 3);
    gotoxy(69, 2);
    std::cout << bright_white("Show borrowing user");
    std::cout << std::endl << std::endl;
    for (int index = 0; index < 10; index++) 
    {
        if (dataBASE.GetHistory(index).Username != "") 
        {
            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Username : ") << light_aqua(dataBASE.GetHistory(index).Username) << std::endl;
            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
            for (int indexBook = 0; indexBook < 5; indexBook++) 
            {
                if (dataBASE.GetHistory(index).Book[indexBook].NameOfBook != "") 
                {
                    std::cout << bright_white("\n\t\t\t\t\t\t\t|Name of book : ") << light_aqua(dataBASE.GetHistory(index).Book[indexBook].NameOfBook) << std::endl;
                    std::cout << bright_white("\n\t\t\t\t\t\t\t|classification of book : ") << light_aqua(dataBASE.GetHistory(index).Book[indexBook].BookClassification) << std::endl;
                    std::cout << bright_white("\n\t\t\t\t\t\t\t|Name of authr : ") << light_aqua(dataBASE.GetHistory(index).Book[indexBook].NameOfAuthor) << std::endl;
                    std::cout << bright_white("\n\t\t\t\t\t\t\t|Time of borrowing : ") << light_aqua(dataBASE.GetHistory(index).Time[indexBook]) << std::endl;
                    std::cout << std::endl;
                }
            }
            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
        }
    }
    std::cout << light_green("\n\t\t\t\t\t\t\tPress any key to go main page.");
    system("pause > null");
    system("cls");
    SwitchMenu();
}
