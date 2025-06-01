#include <iostream>
using namespace std;


#define OVERFLOW 1
#define INVALID_INDEX 2
#define OUNDER_FLOW 3
class Array{
    private:
     int *ptr;
     int capacity;
     int lastIndex;
    public:
      Array(int);
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

Array::Array(int cap){
    ptr = new int[cap];
    capacity =cap;
    lastIndex =-1;
}

bool Array::isFull(){
    return lastIndex ==capacity-1;
}
bool Array::isEmpty(){
    return lastIndex==-1;
}
void Array::append(int data){
    if(isFull()){
        throw OVERFLOW;
    }
    ptr[lastIndex+1] = data;
    lastIndex++;
}
void Array::insert(int index,int data){
    if(index<0 || index>lastIndex+1){
        throw INVALID_INDEX;
    }
    if(isFull()){
        throw OVERFLOW;
    }
    for(int i=lastIndex;  i>=index; i--){
        ptr[i+1] = ptr[i];
    }
    ptr[index] =data;
    lastIndex++;
}

void Array::edit(int index,int data){
    if(index<0 || index>lastIndex){
        throw INVALID_INDEX;
    }
    ptr[index] = data;
}

void Array::del(int index){
    if(index<0 || lastIndex<index){
        throw INVALID_INDEX;
    }
    if(isEmpty()){
        throw OUNDER_FLOW;
    }
    for(int i=index;i<lastIndex; i++){
        ptr[i] = ptr[i+1];
    }
    lastIndex--;
}

int Array::getValue(int index){
    if(index<0 || index>lastIndex){
        throw INVALID_INDEX;
    }
    return ptr[index];
}

int Array::count(){
    return lastIndex+1;
}

Array::~Array(){
    delete []ptr;
   
}

int Array::find(int key){
    if(isEmpty()){
        return -1;
    }
    
    for(int i=0; i<=lastIndex; i++)
        if(ptr[i]==key)return ptr[key];
    
    return -1;
}

Array& Array::operator=(Array &arr ){
    if(ptr!=nullptr){
        delete []ptr;
    }
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    for(int i=0; i<=lastIndex; i++){
        ptr[i] = arr.ptr[i];
    }
    return *this;
}
Array::Array(Array &arr){
    if(ptr!=nullptr)delete []ptr;
    lastIndex = arr.lastIndex;
    capacity = arr.capacity;
    for(int i=0;i<arr.lastIndex; i++){
        ptr[i] = arr.ptr[i];
    }

}

bool Array::check(int key){
    if(isEmpty()){
        return false;
    }
    for(int i =0; i<=lastIndex; i++){
        if(ptr[i]==key){
            return true;
        }
    }
    return false;
}
int Array::getIndex(int key){
    if(isEmpty())return -1;
    for (int i = 0; i <= lastIndex; i++)
    {
        if(ptr[i]==key){
            return i;
        }
    }
    return -1;
    
}

