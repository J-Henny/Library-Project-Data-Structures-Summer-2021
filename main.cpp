/**
 * Laboratory #6 - CSCI2421 - Summer 2021
 * File: main.cpp
 */

#include <iostream> // For cout and cin
#include "memory"   // for smart (managed) pointers
#include "Book.h"
#include "Library.h"

using namespace std;

/**********************************************************************************************************************/
int displayMenu(){
    int option=0;
    cout<<endl<<endl;
    cout << "------------------------------------------------" << endl;
    cout << "                    CSE LIBRARY MAIN MENU       " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "      1) Book: Add                     " << endl;
    cout << "      2) Book: List Available          " << endl;
    cout << "      3) Book: List Checked Out        " << endl;
    cout << "      4) Book: Remove by title         " << endl;
    cout << "      5) Book: Search                  " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "      6) Patron: Add                   " << endl;
    cout << "      7) Patrons: List                 " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "      8) Check Out Book                " << endl;
    cout << "      9) Place Hold                    " << endl;
    cout << "      10) Place Book to Drop Box       " << endl;
    cout << "      11) Check In Books From Drop Box " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "      20) Load Data                    " << endl;
    cout << "      21) Save Data                    " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "                            99) Quit   " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "------------------------------------------------" << endl;
    while ((option < 1 || option>11)  &&(option <20 || option>21)){
        cout << "      Select your option [1-4/99]>> ";
        cin >> option;
        if (option == 99)
            return -1;
    }
    return option;

}
/**********************************************************************************************************************/
/**
 * Displays a movie.
 * @param aMovie
 */
void displayBook(shared_ptr<Book>& aBook){
    cout << aBook->getTitle() << endl;
}

/**********************************************************************************************************************/
/**
 * Loads the database to myService StreamingService
 * @param myService
 */
void loadDatabase(shared_ptr<Library>& myLibrary){

}


/**********************************************************************************************************************/
int main(){
    cout << string(120, '=')  << endl;
    cout << string(50, ' ')<< "PA Assignment"  << endl;
    cout << string(120, '=')  << endl;

    auto myLibrary = make_shared<Library>();

    cout<<endl<<endl;
    cout << string(120, '*')  << endl;
    cout << "Loading Database...."<<endl;
    loadDatabase(myLibrary);


    int option = 0;
    string searchBook;
    string pattern;
    string name;
    string address;
    string number;
    string holder;
    string filename;
    int num;
    string title;
    string authorNames;
    string ISBNnumber;
    string dateOfPub;
    string totalPages;
    string divider = ",";
    int numPages;
    string publisher;
    LinkedBag<shared_ptr<Author>> theAuthors;

    while (option>=0){
        option = displayMenu();
        switch (option) {
            case 1: // Add Book
                {
                    cout<<endl<<endl;
                    cout << string(120,'*') << endl;
                    cin.ignore(1, '\n');

                    cout<< "Type book title ";
                    getline(cin, title);

                    cout<< "Type book author name (if multiple separate by comma ',') ";
                    getline(cin, authorNames);

                    cout<< "Type ISBN number ";
                    getline(cin, ISBNnumber);

                    cout<< "Type date published ";
                    getline(cin, dateOfPub);

                    cout<< "Type book length (pages) ";
                    getline(cin, totalPages);

                    cout<< "Type Publisher ";
                    getline(cin, publisher);

                    numPages=stoi(totalPages);
                    size_t pos = 0;
                    string token;
                    while ((pos = authorNames.find(divider)) != string::npos) {
                        token = authorNames.substr(0, pos);
                        shared_ptr<Author> anAuthor = make_shared<Author>(token);
                        theAuthors.add(anAuthor);
                        authorNames.erase(0, pos + divider.length());
                    }

                    myLibrary->addBook(title, theAuthors, ISBNnumber, dateOfPub, numPages, publisher);
                    break;
                }


            case 2: // List Available Books.
                {
                    vector<shared_ptr<Book>> availableBooks = myLibrary->getAvailable();
                    if (availableBooks.empty())
                        cout << "NO Available Books Found." << endl;
                    else {
                        cout << "Available Books" << endl;
                        cout << "--------------------------------------------------------" << endl;
                        for (const auto &book: availableBooks)
                            cout << *book << endl;
                        cout << "--------------------------------------------------------" << endl;
                    }
                    break;
                }

            case 3: //List of checked out books.
                {
                    vector<shared_ptr<Book>> checkedOutBooks = myLibrary->getCheckedOut();
                    if (checkedOutBooks.empty())
                        cout << "NO Checked Out Books Found." << endl;
                    else {
                        cout << "Checked Out Books" << endl;
                        cout << "--------------------------------------------------------" << endl;
                        for (const auto &book: checkedOutBooks)
                            cout << *book << endl;
                        cout << "--------------------------------------------------------" << endl;
                    }
                    break;
                }

            case 4://Remove book by title
                {
                    cout<<endl<<endl;
                    cout << string(120,'*') << endl;
                    cin.ignore(1, '\n');

                    cout<< "Type book title (case sensitive)>> ";
                    getline(cin, searchBook);
                    myLibrary->searchBookExact(searchBook);
                    /*cout << "Is " << searchBook << "in the database? "
                         << boolalpha << myLibrary->searchBookExact(searchBook)<<endl;*/
                    break;

                }

            case 5: //Search Book by pattern.
                {
                    cout<<endl<<endl;
                    cout << string(120,'*') << endl;
                    cin.ignore(1, '\n');

                    cout << "Input title search pattern>>";
                    getline(cin, pattern);

                    vector<shared_ptr<Book>> searchBooks = myLibrary->searchBookPattern(pattern);

                    if (searchBooks.empty())
                        cout << "NO Matching Books Found." << endl;
                    else {
                        cout << "Matching Books" << endl;
                        cout << "--------------------------------------------------------" << endl;
                        for (const auto &book: searchBooks)
                            cout << *book << endl;
                        cout << "--------------------------------------------------------" << endl;
                    }
                    break;
                }

            case 6: //Add patron.
            {
                cout<<endl<<endl;

                cout << string(120,'*') << endl;
                cin.ignore(1, '\n');

                cout<< "Type patron name ";
                getline(cin, name);

                cout<< "Type patron address ";
                getline(cin, address);

                cout<< "Type patron address ";
                getline(cin, number);

                num = stoi(number);

                myLibrary->addPatron(name, address, num);
                break;
            }

            case 7: //List patron.
            {
                myLibrary->getPatrons();
                break;
            }

            case 8: //Check out book.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cin.ignore(1, '\n');

                cout<< "Type book title (case sensitive)>> ";
                getline(cin, searchBook);

                cout<< "Who is checking out the book ";
                getline(cin, holder);
                myLibrary->checkOutBook(searchBook, holder);
                break;

            case 9: //Place Hold.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cout << "Movies -- Sorted by Title" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                break;

            case 10: //Add book to drop box.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cout << "Movies -- Sorted by Title" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                break;

            case 11: //Check in books.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cout << "Movies -- Sorted by Title" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                break;

            case 20: //Load Data.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cout << "Movies -- Sorted by Title" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                break;

            case 21: //Save Data.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cout << "Movies -- Sorted by Title" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                break;

        }
    }
    cout << "Program Terminated." << endl;
    return 0;
}
