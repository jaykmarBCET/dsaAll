#include <iostream>
using namespace std;

//p1
class Cuboid{
    int l;
    int h;
    int b;
    public:
      Cuboid(int length,int height, int breadth):l(5),h(5),b(5){
        l = length;
        h = height;
        b = breadth;
      }
};

//p2
class Customer{
    int cust_id;
    char name[50],email[30];
    long int mob_no;
    public:
     Customer();
     Customer(int cust_id,char &name,char &email,long int mob_no){
        this->cust_id= cust_id;
        *this->name = name;
        *this->email = email;
        this->mob_no = mob_no;
     }
};

//p3

class Time{
    int hr,min,sec;
    public:
     Time():hr(6),min(30),sec(30){}
};
//p4
class Book{
    int book_id;
    char title[50];
    float price;
    public:
    Book();
    Book(int book_id,char &title,float price){
        this->book_id = book_id;
        *this->title = title;
        this->price = price;
    }
};
//p5

class Complex{
    int real;
    int img;
    public:
       Complex();
       void setData(int real,int img){
        this->real =real;
        this->img = img;
       }
       void showData(){
         cout<<real<<" + "<<img<<"i"<<endl;
       }
};

void f5(){
    Complex c[5];
    
}
