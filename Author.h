#ifndef INC_2021_SUMMER_CSCI2421_AUTHOR_H
#define INC_2021_SUMMER_CSCI2421_AUTHOR_H

#include <string>
#include <vector>

using namespace std;

class Author {
private:
    string name;

public:
    explicit Author();
    explicit Author(const string& aName);
    virtual ~Author();

    const string &getName() const;
    void setName(const string &aName);
};

#include "Author.cpp"
#endif //INC_2021_SUMMER_CSCI2421_AUTHOR_H
