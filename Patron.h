#ifndef INC_2021_SUMMER_CSCI2421_PATRON_H
#define INC_2021_SUMMER_CSCI2421_PATRON_H

#include <string>
#include "memory"


using namespace std;

class Patron {
private:
    string name;
    string address;
    int phoneNumber;

public:
    explicit Patron();
    explicit Patron(const string& aName, const string &anAddress, const int &aNum);
    virtual ~Patron();
    const string& getAddress() const;
    const int& getPhoneNumber() const;

    const string &getName() const;
    void setName(const string &aName);


    friend ostream& operator<<(ostream& out, const Patron& aPatron);
};



#include "Patron.cpp"
#endif //INC_2021_SUMMER_CSCI2421_PATRON_H
