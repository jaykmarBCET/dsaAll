#include <iostream>
#include <cstring>  // Correct header for strcpy
using namespace std;

struct Book {
    int bookId;
    char title[50];
    float price;
};


void input(Book *);  
void display(Book);  

int main() {
    Book b1 = {100, "C in Depth", 546.0f};  
    Book b2, b3;
    
    strcpy(b2.title, "Jay Kumar");  
    
    input(&b3);   
    display(b3);  
    
    return 0;
}


void display(Book b) {
    cout << "\nBook ID: " << b.bookId << endl;
    cout << "Book Title: " << b.title << endl;
    cout << "Book Price: " << b.price << endl;
}


void input(Book *p) {
    cout << "Enter Book ID, Title, and Price: ";
    cin >> p->bookId;
    cin.ignore();  
    cin.getline(p->title, 50);  
    cin >> p->price;
}
