#include <iostream>
using namespace std;


#define OVERFLOW 1
#define INVALID_INDEX 2
class Array{
    private:
     int *ptr;
     int capacity;
     int lastIndex;
    protected:
       void doubleArray();
       void halfArray();
    public:
      Array(int);
      Array();
      void append(int);
      bool isEmpty();
      bool isFull();
      void insert(int,int);
      void edit(int,int);
      void del(int);
      int getValue(int);
      int count();
      int find(int);
      bool check(int);
      int getIndex(int);

      Array& operator=(Array &arr);
      Array(Array &);
      ~Array();
};

int Array::count(){
    return lastIndex+1;
}
void Array::doubleArray(){
    
    int *temp;
    temp = new int[capacity*2];
    for (int i = 0; i < lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    delete []ptr;
    ptr = temp;
    capacity *=2;
    
}

void Array::halfArray(){
    int *temp;
    temp = new int[capacity/2];
    for(int i=0; i<lastIndex; i++){
        temp[i] = ptr[i];
    }
    delete []ptr;
    ptr = temp;
    capacity /=2;
}

void Array::append(int data){
    if(isFull()){
        doubleArray();
    }
    ptr[lastIndex+1] = data;
    lastIndex++; 
}

void Array::insert(int idx,int data){
    if(idx<0 && idx>lastIndex+1){
        throw INVALID_INDEX;
    }
    if(isFull()){
        doubleArray();
    }
    for(int i=lastIndex; i>=idx; i--){
        ptr[i+1] = ptr[i];
    }
    ptr[idx] = data;
    lastIndex++;

}

void Array::del(int index){
    if(index<0 || index>lastIndex){
        throw INVALID_INDEX;
    }
    if(lastIndex)
    for(int i=index; i<lastIndex; i++){
        ptr[i] = ptr[i+1];
    }
    lastIndex--;
    if(capacity>1 &&count()==capacity/2){
        halfArray();
    }

}