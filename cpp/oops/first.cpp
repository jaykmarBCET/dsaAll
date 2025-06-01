#include <iostream>
#include <string>
using namespace std;


class Imaginary {
    int real;
    int imaginary;

public:
    
    Imaginary() : real(0), imaginary(0) {}

    
    Imaginary(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    // Setters
    void setReal(int real) {
        this->real = real;
    }
    
    void setImaginary(int imaginary) {
        this->imaginary = imaginary;
    }
    
    void setComplex(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    
    int getReal() { return this->real; }
    int getImaginary() { return this->imaginary; }

   
    string getComplex() {
        return to_string(real) + (imaginary >= 0 ? " + " : " - ") + to_string(abs(imaginary)) + "i";
    }

    
    friend ostream& operator<<(ostream& out, const Imaginary& obj) {
        out << obj.real << (obj.imaginary >= 0 ? " + " : " - ") << abs(obj.imaginary) << "i";
        return out;
    }
};


int main() {
    Imaginary num1;
    num1.setComplex(5, -3);
    cout << "Complex Number: " << num1.getComplex() << endl;
    
    Imaginary num2(4, 7);
    cout << "Another Complex Number: " << num2 << endl; // Using overloaded operator<<

    return 0;
}
