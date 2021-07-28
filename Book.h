#ifndef BOOK_H
#define BOOK_H

#include "string"
#include "memory"
#include "LinkedBag.h"
#include "Author.h"
#include "Patron.h"
#include "LinkedQueue.h"

using namespace std;

class Book {
private:
    string title;
    string ISBN;
    string dateOfPublication;
    string publisher;
    int numPages;
    LinkedBag<shared_ptr<Author>> authors;
    string currentHolder;
    bool checkedOut = false;
    LinkedQueue<shared_ptr<Patron>> hold;

public:
    explicit Book();

    Book(string aTitle, LinkedBag<shared_ptr<Author>> theAuthors, const string& ISBNnum,
                  const string& dateOfPub, const int numOfPages, const string& publish);

    Book(const LinkedQueue<shared_ptr<Patron>>& aHold);

    ~Book();

    string getTitle() const;

    void setTitle(const string &aTitle);

    bool getChecked() const;

    void checkOut(const string &holder);

    void setChecked(bool check);

    string getDateofPub() const;

    string getCurrentHolder() const;

    void setCurrentHolder(const string aHolder);

    bool isHoldQueueEmpty() const;

    bool addToHold(shared_ptr<Patron> aPatron);

    shared_ptr<Patron> getFirstHold();

    friend ostream &operator<<(ostream &out, const Book &aBook);

    bool addAuthor(const shared_ptr<Author> &anAuthor);

    bool removeAuthor(const shared_ptr<Author> &anAuthor);

    vector<shared_ptr<Author>> getAuthors() const;

    void displayAuthors() const;
};

#include "Book.cpp"


#endif //BOOK_H
