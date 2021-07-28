
#include "iostream"
#include "Book.h"

#include <utility>

/**********************************************************************************************************************/
Book::Book() = default;

/**********************************************************************************************************************/
Book::Book(const string aTitle, LinkedBag<shared_ptr<Author>> theAuthors, const string& ISBNnum,
           const string& dateOfPub, const int numOfPages, const string& publish) : title(std::move(aTitle)), authors(theAuthors), ISBN(ISBNnum),
                                                            dateOfPublication(dateOfPub), numPages(numOfPages), publisher(publish) {}

/**********************************************************************************************************************/
Book::~Book() {
    vector<shared_ptr<Author>> vecActors = this->authors.toVector();

    for (const shared_ptr<Author>& anAuthor: vecActors){
        this->authors.remove(anAuthor);
    }
}

/**********************************************************************************************************************/
string Book::getTitle() const {
    return this->title;
}

/**********************************************************************************************************************/
void Book::setTitle(const string &aTitle) {
    this->title = aTitle;
}

string Book::getDateofPub() const{
    return dateOfPublication;
}

/**********************************************************************************************************************/
ostream& operator<<(ostream& out, const Book& aBook) {
    out << ">>"
        << aBook.getTitle() << "--"
        << aBook.getDateofPub() << "<<" <<endl;

    for (const shared_ptr<Author>& anAuthor: aBook.getAuthors())
        out << anAuthor <<endl;

    return out;
}

/**********************************************************************************************************************/
bool Book::addAuthor(const shared_ptr<Author>& anAuthor) {
    if (this->authors.contains(anAuthor))
        return false;
    else{
        return this->authors.add(anAuthor);
    }
}

/**********************************************************************************************************************/
bool Book::removeAuthor(const shared_ptr<Author> &anAuthor) {
    return this->authors.remove(anAuthor);
}

/**********************************************************************************************************************/
void Book::checkOut(const string &holder){
    checkedOut=true;
    currentHolder = holder;
}
/**********************************************************************************************************************/
vector<shared_ptr<Author>> Book::getAuthors() const {
    return this->authors.toVector();
}

Book::Book(const LinkedQueue<shared_ptr<Patron>>& aHold) : hold(aHold) {}

bool Book::addToHold(shared_ptr<Patron> aPatron) {
    hold.enqueue(aPatron);
    return true;
}

bool Book::getChecked() const {
    return checkedOut;
}
void Book::setChecked(bool check) {
    checkedOut = check;
}
string Book::getCurrentHolder() const {
    return currentHolder;
}
void Book::setCurrentHolder(const string aHolder) {
    currentHolder = aHolder;
}

bool Book::isHoldQueueEmpty() const {
    return hold.isEmpty();
}
shared_ptr<Patron> Book::getFirstHold() {
    if(!isHoldQueueEmpty()){
        shared_ptr<Patron> nextToCheck = hold.peekFront();
        hold.dequeue();
        return nextToCheck;
    }
    else
        return nullptr;
}

void Book::displayAuthors() const {
    vector<shared_ptr<Author>> authVect = authors.toVector();
    for(const shared_ptr<Author>& anAuthor: authVect)
        cout << anAuthor << " ";
    cout << '\n';

}

