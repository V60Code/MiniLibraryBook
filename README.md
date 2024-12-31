# MiniLibraryBook

**MiniLibraryBook** is a simple console-based application for managing a personal book library. It provides basic functionalities like adding, editing, deleting, and viewing books, all while storing the data in a text file.

---

## Features

1. **Add Book**: Add a new book with details such as title, author, year, and genre.
2. **Edit Book Information**: Modify existing book details.
3. **Delete Book**: Remove a book from the library.
4. **Display Total Books**: View the total number of books and their details.
5. **Credits**: Displays the creator's information.
6. **Exit**: Safely exit the application.

---

## How to Run

### Prerequisites
1. Install a C++ compiler, such as `g++`.
2. Clone this repository:
   git clone https://github.com/V60Code/MiniLibraryBook.git
3. Navigate to the project directory:
    cd MiniLibraryBook

## Compile and Execute
1. Compile the program:
    ```bash
    g++ -std=c++11 -o MiniLibraryBook MiniLibraryBook.cpp
    
2. Run the compiled program:
    ```bash
    ./MiniLibraryBook

## Example Usage

### Main Menu
    === MiniLibraryBook Menu ===
    1. Add Book
    2. Edit Book Information
    3. Delete Book
    4. Display Total Books
    5. Exit
    6. Credits
    Choose an option (1-6): 

### Adding a Book
    Enter book title: The Great Gatsby
    Enter book author: F. Scott Fitzgerald
    Enter book year: 1925
    Enter book genre: Fiction
    Book added successfully!

### Displaying Books
    Total books: 1
    1. Title: The Great Gatsby, Author: F. Scott Fitzgerald, Year: 1925, Genre: Fiction

### File Structure
- MiniLibraryBook.cpp: The main source code for the application.
- books.txt: Automatically generated file for storing book data.
