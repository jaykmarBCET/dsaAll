#include <iostream>
#include <string>
using namespace std;

struct Book {
private:
    int bookId;
    string title;
    float price;

public:
    void input() {
        cout << "Enter book ID, title, and price: ";
        cin >> bookId;
        cin.ignore();  // Clears the newline from the input buffer
        getline(cin, title);  // ✅ Corrected to use std::getline for std::string
        cin >> price;
    }

    void show() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    void set(int bookId, string title, float price) {
        this->bookId = bookId;
        this->title = title;
        this->price = price;
    }

    void setPrice(float price) { this->price = price; }
    void setTitle(string title) { this->title = title; }
    void setId(int bookId) { this->bookId = bookId; }

    int getId() { return this->bookId; }
    float getPrice() { return this->price; }
    string getTitle() { return this->title; }
};

int main() {
    Book b1;
    b1.setId(34);
    b1.setTitle("Java");
    b1.setPrice(499.99);
    
    
    b1.show();

    return 0;
}
