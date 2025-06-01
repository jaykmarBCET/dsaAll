
//p1
int avgOfThree(int a,int b,int c){
    return (a+b+c)/3;
}

//p2
int square(int a){return a*a;}
//p3
void swapValue(int a,int b){
    a = a+b;
    b= a-b;
    a = a-b;
}
//p4
int maxValue(int a,int b){return a>b?a:b;}
//p5
int sumOfArray(int arr[],int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum +=arr[i];
    }
    return sum;
}
