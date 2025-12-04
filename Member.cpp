#include "Member.h"
#include <stdexcept>
#include <sstream>

Member::Member() : name("Unknown"), memberId(""), yearJoined(2023) {}

Member::Member(const std::string& name, const std::string& memberId, int yearJoined)
    : name(name), memberId(memberId), yearJoined(yearJoined) {
    if (memberId.empty()) {
        throw std::invalid_argument("Member ID cannot be empty");
    }
    if (yearJoined < 1900 || yearJoined > 2025) {
        throw std::invalid_argument("Year joined must be between 1900 and 2025");
    }
}

std::string Member::getName() const {
    return name;
}

std::string Member::getMemberId() const {
    return memberId;
}

int Member::getYearJoined() const {
    return yearJoined;
}

std::string Member::to_string() const {
    std::ostringstream oss;
    oss << "Member: " << name << " (ID: " << memberId 
        << ", Joined: " << yearJoined << ")";
    return oss.str();
}