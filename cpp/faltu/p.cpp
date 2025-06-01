#include <iostream>
using namespace std;

class Stack{
    int data;
    int *next;
    public:
      Stack(int data):next(nullptr){
        this->data = data;
      }
      void push(int);
      void pop();
      void show();
};

void Stack::push(int data){
    
}
