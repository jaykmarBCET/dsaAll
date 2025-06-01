#include <iostream>
#include <cmath>
using namespace std;


int gcd(int a,int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int lcm(int a,int b){
    double ans = abs(a*b)/gcd(a,b);
    return ans;
}
int lcm(int a,int b){

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
