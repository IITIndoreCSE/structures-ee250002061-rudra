#include <iostream>
#include <fstream>
#include <string>

// Struct definition
struct Book {
    std::string title;
    std::string author;
    int year;
    int pages;
    std::string isbn;
};

// Output function as provided
void print_book(int index, const char* title, const char* author,
                int year, int pages, const char* isbn) {
    std::cout << "Book[" << index << "]: "
              << "title=" << title << ", "
              << "author=" << author << ", "
              << "year=" << year << ", "
              << "pages=" << pages << ", "
              << "isbn=" << isbn << "\n";
}

int main() {
    std::ifstream infile("books.txt");  // Input file

    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    int num_books;
    infile >> num_books;
    infile.ignore(); // To skip newline after number

    // Create a dynamic array of books
    Book* books = new Book[num_books];

    for (int i = 0; i < num_books; ++i) {
        std::getline(infile, books[i].title);
        std::getline(infile, books[i].author);
        infile >> books[i].year;
        infile >> books[i].pages;
        infile.ignore(); // Skip newline
        std::getline(infile, books[i].isbn);
    }

    // Print books using the output function
    for (int i = 0; i < num_books; ++i) {
        print_book(i,
                   books[i].title.c_str(),
                   books[i].author.c_str(),
                   books[i].year,
                   books[i].pages,
                   books[i].isbn.c_str());
    }

    delete[] books; // Free allocated memory
    return 0;
}

