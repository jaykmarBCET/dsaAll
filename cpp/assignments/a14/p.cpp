#include <iostream>
using namespace std;
//p1
class Complex {
    int real, img;

public:
    
    Complex() : real(0), img(0) {}

    
    Complex(int r, int i) {
        real = r;
        img = i;
    }

  
    friend Complex operator+(const Complex &, const Complex &);
    friend Complex operator-(const Complex &, const Complex &);
    friend Complex operator*(const Complex &, const Complex &);

    // Display Function
    void showData() {
        cout << real << " + " << img << "i" << endl;
    }
};


Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.img + c2.img);
}


Complex operator-(const Complex &c1, const Complex &c2) {
    return Complex(c1.real - c2.real, c1.img - c2.img);
}


Complex operator*(const Complex &c1, const Complex &c2) {
    int realPart = c1.real * c2.real - c1.img * c2.img;
    int imgPart = c1.real * c2.img + c1.img * c2.real;
    return Complex(realPart, imgPart);
}

class Time;
int main() {
    Complex c1(3, 2), c2(1, 7);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "Sum: ";
    sum.showData();

    cout << "Difference: ";
    diff.showData();

    cout << "Product: ";
    prod.showData();

    return 0;
}
//p2
class Time{
    int hr,min,sec;
    public:
       
       Time operator<<(Time &t){

       }
       int getHr(){return hr;}
       int getMin(){return min;}
       int getSec(){return sec;}

};