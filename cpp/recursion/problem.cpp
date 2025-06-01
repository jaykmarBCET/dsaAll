#include <iostream>
using namespace std;


void printDecreasingOrder(int n){
    if(n==0)return;
    cout << n<<" , ";
    i++;
    printDecreasingOrder(n-1);
    return;
}
void printIncreasingOrder(int n){
    if(n==0)return;
    printIncreasingOrder(n-1);
    cout<<n<<" , ";
}

int findFactorialOfANumber(int n){
    if(n==0)return 1;
    int fn = n*printFactorialOfANumber(n-1);
    return fn;
}
int sumOfNthNaturalNumber(int n){
    if(n==0)return 0;
    int sum = n+sumOfNthNaturalNumber(n-1);
    return sum;
}

bool isAscendingOrderOfArray(int arr[],int size,int idx){
    if(size<=idx)return true;
    if(arr[idx]>arr[idx+1]){
        return false;
    }
    idx = idx+1;
    return isAscendingOrderOfArray(arr,size,idx);
}
bool isDescendingOrderOfArray(int arr[],int size,int idx){
    if(size<=idx)return true;
    if(arr[idx]<arr[idx+1]){
        return false;
    }
    idx = idx+1;
    return isDescendingOrderOfArray(arr,size,idx);
}
bool isSorting(int arr[]){
    int size = sizeof(arr)/(sizeof(arr[0]));
    return isAscendingOrderOfArray(arr,size,0)|isDescendingOrderOfArray(arr,size,0);
}

int firstOcc(int arr[],int key,int i,int size){
    if(i>=size)return -1;
    if(arr[i]==key)return i;
    return firstOcc(arr,key,i++,size);
}
int lastOcc(int arr[],int key,int i){
    if(i==0)return -1;
    if(arr[i]==key)return i;
    return lastOcc(arr,key,i++);
}

int power(int x,int n){
    if(n==0)return 1;
    int half = power(x,n/2);
    int full = half*half;
    if(n%2!=0)full = full*x;
    return full;
}
int tilingProblem(int n){
    if(n==0 || n==1)return 1;
    return tilingProblem(n-1)+tilingProblem(n-2);
}
