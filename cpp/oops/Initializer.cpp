#include <iostream>

using namespace std;


class Initializer
{
private:
    int a,b;
public:
    Initializer(/* args */):a(5),b(5){}
    ~Initializer();
};

class Product{
    private:
      int a,b,c;
      int &r;
    public:
      Product(int x,int y,int z, int *ptr):r(*ptr){
        a=x;
        b=y;
        c=z;
      }
      void show(){
        cout<<"a= "<<a<<" b= "<<b<<" c= "<<endl;
        cout<<"r= "<<r<<endl;
      }
};
int main(int argc, char const *argv[])
{
     int *ptr = (int*)malloc(4);
     *ptr =100;
     Product p1 = {10,10,10,ptr};

    return 0;
}

