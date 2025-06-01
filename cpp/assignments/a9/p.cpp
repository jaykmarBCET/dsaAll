#include <iostream>
using namespace std;

//p1
class Complex{
    private:
      int r;
      int i;
    public:
      void setData(int,int);
      void showData();
      Complex add(Complex);
      Complex subtract(Complex);
      Complex multiply(Complex);
};

void Complex::setData(int real,int img){
    r=real;
    i = img;
}
void Complex::showData(){
    cout<<r<<" + "<<i<<"i";
}
Complex Complex::add(Complex c){
    Complex temp;
    temp.r = r+c.r;
    temp.i = i+c.i;
    return temp;
}
Complex Complex::multiply(Complex c){
    Complex temp;
    temp.r = r*c.r;
    temp.i = i*c.i;
    return temp;
}
Complex Complex::subtract(Complex c){
    Complex temp;
    temp.r = r-c.r;
    temp.i = i-c.i;
    return temp;
}

//p2
class Time{
    private:
     short int hh;
     short int mm;
     short int ss;
    public:
       void setTime(short int hh,short int mm,short int ss);
       void showTime();
       void normalize();
       bool isGreater(Time);
};

void Time::setTime(short int hh,short int mm,short int ss){
    this->hh=hh;
    this->mm=mm;
    this->ss = ss;
}
void Time::showTime(){
    cout<<hh<<":"<<mm<<":"<<ss;
}
void Time::normalize(){
   cout<<hh<<" : "<<mm<<" : "<<ss;
}
bool Time::isGreater(Time){
    int total = hh*60*60 + mm*60+ss;
    int giveTotal = hh*60*60+mm*60+ss;
    return total<giveTotal;
}

//p5

class Matrix{
    private:
     int mat[3][3];
    public:
      Matrix add(Matrix m);
      Matrix sub(Matrix m);
      Matrix mul(Matrix m);
      Matrix transpose();
      bool is_singular();
};

Matrix Matrix::add(Matrix m){
    Matrix temp;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp.mat[i][j] = mat[i][j]+m.mat[i][j];
        }
    }
    return temp;
}

Matrix Matrix::sub(Matrix m){
    Matrix temp;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            temp.mat[i][j] = mat[i][j] - m.mat[i][j];
        }
    }
    return temp;
}
Matrix Matrix::mul(Matrix m){
    Matrix temp;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                temp.mat[i][j] = mat[i][k]*m.mat[k][j];
            }
        }
    }
    return temp;
}

bool Matrix::is_singular() {
    int result = (
        (mat[2][2] * mat[1][1] - mat[2][1] * mat[1][2]) * mat[0][0] -
        (mat[2][2] * mat[1][0] - mat[2][0] * mat[1][2]) * mat[0][1] +
        (mat[2][1] * mat[1][0] - mat[2][0] * mat[1][1]) * mat[0][2]
    );
    return result == 0;
}
