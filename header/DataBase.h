#ifndef DATABASE_H
#define DATABASE_H

#include <string>

/**
 * @struct Book
 * @brief Represents a book in the library.
 *
 * Stores the book's classification, title, author, and
 * current borrowing status.
 */
struct Book {
    std::string BookClassification;
    std::string NameOfBook;
    std::string NameOfAuthor;
    bool Borrowed = false;
};

/**
 * @struct User
 * @brief Represents a user registered in the library system.
 *
 * Stores the user's account information and permission level.
 */
struct User {
    std::string Username;
    int Age;
    std::string Email;
    std::string Password;
    char Permission;
};

/**
 * @struct History
 * @brief Represents the borrowing history of a library user.
 *
 * Stores the borrowed books, their borrowing dates, the Username,
 * and the number of borrowing records.
 */
struct History {
    Book Book[5];
    std::string Time[5];
    std::string Username;
    int CounterBorrowing;
};

/**
 * @class DataBase
 * @brief Manages the library's books, users, and borrowing records.
 *
 * Provides operations for adding, deleting, searching, and retrieving
 * books and users, as well as managing borrowing history.
 *
 * The current implementation uses fixed-size arrays to store the data.
 */
class DataBase {
private:
    Book books[45];
    User users[10];
    History BorrowingHistory[10];

public:
    /**
    * @brief Initializes the library database with its initial data.
    */
    DataBase();

    // Book management
    bool CheckBook(Book book);
    void Addbook(Book book);
    void Deletebook(Book book);
    Book GetBook(int index);
    bool Checkbookborrowed(Book book);
    void SetBook_Borrow(Book name);
    void UnBook_Borrow(Book name);

    // User management
    bool CheckUser(User user);
    User GetUser(User user);
    void AddUser(User user);

    // Borrowing history management
    History GetHistory(int index);
    History GetHistory(User visitor);
    void AddHistory(History history);
    void EditHistory(History history);
};

extern DataBase dataBASE;

#endif
