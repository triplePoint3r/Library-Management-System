#include "Users.h"

Visitor::Visitor() {}

Visitor::Visitor(User visitor) 
{
    this->visitor = visitor;
    borrowing = dataBASE.GetHistory(visitor);
    SwitchMenu();
}

void Visitor::SwitchMenu() 
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
            "Borrow book",
            [this]() {
                V_borrowing();
            }
        },
        {
            4,
            "Return book",
            [this]() {
                V_returning();
            }
        },
        {
            5,
            "Show borrowing history",
            [this]() {
                V_showHistory();
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

void Visitor::V_showallBooks() 
{
    system("cls");
    drawRectangle(60, 3);
    gotoxy(70, 2);
    std::cout << bright_white("Show all books");
    std::cout << std::endl;
    std::cout << std::endl;
    for (int index = 0; index < 45; index++) {
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

void Visitor::V_searchOfBook() 
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

    switch (searching_choice) {
    case 'C':
        cin.clear();
        cin.ignore(100, '\n');
        gotoxy(50, 9);
        std::cout << bright_white("Enter Classification :");
        getline(cin, BookOfClassification);
        if (BookOfClassification == "") {
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
            for (int index = 0; index < 45; index++) {
                if (dataBASE.GetBook(index).BookClassification == BookOfClassification) {

                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << bright_white("\n\t\t\t\t\t\t|Book Name : ") << light_aqua(dataBASE.GetBook(index).NameOfBook);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Classification: ") << light_aqua(dataBASE.GetBook(index).BookClassification);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Author: ") << light_aqua(dataBASE.GetBook(index).NameOfAuthor);
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << std::endl;
                    Book_ClassIfication_FO = true;
                }
            }
            if (!Book_ClassIfication_FO) {
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
        if (NameOfBook == "") {
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
            for (int index = 0; index < 45; index++) {
                if (dataBASE.GetBook(index).NameOfBook == NameOfBook) {
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << bright_white("\n\t\t\t\t\t\t|Book Name : ") << light_aqua(dataBASE.GetBook(index).NameOfBook);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Classification: ") << light_aqua(dataBASE.GetBook(index).BookClassification);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Author: ") << light_aqua(dataBASE.GetBook(index).NameOfAuthor);
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << std::endl;
                    Name_Book_FO = true;
                }
            }
            if (!Name_Book_FO) {
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
        if (NameOfauthor == "") {
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
            for (int index = 0; index < 45; index++) {
                if (dataBASE.GetBook(index).NameOfAuthor == NameOfauthor) {
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << bright_white("\n\t\t\t\t\t\t|Book Name : ") << light_aqua(dataBASE.GetBook(index).NameOfBook);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Classification: ") << light_aqua(dataBASE.GetBook(index).BookClassification);
                    std::cout << bright_white("\n\t\t\t\t\t\t|Author: ") << light_aqua(dataBASE.GetBook(index).NameOfAuthor);
                    std::cout << bright_white("\n\t\t\t\t\t\t==========================================");
                    std::cout << std::endl;
                    Name_author_FO = true;
                }
            }
            if (!Name_author_FO) {
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
        SwitchMenu();
        break;
    default:
        system("cls");
        V_searchOfBook();
        break;
    }
}

bool Visitor::V_checkBorrowing() 
{
    if (borrowing.CounterBorrowing >= 5) {
        return false;
    }
    else
    {
        return true;
    }
}

void Visitor::V_borrowing() 
{
    Book bBook;
    char ValidationOfborrow;

    system("cls");
    drawRectangle(60, 3);
    gotoxy(73, 2);
    std::cout << light_red("Borrowing");
    std::cout << std::endl << std::endl << std::endl;

    drawRectangle(60, 10);
    cin.clear();
    cin.ignore(100, '\n');
    if (V_checkBorrowing()) {
        gotoxy(50, 6);
        std::cout << bright_white("Enter name of book you want to borrow : ");
        getline(cin, bBook.NameOfBook);
        if (bBook.NameOfBook != "") {
            if (dataBASE.CheckBook(bBook)) {
                if (dataBASE.Checkbookborrowed(bBook) == false) {
                    for (int index = 0; index < 45; index++) {
                        if (dataBASE.GetBook(index).NameOfBook == bBook.NameOfBook) {
                            gotoxy(50, 7);
                            std::cout << bright_white("This book you want to borrow ?");
                            gotoxy(50, 8);
                            std::cout << bright_white("Name of book :") << light_yellow(dataBASE.GetBook(index).NameOfBook);
                            gotoxy(50, 9);
                            std::cout << bright_white("Classification of book :") << light_yellow(dataBASE.GetBook(index).BookClassification);
                            gotoxy(50, 10);
                            std::cout << bright_white("Name of authr :") << light_yellow(dataBASE.GetBook(index).NameOfAuthor);
                            gotoxy(50, 11);
                            std::cout << bright_white("Enter Y to borrow the book or N to not borrow it :");
                            cin.ignore(0, '\n');
                            cin >> ValidationOfborrow;
                            if (ValidationOfborrow == 'y' || ValidationOfborrow == 'Y') {

                                bBook.NameOfBook = dataBASE.GetBook(index).NameOfBook;
                                bBook.BookClassification = dataBASE.GetBook(index).BookClassification;
                                bBook.NameOfAuthor = dataBASE.GetBook(index).NameOfAuthor;
                                V_setHistory(bBook, getCurrentDate(), visitor.Username);
                                dataBASE.SetBook_Borrow(bBook);

                                gotoxy(50, 12);
                                std::cout << light_green("The book has been borrowed");
                                gotoxy(50, 13);
                                std::cout << light_green("Press any key to go main page.");
                                system("pause > null");
                                system("cls");
                                SwitchMenu();
                            }
                            if (ValidationOfborrow == 'n' || ValidationOfborrow == 'N') {
                                gotoxy(50, 12);
                                std::cout << light_red("The book has not been borrowed");
                                gotoxy(50, 13);
                                std::cout << light_green("Press any key to go main page.");
                                system("pause > null");
                                system("cls");
                                SwitchMenu();
                            }
                        }
                    }
                }
                else
                {
                    gotoxy(50, 7);
                    std::cout << light_red("The book is borrowed!");
                    gotoxy(50, 8);
                    std::cout << light_green("Press any key to go main page.");
                    system("pause > null");
                    system("cls");
                    SwitchMenu();
                }
            }
            else {
                gotoxy(50, 7);
                std::cout << light_red("The book is not found!");
                gotoxy(50, 8);
                std::cout << light_green("Press any key to go main page.");
                system("pause > null");
                system("cls");
                SwitchMenu();
            }
        }
        else {
            gotoxy(50, 7);
            std::cout << light_red("invalid input!");
            gotoxy(50, 8);
            std::cout << light_green("Press any key to go main page.");
            system("pause > null");
            system("cls");
            SwitchMenu();
        }
    }
    else {
        gotoxy(50, 6);
        std::cout << light_red("you have reached the limit of borrowing books");
        gotoxy(50, 7);
        std::cout << light_green("Press any key to go main page.");
        system("pause > null");
        system("cls");
        SwitchMenu();
    }
}

void Visitor::V_returning() {
    Book rBook;
    char ValidationOfreturning;

    system("cls");
    drawRectangle(60, 3);
    gotoxy(73, 2);
    std::cout << light_red("Returning");

    std::cout << std::endl << std::endl << std::endl;
    drawRectangle(60, 10);
    cin.clear();
    cin.ignore(100, '\n');

    gotoxy(50, 6);
    std::cout << bright_white("Enter name of book you want to returning :");
    getline(cin, rBook.NameOfBook);
    if (rBook.NameOfBook != "") {
        if (dataBASE.CheckBook(rBook)) {
            for (int index = 0; index < 45; index++) {
                if (dataBASE.GetBook(index).NameOfBook == rBook.NameOfBook) {
                    gotoxy(50, 7);
                    std::cout << bright_white("This book you want to returning ?");
                    gotoxy(50, 8);
                    std::cout << bright_white("Name of book :") << light_yellow(dataBASE.GetBook(index).NameOfBook) << std::endl;
                    gotoxy(50, 9);
                    std::cout << bright_white("Classification of book :") << light_yellow(dataBASE.GetBook(index).BookClassification) << std::endl;
                    gotoxy(50, 10);
                    std::cout << bright_white("Name of authr :") << light_yellow(dataBASE.GetBook(index).NameOfAuthor) << std::endl;
                    gotoxy(50, 11);
                    std::cout << bright_white("Enter Y to borrow the book or N to not borrow it :");
                    cin.ignore(0, '\n');
                    cin >> ValidationOfreturning;
                    if (ValidationOfreturning == 'y' || ValidationOfreturning == 'Y') {
                        rBook.NameOfBook = dataBASE.GetBook(index).NameOfBook;
                        rBook.BookClassification = dataBASE.GetBook(index).BookClassification;
                        rBook.NameOfAuthor = dataBASE.GetBook(index).NameOfAuthor;
                        V_editHistory(rBook);
                        dataBASE.UnBook_Borrow(rBook);

                        gotoxy(50, 12);
                        std::cout << light_green("The book has been returning");
                        gotoxy(50, 13);
                        std::cout << light_green("Press any key to go main page.");
                        system("pause > null");
                        system("cls");
                        SwitchMenu();
                    }
                    if (ValidationOfreturning == 'n' || ValidationOfreturning == 'N') {
                        gotoxy(50, 12);
                        std::cout << light_red("The book has not been returning");
                        gotoxy(50, 13);
                        std::cout << light_green("Press any key to go main page.");
                        system("pause > null");
                        system("cls");
                        SwitchMenu();
                    }

                }
            }
        }
        else
        {
            gotoxy(50, 7);
            std::cout << light_red("The book is not found!");
            gotoxy(50, 8);
            std::cout << light_green("Press any key to go main page.");
            system("pause > null");
            system("cls");
            SwitchMenu();
        }
    }
    else
    {
        gotoxy(50, 7);
        std::cout << light_red("invalid input!");
        gotoxy(50, 8);
        std::cout << light_green("Press any key to go main page.");
        system("pause > null");
        system("cls");
        SwitchMenu();
    }
}

void Visitor::V_editHistory(Book book) 
{    
    for (int index = 0; index < 5; index++) {
        if (borrowing.Book[index].NameOfBook == book.NameOfBook) {
            borrowing.Book[index].NameOfBook = "";
            borrowing.Book[index].BookClassification = "";
            borrowing.Book[index].NameOfAuthor = "";
            borrowing.Time[index] = "";
            borrowing.CounterBorrowing -= 1;
            dataBASE.EditHistory(borrowing);
            break;
        }
    }
}

void Visitor::V_setHistory(Book book, string time, string Username) 
{    
    for (int index = 0; index < 5; index++) {
        if (borrowing.Book[index].NameOfBook == "" && borrowing.Time[index] == "") {
            borrowing.Book[index] = book;
            borrowing.Time[index] = time;
            borrowing.Username = Username;
            borrowing.CounterBorrowing += 1;
            dataBASE.AddHistory(borrowing);
            break;
        }
    }
}

void Visitor::V_showHistory() 
{
    system("cls");
    for (int index = 0; index < 5; index++) {
        if (borrowing.Book[index].NameOfBook != "" && borrowing.Time[index] != "") {
            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Name of book :") << light_yellow(borrowing.Book[index].NameOfBook);
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Classification of book :") << light_yellow(borrowing.Book[index].BookClassification);
            std::cout << bright_white("\n\t\t\t\t\t\t\t|Name of authr :") << light_yellow(borrowing.Book[index].NameOfAuthor);
            std::cout << bright_white("\n\t\t\t\t\t\t\t|The time of borrowing :") << light_yellow(borrowing.Time[index]);
            std::cout << bright_white("\n\t\t\t\t\t\t\t==========================================");
            std::cout << std::endl;
        }
    }
    std::cout << light_green("\n\t\t\t\t\t\t\tPress any key to go main page.");
    system("pause > null");
    system("cls");
    SwitchMenu();
}