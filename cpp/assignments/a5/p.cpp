#include <iostream>
#include <cmath>
using namespace std;

//p1
void swapNum(int &a,int &b){
    int temp =a;
    a=b;
    b=temp;
}
//p2
int add(int,int,int=0);

int add(int a,int b,int c){
    return a+b+c;
}

//p3

double area(float r){
    return 3.14*r*r;
}
double area(double base,double heigh){
    return 0.5*base*heigh;
}

double area(int len,int width){
    return len*width;
}

//p4
int maxValue(int a,int b){
    return a>b?a:b;
}

//p5
double add(double a,double b){
    return a+b;
}

