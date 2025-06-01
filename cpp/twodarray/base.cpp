#include <iostream>
using namespace std;

int main(){
    int arr[][] = {{1,2,3},{4,5,6},{7,8,9}};
    int size = sizeof(arr)/sizeof(arr[0]);
    int col = sizeof(arr[0])/sizeof(arr[0][0]);
    int row =0;
    int key = 7;
    while(row<size && col>=0){
        if(key==arr[row][col]){
            cout << row<<", "<<col<<endl;
            break;
        }
        else if(arr[row][col]<key){
            row++;
        }else{
            col--;
        }
    }
    return 0;
}

