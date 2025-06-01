#include <iostream>
#include <cmath>
using namespace std;


bool isPrime(int n){
    if(n<=1)return false;
    for (int i = 2; i < n; i++)
    {
       if(n%i==0){
        return false;
       }
    }
    return true;
}
//p1
void printPrime(int a,int b){
    for(int i=a; i<=b; i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }
}
//p2
int hightValueOfDigit(int n){
    int maximum = INT_MIN;
    while(n!=0){
        int digit = n%10;
        if(maximum<digit){
            maximum = digit;
        }
    }
    return maximum;
}
//p3
int raisePower(int x,int y){
    return pow(x,y);
}
//p4
int fact(int n){
    if(n==0 ||n==1)return 1;
    return n * fact(n-1);
}

int ncr(int n,int r){
    int nthFact = fact(n);
    int n_r = fact(n-r);
    int rthFact = fact(r);
    return nthFact/(n_r*rthFact);
}

void printPascalTriangle(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<ncr(i,j)<<" ";
        }
        cout<<endl;
    }
}
//p5

bool isPerfectSquare(int num){
    int sqrtNum = sqrt(num);
    return (sqrtNum*sqrtNum==num);
}

bool isFibonacci(int n){
    if(n<0)return false;
    return isPerfectSquare(5*n*n+4)|| isPerfectSquare(5*n*n-4);
}