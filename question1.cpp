#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    int pages;
    string isbn;
};

void print_book(int index, const Book &book) {
    cout << "Book[" << index << "]:\n"
         << " title=" << book.title << ",\n"
         << " author=" << book.author << ",\n"
         << " year=" << book.year << ",\n"
         << " pages=" << book.pages << ",\n"
         << " isbn=" << book.isbn << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening file " << argv[1] << endl;
        return 1;
    }

    Book book;
    int index = 0;

    // Expected file format: title author year pages isbn (all separated by whitespace)
    while (input >> book.title >> book.author >> book.year >> book.pages >> book.isbn) {
        print_book(index++, book);
    }

    input.close();
    return 0;
}

