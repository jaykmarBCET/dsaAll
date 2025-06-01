#include <iostream>
using namespace std;


class Product
{
    private:
       int p1,p2,p3;

    public:
       void show(){
        cout<<"p1="<<p1<<"p2="<<p2<<"p3="<<p3;
       }
       friend void dost();
       friend void Item::showProduct();
};

void dost(){
    
}
class Item{
   public:
      void showProduct(){
         cout<<"Hello";
      }
      
};