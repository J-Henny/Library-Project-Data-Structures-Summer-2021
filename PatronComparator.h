#ifndef CSCI2421_PATRONCOMPARATOR_H
#define CSCI2421_PATRONCOMPARATOR_H

#include "memory"
#include "Patron.h"
#include "Comparator.h"

using namespace std;


class PatronComparator : public Comparator<shared_ptr<Patron>> {
public:
/**
 * @param lhs
 * @param rhs
 * @return  true when lhs.title < rhs.title. False otherwise.
 */
bool lessThan(const shared_ptr<Patron> &lhs, const shared_ptr<Patron> &rhs) noexcept(false) override {
if (lhs == nullptr || rhs == nullptr)
throw logic_error("Cant compare NULLPTR");

return lhs->getName() < rhs->getName();
};

/**
 * @param lhs
 * @param rhs
 * @return  true when lhs.title > rhs.title. False otherwise.
 */
bool greaterThan(const shared_ptr<Patron> &lhs, const shared_ptr<Patron> &rhs) noexcept(false) override {
if (lhs == nullptr || rhs == nullptr)
throw logic_error("Cant compare NULLPTR");

return lhs->getName() > rhs->getName();
};

/**
 * @param lhs
 * @param rhs
 * @return  true when lhs.title == rhs.title. False otherwise.
 */
bool equals(const shared_ptr<Patron> &lhs, const shared_ptr<Patron> &rhs) noexcept(false) override {
if (lhs == nullptr || rhs == nullptr)
throw logic_error("Cant compare NULLPTR");

return lhs->getName() == rhs->getName();
};
};


#endif
