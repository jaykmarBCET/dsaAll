#include <iostream>
using namespace std;

int Binary(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    
    int index = Binary(arr, size, key);
    
    cout << index;
    
    return 0;
}
