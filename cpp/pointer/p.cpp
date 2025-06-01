#include <iostream>
using namespace std;


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}

int findMax(int *arr,int size){
    int max = *arr;
    for(int i=1; i<size; i++){
        if(*(arr+i)>max){
            max = *(arr+i);
        }
    }
    return max;
}

int main(){
    int a=5,b=6;
    swap(&a,&b);
}