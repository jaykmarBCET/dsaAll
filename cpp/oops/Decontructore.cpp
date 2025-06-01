#include <iostream>
using namespace std;
class Decontructore
{
    private:
      int a,b;
    public:
       Decontructore(int a,int b){
          this->a=a;
          this->b=b; 
       }
       ~Decontructore(){}
       void setData(int a,int b){
        this->a=a;
        this->b=b;
       }
       void showData(){
        cout << "a= "<<a<<" b= "<<b;
       }
       
};