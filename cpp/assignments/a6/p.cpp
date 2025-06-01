#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


//p1
void sort(int arr[],int si,int ei){
    if(si>=ei)return;
    int mid = si + (ei-si)/2;

    sort(arr,si,mid);
    sort(arr,mid+1,ei);

    merge(arr,si,mid,ei);
    return;
}
void merge(int arr[],int si,int mid,int ei){
    int i =si;
    int j = mid+1;
    int k=0;
    int temp[ ei - si+1];
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=ei){
        temp[k++] = arr[j++];
    }
    for(int k=0; k<temp.length; k++){
        arr[k+si] = temp[k];
    }
    return;
}

void sort(int arr[],int size,bool isAsc){

    sort(arr,0,size);
    if(isAsc){
        return;
    }else{
        int left=0;
        int right = size-1;
        while(left<right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    return;
    
}
//p2
void sort(string arr[],int si,int ei){
    if(si>=ei)return;

    int mid = si+ (ei-si)/2;
    sort(arr,si,mid);
    sort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}
void merge(string arr[],int si,int mid,int ei){
    int i=si;
    int j = mid+1;
    int k=0;
    int temp[ei-si+1];
    while(i<mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=ei){
        temp[k++] = arr[j++];
    }
}

void sort(string arr[],int size,bool isAsc){

    sort(arr,0,size);
    if(isAsc){
        return;
    }else{
        int left=0;
        int right = size-1;
        while(left<right){
            string temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    return;
    
}

//p3 

void rotateArray(vector<int>& arr,int n,int direction=-1){
    int size = arr.size();
    n = n%size;
    if(direction==-1){
        rotate(arr.begin(),arr.begin()+n,arr.end());
    }else{
        rotate(arr.rbegin(),arr.rebegin()+n,arr.rend());
    }
}

// p3

int gcd(int a,int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
int lcm(int a,int b){
    int gc = gcd(a,b);
    int mod = (int) abs((double)a*b);
    return mod/gc;
}

int lcm(int a,int b,int c){
     int result = lcm(lcm(a,b),c);
     return result;
}

//p5
//prime factor of given number num=36

