#include <iostream>
using namespace std;


void swapValue(int &a,int &b){
    int temp = a;
    a = b;
    b=temp;
}

int main(int argc, char const *argv[])
{
    int a=4;
    int b=5;
    swapValue(a,b);
    return 0;
}
