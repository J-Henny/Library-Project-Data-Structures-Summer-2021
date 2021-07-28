#include "Patron.h"
Patron::Patron(): name("") {}

Patron::Patron(const string &aName, const string &anAddress, const int &aNum): name(aName), address(anAddress), phoneNumber(aNum){}

Patron::~Patron() = default;

const string &Patron::getName() const {
    return name;
}

const string &Patron:: getAddress() const{
    return address;
}
const int& Patron::getPhoneNumber() const {
    return phoneNumber;
}
void Patron::setName(const string &aName) {
    Patron::name = aName;
}



