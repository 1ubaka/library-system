#include "Book.h"
#include <stdexcept>
#include <sstream>

int Book::totalBooks = 0;

Book::Book() 
    : title("Untitled"), author(), year(2000), price(0.0), isbn("") {
    totalBooks++;
}

Book::Book(const std::string& title, const Author& author, int year, 
           double price, const std::string& isbn)
    : title(title), author(author), year(year), price(price), isbn(isbn) {
    if (price < 0) {
        throw std::invalid_argument("Price cannot be negative");
    }
    if (year < 1000 || year > 2025) {
        throw std::invalid_argument("Year must be between 1000 and 2025");
    }
    totalBooks++;
}

Book::Book(const Book& other)
    : title(other.title), author(other.author), year(other.year),
      price(other.price), isbn(other.isbn) {
    totalBooks++;
}

Book::Book(Book&& other) noexcept
    : title(std::move(other.title)), author(std::move(other.author)),
      year(other.year), price(other.price), isbn(std::move(other.isbn)) {
    totalBooks++;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        title = other.title;
        author = other.author;
        year = other.year;
        price = other.price;
        isbn = other.isbn;
    }
    return *this;
}

Book& Book::operator=(Book&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
        author = std::move(other.author);
        year = other.year;
        price = other.price;
        isbn = std::move(other.isbn);
    }
    return *this;
}

Book::~Book() {
    totalBooks--;
}

// Getters
std::string Book::getTitle() const {
    return title;
}

Author Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

double Book::getPrice() const {
    return price;
}

std::string Book::getIsbn() const {
    return isbn;
}

void Book::setPrice(double newPrice) {
    if (newPrice < 0) {
        throw std::invalid_argument("Price cannot be negative");
    }
    price = newPrice;
}

void Book::setYear(int newYear) {
    if (newYear < 1000 || newYear > 2025) {
        throw std::invalid_argument("Year must be between 1000 and 2025");
    }
    year = newYear;
}

int Book::getTotalBooks() {
    return totalBooks;
}

std::string Book::to_string() const {
    std::ostringstream oss;
    oss << "\"" << title << "\" by " << author.to_string() 
        << " (" << year << "), Price: " << price 
        << " BGN, ISBN: " << isbn;
    return oss.str();
}