#include "Author.h"
#include <stdexcept>
#include <sstream>

Author::Author() : name("Unknown"), birthYear(1900) {}

Author::Author(const std::string& name, int birthYear) 
    : name(name), birthYear(birthYear) {
    if (birthYear < 1800 || birthYear > 2025) {
        throw std::invalid_argument("Birth year must be between 1800 and 2025");
    }
}

std::string Author::getName() const {
    return name;
}

int Author::getBirthYear() const {
    return birthYear;
}

void Author::setBirthYear(int year) {
    if (year < 1800 || year > 2025) {
        throw std::invalid_argument("Birth year must be between 1800 and 2025");
    }
    birthYear = year;
}

std::string Author::to_string() const {
    std::ostringstream oss;
    oss << name << " (" << birthYear << ")";
    return oss.str();
}