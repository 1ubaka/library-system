#include "Library.h"
#include <sstream>
#include <algorithm>

void Library::addBook(const Book& b) {
    books.push_back(b);
}

void Library::addMember(const Member& m) {
    members.push_back(m);
}

bool Library::hasBook(const std::string& isbn) const {
    for (const auto& book : books) {
        if (book.getIsbn() == isbn) {
            return true;
        }
    }
    return false;
}

bool Library::isBookAvailable(const std::string& isbn) const {
    if (!hasBook(isbn)) {
        return false;
    }
    
    for (const auto& loan : loans) {
        if (loan.getIsbn() == isbn && !loan.isReturned()) {
            return false;
        }
    }
    
    return true;
}

bool Library::loanBook(const std::string& isbn, const std::string& memberId,
                       const std::string& start, const std::string& due) {
    if (!isBookAvailable(isbn)) {
        return false;
    }
    
    bool memberExists = false;
    for (const auto& member : members) {
        if (member.getMemberId() == memberId) {
            memberExists = true;
            break;
        }
    }
    
    if (!memberExists) {
        return false;
    }
    
    try {
        Loan newLoan(isbn, memberId, start, due);
        loans.push_back(newLoan);
        return true;
    } catch (...) {
        return false;
    }
}

bool Library::returnBook(const std::string& isbn, const std::string& memberId) {
    for (auto& loan : loans) {
        if (loan.getIsbn() == isbn && 
            loan.getMemberId() == memberId && 
            !loan.isReturned()) {
            loan.markReturned();
            return true;
        }
    }
    return false;
}

std::vector<Book> Library::findByAuthor(const std::string& authorName) const {
    std::vector<Book> result;
    
    for (const auto& book : books) {
        std::string bookAuthorName = book.getAuthor().getName();
        if (bookAuthorName.find(authorName) != std::string::npos) {
            result.push_back(book);
        }
    }
    
    return result;
}

std::string Library::to_string() const {
    std::ostringstream oss;
    
    int activeLoans = 0;
    for (const auto& loan : loans) {
        if (!loan.isReturned()) {
            activeLoans++;
        }
    }
    
    oss << "=== Library Statistics ===\n";
    oss << "Total Books: " << books.size() << "\n";
    oss << "Total Members: " << members.size() << "\n";
    oss << "Total Loans: " << loans.size() << "\n";
    oss << "Active Loans: " << activeLoans << "\n";
    oss << "Book instances (static): " << Book::getTotalBooks();
    
    return oss.str();
}