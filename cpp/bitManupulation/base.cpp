#include <iostream>
using namespace std;

int getBit(int n,int pos){
    int bitmask = 1<<pos;
    return n&bitmask;
}

int setBit(int n,int pos){
    int bitmask = 1<<pos;
    return n|bitmask;
}

int clearBit(int n,int pos){
    int bitmask = ~(1<<pos);
    return n&bitmask;
}
int updateBit(int n,int pos,int newBit){
    n = clearBit(n,pos);
    int bitmask = newBit<<pos;
    return n|bitmask;
}
int clearLastBit(int n,int pos){
    bitmask (~0)<<pos;
    return n|bitmask;
}
int clearRangeBit(int n ,int left,int right){
    left = ((~0)<<1+left);
    right = (1<<right)-1;
    bitmask = a|b;
    return n&bitmask;
}
int isPower(int n){return n&(n-1);}

int main(int argc, char const *argv[])
{
    
    return 0;
}
