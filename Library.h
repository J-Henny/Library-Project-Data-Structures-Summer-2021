#ifndef INC_2021_SUMMER_CSCI2421_LIBRARY_H
#define INC_2021_SUMMER_CSCI2421_LIBRARY_H

#include "string"
#include "memory"
#include "LinkedBag.h"

#include "BinarySearchTree.h"
#include "LinkedStack.h"
#include "LinkedList.h"
#include "Book.h"
#include "Patron.h"
#include "Author.h"
#include "PatronComparator.h"
#include "NotFoundException.h"

using namespace std;

class Library {
private:
    shared_ptr<LinkedList<shared_ptr<Book>>> books;
    unique_ptr<BinarySearchTree<shared_ptr<Patron>>> patrons;
    shared_ptr<LinkedStack<shared_ptr<Book>>> dropBox;


public:
    explicit Library();

    virtual ~Library();

    bool addBook(string aTitle, LinkedBag<shared_ptr<Author>> theAuthors, const string& ISBNnum,
                 const string& dateOfPub, const int numOfPages, const string& publish);

    bool addPatron(const string& aName, const string& anAddress, const int& phoneNum);


    bool isBookAvailable(const string &title);

    /**
     * Searchs for a movie with the exact same title as the given argument.
     * @param title
     * @return
     */
    shared_ptr<Book> searchBookExact(const string &title);

    /**
     * Search for all movies that have the patter in their title (case-insensitive)
     * @param titlePattern
     * @return
     */
    vector<shared_ptr<Book>> searchBookPattern(const string &titlePattern);

    vector<shared_ptr<Book>> getAvailable();

    vector<shared_ptr<Book>> getCheckedOut() const;

    void getPatrons();

    void checkOutBook(const string& bookTitle, const string& holder);



    friend std::ostream &operator<<(std::ostream &out, const Library &service);


    static void displayPatron(shared_ptr<Patron>& aPatron);

    void removeByTitle(string& title);

    void placeHold(shared_ptr<Patron>& aPatron, string& title);

    void addToDropBox(const string& bookTitle);

};

#include "Library.cpp"

#endif

