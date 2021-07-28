#include "Author.h"

Author::Author(): name(""){}
Author::Author(const string& aName): name(aName) {}
Author::~Author() = default;

const string &Author::getName() const {
    return name;
}

void Author::setName(const string &aName) {
    Author::name = aName;
}



