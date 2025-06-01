#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

void printPairs(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            cout << "(" << arr[i] << ", " << arr[j] << ") ";
        }
        cout << "\n";
    }
}

int maxSubArray(int arr[], int size) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < size; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);  

        if (currSum < 0) {  
            currSum = 0;
        }
    }
    return maxSum;
}

int rainTrapWater(int arr[], int size) {
    if (size <= 1) return 0;  

    int leftMax[size], rightMax[size];

    
    leftMax[0] = arr[0];
    for (int i = 1; i < size; i++) {
        leftMax[i] = max(arr[i], leftMax[i - 1]);
    }

    
    rightMax[size - 1] = arr[size - 1];
    for (int i = size - 2; i >= 0; i--) {  
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }

    
    int maxTrap = 0;
    for (int i = 0; i < size; i++) {
        int waterLevel = min(leftMax[i], rightMax[i]); 
        int trap = waterLevel - arr[i];

        if (trap > 0) {  
            maxTrap += trap;
        }
    }

    return maxTrap;
}


int buyAndSell(int arr[],int size){
    int maxProfit=0;
    
    int buyingPrice = INT_MAX;
    for(int i=0; i<size; i++){
        if(buyingPrice>arr[i]){
            buyingPrice = arr[i];
        }
        else{
            int currProfit = arr[i] - buyingPrice;
            maxProfit = max(currProfit,maxProfit);
        }
    }
    return maxProfit;
}


  


double shortestPath(string str) {
    int x = 0, y = 0;
    for (char ch : str) {
        if (ch == 'N') y++;    // Move up
        else if (ch == 'S') y--;  // Move down
        else if (ch == 'E') x++;  // Move right
        else if (ch == 'W') x--;  // Move left
    }

    
    return sqrt(x * x + y * y);
}

char oddEven(int n){
    int result = n&1;
    return result==0?'E':'O';
}
