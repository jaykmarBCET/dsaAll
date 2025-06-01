#include <iostream>


void bubbleSort(int arr[],int size){
    if(size<=1)return;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionSort(int arr[],int size){
    if(size<=1)return;
    for(int i=0; i<size; i++){
        int minPos = i;
        for(int j=i+1; j<size; j++){
            if(arr[i]>arr[j]){
                minPos = j;
                break;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}

void insertionSort(int arr[],int size){
    if(size<=1)return;
    for(int i=1; i<size; i++){
        int curr = arr[i];
        int prev = i-1;
        while (prev>=0 && arr[prev]>curr)
        {
            arr[prev+1] = arr[prev];
        }
        arr[prev+1] = curr;
        
    }
}

void mergeSort(int arr[],int si,int ei){
    if(si>=ei)return;
    int mid = si + (ei-si)/2;

    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}

void merge(int arr[],int si,int mid,int ei){
    int i = si;
    int k=0;
    int j=mid+1;
    int temp[ei-si+1];
    while(i<=mid && j<=ei){
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

    for(int i=0; i<k; i++){
        arr[si+i] = temp[i];
    }
}


void quickSort(int arr[],int low,int high){
    
}