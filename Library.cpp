
#include "iostream"
#include "string"
#include "regex"
#include "iomanip"


/**********************************************************************************************************************/
#include "LinkedBag.h"
#include "LinkedList.h"
#include "Library.h"

Library::Library(){
    shared_ptr<Comparator<shared_ptr<Patron>>> aPatronComparator = make_shared<PatronComparator>();
    patrons = make_unique<BinarySearchTree<shared_ptr<Patron>>>(aPatronComparator);
    books = make_shared<LinkedList<shared_ptr<Book>>>();
    dropBox = make_shared<LinkedStack<shared_ptr<Book>>>();
}
/**********************************************************************************************************************/
Library::~Library() {
    books->clear();
    patrons->clear();
    while(!dropBox->isEmpty())
        dropBox->pop();
}

/**********************************************************************************************************************/
bool Library::addBook(string aTitle, LinkedBag<shared_ptr<Author>> theAuthors, const string& ISBNnum,
                      const string& dateOfPub, const int numOfPages, const string& publish){

    bool added ;
    shared_ptr<Book> aBook = make_shared<Book>(aTitle, theAuthors, ISBNnum, dateOfPub, numOfPages, publish);
    /**
     * YOUR CODE HERE.
     */
    added = books->insert(1, aBook);
    return added;
}

/**********************************************************************************************************************/
bool Library::addPatron(const string& aName, const string& anAddress, const int& phoneNum){

    bool added ;
    shared_ptr<Patron> aPatron = make_shared<Patron>(aName, anAddress, phoneNum);
    /**
     * YOUR CODE HERE.
     */
    added = patrons->add(aPatron);

    return added;
}

/**********************************************************************************************************************/
bool Library::isBookAvailable(const string& title){
    return (searchBookExact(title) != nullptr);
}

/**********************************************************************************************************************/
shared_ptr<Book> Library::searchBookExact(const string& title){
    for (int i = 1; i < books->getLength() + 1; i++)
        if (books->getEntry(i)->getTitle() == title)
            return books->getEntry(i);
    return nullptr;
}

/**********************************************************************************************************************/
vector<shared_ptr<Book>> Library::getAvailable(){
    vector<shared_ptr<Book>> availableBooks;
    for(int i = 1; i< books->getLength(); i++){
        shared_ptr<Book> aBook = books->getEntry(i);
        if(!aBook->getChecked()){
            availableBooks.push_back(aBook);
        }
    }
    return availableBooks;
}

/**********************************************************************************************************************/
vector<shared_ptr<Book>> Library::getCheckedOut() const {
    vector<shared_ptr<Book>> checkedOutBooks;
    for(int i = 1; i< books->getLength(); i++){
        shared_ptr<Book> aBook = books->getEntry(i);
        if(aBook->getChecked()){
            checkedOutBooks.push_back(aBook);
        }
    }
    return checkedOutBooks;
}

/**********************************************************************************************************************/
void Library::checkOutBook(const string& bookTitle, const string& holder){
    for (int i = 1; i < books->getLength() + 1; i++){
        if (books->getEntry(i)->getTitle() == bookTitle){
            books->getEntry(i)->checkOut(holder);
        }
    }
}
/**********************************************************************************************************************/
void Library:: getPatrons(){
    return patrons->inorderTraverse(displayPatron);
}

/**********************************************************************************************************************/
vector<shared_ptr<Book>> Library::searchBookPattern(const string& titlePattern){
    /**
     * TODO #9: searchMoviePattern
     *
     * Returns a vector of pointers to movies.
     *
     * Using the regular expression module, search for all the movies that contain the titlePattern in their titles.
     * This should be case-insensitive.
     * Hint: the pattern ".*HELLO.*" searches for the word HELLO in the string. any chain of characters can exist before
     *       or after the word.
     * To transform a string variable aString to uppercase you can use:
     *      transform(aString.begin(), aString.end(), aString.begin(), ::toupper);
     *
     * Check out regex and regex_match:  https://en.cppreference.com/w/cpp/regex/regex_match
     *
     */

    vector<shared_ptr<Book>> foundBooks;
    string titleUpper;
    transform(titlePattern.begin(), titlePattern.end(), ::back_inserter(titleUpper), ::toupper); /** Making searchString toupper*/
    titleUpper = ".*" + titleUpper + ".*";
    regex check(titleUpper); /** Changing to regex type */
    for (int i =1; i< books->getLength() + 1; i++ ){
        shared_ptr<Book> aBook = books->getEntry(i);
        string temp = aBook->getTitle(); /** Current movie title */
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (regex_match(temp, check)){ /** Checking if the target string*/
            foundBooks.push_back(aBook);
        }
    }


    /**
     * YOUR CODE HERE
     */
    return foundBooks;
}

/**********************************************************************************************************************/

void Library:: addToDropBox(const string& bookTitle) {
    for (int i = 1; i < books->getLength() + 1; i++) {
        if (books->getEntry(i)->getTitle() == bookTitle) {
            dropBox->push(books->getEntry(i));
        }
    }
}
/**********************************************************************************************************************/
std::ostream& operator<<(std::ostream& out, const Library& service) {
    out << std::endl;
    out << "Books in the Library: " << std::endl;
    for(int i = 1; i < service.books->getLength() + 1; i++)
        out<< *service.books->getEntry(i) << std::endl;
    out<< "--------------------------------------------"<<std::endl;

    return out;
}



/*********************************************************************************************************************/
void Library::addToDropBox(shared_ptr<Book> aBook) {
    dropBox->push(aBook);
}
void Library::checkInDropBox() {
    while(!dropBox->isEmpty())
        dropBox->pop();
}

void Library::displayPatron(shared_ptr<Patron> &aPatron) {
    cout << left <<
         setw(10) << aPatron->getName() << " -- " <<
         setw(20) << aPatron->getAddress() << " -- " <<
         setw(30) << aPatron->getPhoneNumber() << endl;
}

void Library::removeByTitle(string& title) {
    bool removed;
    for (int i = 1; i < books->getLength() + 1; i++)
        if (books->getEntry(i)->getTitle() == title)
            removed = books->remove(i);
    if(!removed)
        cout << "No book found with entered title. Please retry." << endl;
}

void Library::placeHold(shared_ptr<Patron> &aPatron, string& title) {
    bool holdPlaced = false;
    for (int i = 1; i < books->getLength() + 1; i++)
        if (books->getEntry(i)->getTitle() == title)
            holdPlaced = books->getEntry(i)->addToHold(aPatron);
    if(!holdPlaced)
        cout << "Book with entered title was not found. Please retry." << endl;
}
