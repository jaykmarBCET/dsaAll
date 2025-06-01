#include <iostream>
using namespace std;

class Complex{
    private:
      int a,b;
    public:
      void  setData(int x,int y);
      void showData();
      Complex add(Complex c);
      
};

Complex Complex::add(Complex c){
  Complex temp;
  temp.a = a+c.a;
  temp.b = b+c.b;
  return temp;
}

void Complex::setData(int x,int y){
    a=x;
    b=y;
}
void Complex::showData(){
    cout<<"a= "<<a<<" b= "<<b<<endl;
}