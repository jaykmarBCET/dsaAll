#include <cstring> 
#include <iostream>
using namespace std;

//p1

class Number{
    int size;
    int *arr;
    public:
      Number(int size){
        size = size;
        arr = new int[size];
      }
      ~Number(){
        delete []arr;
      }
      Number(Number &n){
        size = n.size;
        arr = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = n.arr[i];
        }
      }
};

//p2


class Student {
    char name[50];
    char gmail[50];
    int id;

public:
    
    Student() {
        strcpy(name, "Unknown");
        strcpy(gmail, "unknown@gmail.com");
        id = 0;
    }

   
    Student(const char *name, const char *gmail, int id) {
        strcpy(this->name, name);   // Correct way to copy C-strings
        strcpy(this->gmail, gmail);
        this->id = id;
    }

    
    void display() {
        std::cout << "Name: " << name << "\nGmail: " << gmail << "\nID: " << id << std::endl;
    }
};

//p3
class Date{
    int d, y, m;
    public:
      Date(int d,int m,int y):d(d),m(m),y(y){};
};
//p4

class Room{
    int room_no;
    char room_type[50];
    bool is_ac;
    float price;
    public:
     Room(int room_no,char &room_type,bool is_ac,float price){
        this->room_no = room_no;
        strcopy(*this.room_type,room_type);
        this->is_ac =is_ac;
        this->price = price;
     }
};

//p5
//Circle
class Complex{
    int real;
    int img;
    public;
    void showData(){
        cout<<real<<" + "<<img+"i";
    }
    void setData(int real,int img){
        this->real = real;
        this->img = img;
    }
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
};


