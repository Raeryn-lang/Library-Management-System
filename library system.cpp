// ============================================
// SIMPLE LIBRARY MANAGEMENT SYSTEM
// Perfect for 1st Year C++ Assignment
// ============================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ========== BOOK CLASS ==========
class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    // Constructor
    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;
    }

    // Getter functions
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return isbn; }
    bool isBookAvailable() { return available; }

    // Borrow and return functions
    void borrow() { available = false; }
    void returnBook() { available = true; }

    // Display book info
    void display() {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nISBN: " << isbn;
        cout << "\nStatus: " << (available ? "Available" : "Borrowed");
        cout << "\n-------------------\n";
    }
};

// ========== USER CLASS ==========
class User {
private:
    string name;
    string id;

public:
    // Constructor
    User(string n, string i) {
        name = n;
        id = i;
    }

    // Getter functions
    string getName() { return name; }
    string getID() { return id; }

    // Display user info
    void display() {
        cout << "\nName: " << name;
        cout << "\nUser ID: " << id;
        cout << "\n-------------------\n";
    }
};

// ========== LIBRARY CLASS ==========
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    // Add a book to library
    void addBook() {
        string title, author, isbn;
        
        cout << "\nEnter book title: ";
        cin.ignore();
        getline(cin, title);
        
        cout << "Enter author: ";
        getline(cin, author);
        
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        
        Book newBook(title, author, isbn);
        books.push_back(newBook);
        
        cout << "\nBook added successfully!\n";
    }

    // Display all books
    void showAllBooks() {
        if (books.empty()) {
            cout << "\nNo books in library!\n";
            return;
        }
        
        cout << "\n=== ALL BOOKS ===\n";
        for (int i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }

    // Search for a book
    void searchBook() {
        string search;
        bool found = false;
        
        cout << "\nEnter title, author or ISBN to search: ";
        cin.ignore();
        getline(cin, search);
        
        cout << "\n=== SEARCH RESULTS ===\n";
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle().find(search) != string::npos ||
                books[i].getAuthor().find(search) != string::npos ||
                books[i].getISBN().find(search) != string::npos) {
                books[i].display();
                found = true;
            }
        }
        
        if (!found) {
            cout << "No books found!\n";
        }
    }

    // Remove a book
    void removeBook() {
        string isbn;
        bool found = false;
        
        cout << "\nEnter ISBN of book to remove: ";
        cin.ignore();
        getline(cin, isbn);
        
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getISBN() == isbn) {
                books.erase(books.begin() + i);
                cout << "\nBook removed successfully!\n";
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "\nBook not found!\n";
        }
    }

    // Add a user
    void addUser() {
        string name, id;
        
        cout << "\nEnter user name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter user ID: ";
        getline(cin, id);
        
        User newUser(name, id);
        users.push_back(newUser);
        
        cout << "\nUser added successfully!\n";
    }

    // Show all users
    void showAllUsers() {
        if (users.empty()) {
            cout << "\nNo users registered!\n";
            return;
        }
        
        cout << "\n=== ALL USERS ===\n";
        for (int i = 0; i < users.size(); i++) {
            users[i].display();
        }
    }

    // Borrow a book
    void borrowBook() {
        string userID, bookISBN;
        bool userFound = false, bookFound = false;
        
        cout << "\nEnter user ID: ";
        cin.ignore();
        getline(cin, userID);
        
        // Find user
        int userIndex = -1;
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getID() == userID) {
                userFound = true;
                userIndex = i;
                break;
            }
        }
        
        if (!userFound) {
            cout << "\nUser not found!\n";
            return;
        }
        
        cout << "Enter book ISBN to borrow: ";
        getline(cin, bookISBN);
        
        // Find book
        int bookIndex = -1;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getISBN() == bookISBN) {
                bookFound = true;
                bookIndex = i;
                break;
            }
        }
        
        if (!bookFound) {
            cout << "\nBook not found!\n";
            return;
        }
        
        if (!books[bookIndex].isBookAvailable()) {
            cout << "\nBook is already borrowed!\n";
            return;
        }
        
        // Borrow the book
        books[bookIndex].borrow();
        cout << "\nBook borrowed successfully by " << users[userIndex].getName() << "!\n";
    }

    // Return a book
    void returnBook() {
        string userID, bookISBN;
        bool userFound = false, bookFound = false;
        
        cout << "\nEnter user ID: ";
        cin.ignore();
        getline(cin, userID);
        
        // Find user
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getID() == userID) {
                userFound = true;
                break;
            }
        }
        
        if (!userFound) {
            cout << "\nUser not found!\n";
            return;
        }
        
        cout << "Enter book ISBN to return: ";
        getline(cin, bookISBN);
        
        // Find book
        int bookIndex = -1;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getISBN() == bookISBN) {
                bookFound = true;
                bookIndex = i;
                break;
            }
        }
        
        if (!bookFound) {
            cout << "\nBook not found!\n";
            return;
        }
        
        if (books[bookIndex].isBookAvailable()) {
            cout << "\nBook was not borrowed!\n";
            return;
        }
        
        // Return the book
        books[bookIndex].returnBook();
        cout << "\nBook returned successfully!\n";
    }
};

// ========== MAIN FUNCTION ==========
int main() {
    Library library;
    int choice;
    
    cout << "=================================\n";
    cout << "LIBRARY MANAGEMENT SYSTEM\n";
    cout << "=================================\n";
    
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Remove Book\n";
        cout << "5. Add User\n";
        cout << "6. Show All Users\n";
        cout << "7. Borrow Book\n";
        cout << "8. Return Book\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.showAllBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.removeBook();
                break;
            case 5:
                library.addUser();
                break;
            case 6:
                library.showAllUsers();
                break;
            case 7:
                library.borrowBook();
                break;
            case 8:
                library.returnBook();
                break;
            case 9:
                cout << "\nThank you for using Library System!\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter 1-9.\n";
        }
        
    } while(choice != 9);
    
    return 0;
}