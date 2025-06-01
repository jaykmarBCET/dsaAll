#include <iostream>
using namespace std;

class Item{
    public:
     int a,b; // instance member variable | Non-static member variables
     static int k; // static member variable | class variable

};

int Item::k; // if we want to access static variable 
// agar ham class ka multiple object banate hai tab bhi static variable ek hi raheta hai



int main(){

}