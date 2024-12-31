#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

// Function to load books from a text file
vector<Book> loadBooks(const string &filename) {
    vector<Book> books;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Book book;
            getline(ss, book.title, '|');
            getline(ss, book.author, '|');
            ss >> book.year;
            ss.ignore(); // Ignore the '|' character
            getline(ss, book.genre);
            books.push_back(book);
        }
        file.close();
    }
    return books;
}

// Function to save books to a text file
void saveBooks(const string &filename, const vector<Book> &books) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &book : books) {
            file << book.title << "|" << book.author << "|" << book.year << "|" << book.genre << "\n";
        }
        file.close();
    }
}

// Function to add a book
void addBook(vector<Book> &books) {
    Book book;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, book.title);

    cout << "Enter book author: ";
    getline(cin, book.author);

    while (true) {
        cout << "Enter book year: ";
        cin >> book.year;
        if (cin.fail() || book.year < 0 || book.year > 2100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid year. Enter a number between 0 and 2100.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    cout << "Enter book genre: ";
    getline(cin, book.genre);

    books.push_back(book);
    cout << "Book added successfully!\n";
}

// Function to edit book information
void editBook(vector<Book> &books) {
    if (books.empty()) {
        cout << "No books available to edit.\n";
        return;
    }

    int index;
    while (true) {
        cout << "Enter the book number to edit (1 - " << books.size() << "): ";
        cin >> index;
        if (cin.fail() || index < 1 || index > books.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid book number. Try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    index--; // Convert to zero-based index
    cout << "Enter new information for the book:\n";
    cout << "Title: ";
    getline(cin, books[index].title);
    cout << "Author: ";
    getline(cin, books[index].author);

    while (true) {
        cout << "Year: ";
        cin >> books[index].year;
        if (cin.fail() || books[index].year < 0 || books[index].year > 2100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid year. Enter a number between 0 and 2100.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    cout << "Genre: ";
    getline(cin, books[index].genre);
    cout << "Book updated successfully!\n";
}

// Function to delete a book
void deleteBook(vector<Book> &books) {
    if (books.empty()) {
        cout << "No books available to delete.\n";
        return;
    }

    int index;
    while (true) {
        cout << "Enter the book number to delete (1 - " << books.size() << "): ";
        cin >> index;
        if (cin.fail() || index < 1 || index > books.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid book number. Try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    index--; // Convert to zero-based index
    books.erase(books.begin() + index);
    cout << "Book deleted successfully!\n";
}

// Function to display total books
void displayBooks(const vector<Book> &books) {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << "Total books: " << books.size() << endl;
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". Title: " << books[i].title
             << ", Author: " << books[i].author
             << ", Year: " << books[i].year
             << ", Genre: " << books[i].genre << endl;
    }
}

// Function to display credits
void showCredits() {
    cout << "\n=== Credits ===\n";
    cout << "Name: Muhammad Alfarizi Habibullah || V60Code\n";
    cout << "https://github.com/V60Code\n";
    cout << "Thank you for using this application!\n";
}

// Main function
int main() {
    const string filename = "books.txt";
    vector<Book> books = loadBooks(filename);
    int choice;

    do {
        cout << "\n=== MiniLibraryBook Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. Edit Book Information\n";
        cout << "3. Delete Book\n";
        cout << "4. Display Total Books\n";
        cout << "5. Exit\n";
        cout << "6. Credits\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Enter a number between 1 and 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addBook(books);
                saveBooks(filename, books);
                break;
            case 2:
                editBook(books);
                saveBooks(filename, books);
                break;
            case 3:
                deleteBook(books);
                saveBooks(filename, books);
                break;
            case 4:
                displayBooks(books);
                break;
            case 5:
                cout << "Thank you for using MiniLibraryBook!\n";
                break;
            case 6:
                showCredits();
                break;
        }
    } while (choice != 5);

    return 0;
}
