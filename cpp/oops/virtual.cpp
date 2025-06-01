#include <iostream>
using namespace std;

class A{
    public:
     virtual void f1(){
        cout<<"A";
      }
};

class B: public A{
    public: 
     void f1(){
        cout<<"B";
     }
};

int main(){

}