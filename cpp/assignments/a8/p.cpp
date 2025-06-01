#include <iostream>
using namespace std;

//p1
class Complex{
    private:
      int real;
      int img;
    public:
      void setData(int,int);
      void showData();
      int getReal();
      int getImag();
      Complex add(Complex);
      Complex mul(Complex);
      

};

void Complex::setData(int r,int i){
    real = r;
    img = i;
}
void Complex::showData(){
    cout<<"real= "<<real<<" img= "<<img<<endl;
}
int Complex::getReal(){
    return real;
}
int Complex::getImag(){
    return img;
}
Complex Complex::add(Complex c){
    Complex temp;
    temp.real = real+ c.real;
    temp.img  = img + c.img;
    return temp;
}
Complex Complex::mul(Complex c){
    Complex temp ;
    temp.real = real* c.real;
    temp.img = img * c.img;
    return temp;
}

//p2
class Time{
    private:
       int hh;
       int mm;
       int ss;
    public:
       void setTime(int hh,int mm,int ss);
       void showTime();
       void display();

};

void Time::setTime(int hh,int mm,int ss){
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
}

void Time::showTime(){
    cout<<"hours: "<<hh<<" min: "<<mm<<" sec: "<<ss; 
}
//p3

class Date{
    private:
      int day;
      int month;
      int year;
    public:
      void setDate(int day,int month,int year);
      void showDate();
      void display();
};

void Date::setDate(int day,int month,int year){
    this->day=day;
    this->month = month;
    this->year = year;
}
void Date::showDate(){
    cout<<day<<"-"<<month<<"-"<<year;
}

//p4
class Circle{
    private:
      int radius;
    public:
       void setRadius(int r){
        this->radius =r;
       }
       int getRadius(){
        return radius;
       }
       int area(){
        return 3.14*radius*radius;
       }

};
