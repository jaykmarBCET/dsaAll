#include <iostream>
#include <string>
using namespace std;

//p1
int hcf(int a,int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return;
}
//p2
int volume(double length,int width,int height){
    double volume = length*width*height;
    return int(volume);
}
int valume(double r,int h){
    return (int) 3.14*r>r*h;
}
int volume(double r){
    double volume = (4.0/3.0)*3.14*pow(r,2);
    return volume;
}
//p3
void subString(string str,int s,int e=-1){
    if(e==-1){
        e = str.length();
    }

    cout<<str.substr(s,e);
}
//4
void swapArray(int arr1[],int  arr2[]){
    int len1 = sizeof(arr1)/(sizeof(arr1[0]));
    int temp[len1];
    for(int i=0; i<len1; i++){
        temp[i] = arr1[i];
    }
    for(int i=0; i<len1; i++){
        arr1[i] = arr2[i];
    }
    for(int i=0; i<len1; i++){
        arr2[i] = temp[i];
    }
}

//5
// already solved it
