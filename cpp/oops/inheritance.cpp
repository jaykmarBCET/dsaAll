#include <iostream>
using namespace std;


class A{
    private:
      int a;
    protected:
      void setA(int x){a=x;}
    public:
      int getA(){return a;}
};

class B:public A{
    private:
     int b;
    protected:
     void setB(int y){b=y;}
    public:
     int getB(){return b;}
     void setData(int x,int y){setA(y);setB(y);}
     void printData(){
        cout<<"a="<<getA()<<" b="<<b;
     }
};

int main(){
  B obj;
  
}