#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan(const std::string& isbn, const std::string& memberId,
         const std::string& startDate, const std::string& dueDate);
    
    void markReturned();
    bool isOverdue(const std::string& today) const;
    
    std::string getIsbn() const;
    std::string getMemberId() const;
    std::string getStartDate() const;
    std::string getDueDate() const;
    bool isReturned() const;
    
    std::string to_string() const;
};

#endif