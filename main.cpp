#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;
    
    Author a{"Ivan Vazov", 1850};
    
    Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
    Book b2{"Nema zemya", a, 1900, 18.90, "ISBN-002"};
    
    lib.addBook(b1);
    lib.addBook(b2);
    
    lib.addMember(Member{"Petar Petrov", "M001", 2023});
    
    cout << lib.to_string() << "\n\n";
    
    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17")) {
        cout << "Loan created.\n";
    }
    
    cout << "Available ISBN-001? " << boolalpha 
         << lib.isBookAvailable("ISBN-001") << "\n";
    
    lib.returnBook("ISBN-001", "M001");
    
    cout << "Available ISBN-001? " << boolalpha 
         << lib.isBookAvailable("ISBN-001") << "\n\n";
    
    cout << "Books by Vazov:\n";
    for (const auto& bk : lib.findByAuthor("Vazov")) {
        cout << bk.to_string() << "\n";
    }
    
    cout << "\n=== Additional Tests ===\n\n";
    
    Author hristo{"Hristo Botev", 1848};
    Book b3{"Poema za Hadji Dimitar", hristo, 1873, 15.00, "ISBN-003"};
    lib.addBook(b3);
    
    lib.addMember(Member{"Maria Ivanova", "M002", 2024});
    
    cout << "Testing multiple loans:\n";
    if (lib.loanBook("ISBN-002", "M002", "2025-12-01", "2025-12-15")) {
        cout << "Loan ISBN-002 to M002: Success\n";
    }
    
    if (lib.loanBook("ISBN-003", "M001", "2025-12-02", "2025-12-16")) {
        cout << "Loan ISBN-003 to M001: Success\n";
    }
    
    if (!lib.loanBook("ISBN-002", "M001", "2025-12-03", "2025-12-17")) {
        cout << "Loan ISBN-002 to M001: Failed (book not available)\n";
    }
    
    cout << "\n" << lib.to_string() << "\n";
    
    return 0;
}