#include <iostream>
using namespace std;


class Complex{
    private:
     int a,b;
    public:
    void setData(int x,int y){
        a=x;
        b=y;
    }
    void showData(){
        cout<<"a= "<<a<<" b= "<<b<<endl;
    }

};

void f1(){
    Complex c1,c2;
    c1.setData(3,4);
    c1.showData();
    c1.setData(5,6);
    c1.showData();
}

int main(){
    f1();
    return 0;
}
