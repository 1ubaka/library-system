#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member();
    
    Member(const std::string& name, const std::string& memberId, int yearJoined);
    
    std::string getName() const;
    std::string getMemberId() const;
    int getYearJoined() const;
    
    std::string to_string() const;
};

#endif