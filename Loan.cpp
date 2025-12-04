#include "Loan.h"
#include <stdexcept>
#include <sstream>

Loan::Loan(const std::string& isbn, const std::string& memberId,
           const std::string& startDate, const std::string& dueDate)
    : isbn(isbn), memberId(memberId), startDate(startDate), 
      dueDate(dueDate), returned(false) {

    if (dueDate < startDate) {
        throw std::invalid_argument("Due date cannot be before start date");
    }
}

void Loan::markReturned() {
    returned = true;
}

bool Loan::isOverdue(const std::string& today) const {
    return !returned && (today > dueDate);
}

std::string Loan::getIsbn() const {
    return isbn;
}

std::string Loan::getMemberId() const {
    return memberId;
}

std::string Loan::getStartDate() const {
    return startDate;
}

std::string Loan::getDueDate() const {
    return dueDate;
}

bool Loan::isReturned() const {
    return returned;
}

std::string Loan::to_string() const {
    std::ostringstream oss;
    oss << "Loan: ISBN=" << isbn << ", Member=" << memberId 
        << ", Start=" << startDate << ", Due=" << dueDate 
        << ", Status=" << (returned ? "Returned" : "Active");
    return oss.str();
}