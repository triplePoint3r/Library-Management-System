#include "DataBase.h"
#include "currentTime.h"

DataBase dataBASE;

DataBase::DataBase(){
    books[0] = { "stories", "The Silent Patient", "Alex Michaelides" };
    books[1] = { "stories", "Where the Crawdads Sing", "Delia Owens" };
    books[2] = { "stories", "Educated", "Tara Westover" };
    books[3] = { "stories", "Becoming", "Michelle Obama" };
    books[4] = { "stories", "The Testaments", "Margaret Atwood" };

    books[5] = { "education", "Mindset", "Carol S. Dweck" };
    books[6] = { "education", "Grit", "Angela Duckworth" };
    books[7] = { "education", "The Element", "Ken Robinson" };
    books[8] = { "education", "How Children Succeed", "Paul Tough" };
    books[9] = { "education", "Make It Stick", "Peter C. Brown" };

    books[10] = { "history", "Sapiens", "Yuval Noah Harari" };
    books[11] = { "history", "1491", "Charles C. Mann" };
    books[12] = { "history", "SPQR", "Mary Beard" };
    books[13] = { "history", "Guns, Germs, and Steel", "Jared Diamond" };
    books[14] = { "history", "The Wright Brothers", "David McCullough" };

    books[15] = { "sports", "Moneyball", "Michael Lewis" };
    books[16] = { "sports", "Seabiscuit", "Laura Hillenbrand" };
    books[17] = { "sports", "Friday Night Lights", "H.G. Bissinger" };
    books[18] = { "sports", "Open", "Andre Agassi" };
    books[19] = { "sports", "The Real Madrid Way", "Steven G. Mandis" };

    books[20] = { "programming", "Clean Code", "Robert C. Martin" };
    books[21] = { "programming", "Refactoring", "Martin Fowler" };
    books[22] = { "programming", "Design Patterns", "Erich Gamma" };
    books[23] = { "programming", "The Pragmatic Programmer", "Andrew Hunt and David Thomas" };
    books[24] = { "programming", "Code Complete", "Steve McConnell" };
    
    books[25] = { "", "", "" };
    books[26] = { "", "", "" };
    books[27] = { "", "", "" };
    books[28] = { "", "", "" };
    books[29] = { "", "", "" };
    books[30] = { "", "", "" };
    books[31] = { "", "", "" };
    books[32] = { "", "", "" };
    books[33] = { "", "", "" };
    books[34] = { "", "", "" };
    books[35] = { "", "", "" };
    books[36] = { "", "", "" };
    books[37] = { "", "", "" };
    books[38] = { "", "", "" };
    books[39] = { "", "", "" };
    books[40] = { "", "", "" };
    books[41] = { "", "", "" };
    books[42] = { "", "", "" };
    books[43] = { "", "", "" };
    books[44] = { "", "", "" };


    users[0].Username = "admin";
    users[0].Age = 19;
    users[0].Email = "Admin@gmail.com";
    users[0].Password = "admin";
    users[0].Permission = 'A';

    users[1].Username = "user";
    users[1].Age = 19;
    users[1].Email = "user@gmail.com";
    users[1].Password = "user";
    users[1].Permission = 'U';

    BorrowingHistory[0].Username = "user";
    BorrowingHistory[0].Book[0].NameOfBook = "Mindset";
    BorrowingHistory[0].Book[0].BookClassification = "education";
    BorrowingHistory[0].Book[0].NameOfAuthor = "Carol S. Dweck";
    books[5].Borrowed = true;
    BorrowingHistory[0].Time[0] = getCurrentDate();
}

bool DataBase::CheckBook(Book book) 
{
    for (int index = 0; index < 45; index++) 
    {
        if (books[index].NameOfBook == book.NameOfBook) 
        {
            return true;
        }
    }
    return false;
}

void DataBase::Addbook(Book book) 
{
    for (int index = 0; index < 45; index++) 
    {
        if (books[index].NameOfBook == "") 
        {
            books[index].NameOfBook = book.NameOfBook;
            books[index].BookClassification = book.BookClassification;
            books[index].NameOfAuthor = book.NameOfAuthor;
            books[index].Borrowed = false;
            break; 
        }
    }
}

void DataBase::Deletebook(Book book) 
{
    for (int index = 0; index < 45; index++) 
    {
        if (books[index].NameOfBook == book.NameOfBook) 
        {
            books[index].NameOfBook = "";
            books[index].BookClassification = "";
            books[index].NameOfAuthor = "";
            books[index].Borrowed = NULL;
            break;
        }
    }
}

Book DataBase::GetBook(int index) 
{
    return books[index];
}

bool DataBase::Checkbookborrowed(Book book) 
{
    for (int index = 0; index < 45; index++) 
    {
        if (books[index].NameOfBook == book.NameOfBook) 
        {
            if (books[index].Borrowed == false) 
            {
                return false;                           
            }         
            if (books[index].Borrowed == true) 
            {
                return true;
            }
        }
    }
    
}

void DataBase::SetBook_Borrow(Book book) 
{
    for (int index = 0; index < 45; index++) 
    {
        if (books[index].NameOfBook == book.NameOfBook) 
        {
            books[index].Borrowed = true;
            break;
        }
    }
}

void DataBase::UnBook_Borrow(Book book) {
    for (int index = 0; index < 45; index++) {
        if (books[index].NameOfBook == book.NameOfBook) {
            books[index].Borrowed = false;
            break;
        }
    }
}

bool DataBase::CheckUser(User user) 
{
    for (int index = 0; index < 10; index++) 
    {
        if (users[index].Username == user.Username && users[index].Password == user.Password)
        {
            return true;
        }
    }
    return false;
}

User DataBase::GetUser(User user) 
{
    for (int index = 0; index < 10; index++) 
    {
        if (users[index].Username == user.Username) 
        {
            return users[index];
        }
    }    
    return User{};
}

void DataBase::AddUser(User user) 
{
    for (int index = 0; index < 10; index++) 
    {
        if (users[index].Username == "") 
        {
            users[index] = user;
            break;
        }
    }    
}

History DataBase::GetHistory(User visitor) 
{
    for (int index = 0; index < 10; index++) 
    {
        if (BorrowingHistory[index].Username == visitor.Username)
        {
            return BorrowingHistory[index];
        }            
        else 
        {
            return History{};
        }
    }    
}

History DataBase::GetHistory(int index) 
{
    return BorrowingHistory[index];
}

void DataBase::AddHistory(History history) 
{
    for (int index = 0; index < 10; index++) 
    {
        if (BorrowingHistory[index].Username == "" || BorrowingHistory[index].Username == history.Username)
        {
            BorrowingHistory[index] = history;
            break;
        }
    }           
}

void DataBase::EditHistory(History history) 
{
    for (int index = 0; index < 10; index++) 
    {
        if (BorrowingHistory[index].Username == history.Username)
        {
            BorrowingHistory[index] = history;
            break;
        }
    }    
}