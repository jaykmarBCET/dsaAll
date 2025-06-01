#include <iostream>
using namespace std;


//p1,p2

int gcd(int a,int b){
    while(b!=0){
        int temp = b;
        b=a%b;
        a = temp;
    }
    return b;
}

class Fraction{
    private:
      long numerator,denominator;
    public:
      Fraction():numerator(0),denominator(1){}
      Fraction(long n,long d):numerator(n),denominator(d){
        if(d==0){
            cout<<"Error: Denominator can not be zero"<<endl;
            denominator=1;
        }else{
            numerator = n;
            denominator = d;
        }
      }

      
      Fraction operator+(Fraction f);
      void display(){
        cout<<numerator <<"/" <<denominator <<endl;
      }
};

Fraction Fraction::operator+(Fraction f){
    int num = numerator * f.denominator+f.numerator*denominator;
    int den = denominator*f.denominator;
    int common = gcd(num,den);
    return Fraction(num/common,den/common);

}

//p3,p4
class Distance{
    int km,m,cm;
    public:
      void display(){
        cout<<km<<"km : "<<m<<"m : "<<cm<<" cm"<<endl;
      }
      Distance operator+(Distance &);
      Distance():km(0),m(0),cm(0){}
      Distance(int km,int m,int cm){
        this->km = km;
        this->m = m;
        this->cm = cm;
      }
      void operator++(){
        cm = cm+1;
      }
      void operator--(){
        cm = cm-1;
      }
      int getM(){
        return m;
      }
      int getKm(){
        return km;
      }
      int getCm(){
        return cm;
      }
      void setM(int m){
        this->m= m;
      }
      void setKm(int km){
        this->km= km;
      }
      void setCm(int cm){
        this->cm= cm;
      }
};

Distance Distance::operator+(Distance &d){
    Distance temp;
    temp.setCm(cm+d.getCm());
    temp.setKm(km+d.getKm());
    temp.setCm(m+d.getM());
    return temp;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

//p5

class Array{
    int *ptr;
    int size;
    public:
    Array(int size){
        this->size = size;
         ptr = new int[size];
    }
    ~Array(){
        delete ptr;
    }
    int subscript(int index){
        return ptr[index];
    }

};
