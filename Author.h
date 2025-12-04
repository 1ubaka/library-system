#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

class Author {
private:
    std::string name;
    int birthYear;

public:
    Author();
    
    Author(const std::string& name, int birthYear);
    
    std::string getName() const;
    int getBirthYear() const;
    
    void setBirthYear(int year);
    
    std::string to_string() const;
};

#endif