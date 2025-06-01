#include <iostream>
using namespace std;

// Complex Number Class
class Complex {
    int real, img;

public:
    Complex() : real(0), img(0) {}
    Complex(int r, int i) : real(r), img(i) {}

    Complex operator+(Complex);
    Complex operator*(Complex);
    Complex operator-(Complex);
    bool operator==(Complex);

    void display() {
        cout << real << " + " << img << "i" << endl;
    }
};

Complex Complex::operator+(Complex c) {
    return Complex(real + c.real, img + c.img);
}

Complex Complex::operator*(Complex c) {
    return Complex(real * c.real - img * c.img, real * c.img + img * c.real);
}

Complex Complex::operator-(Complex c) {
    return Complex(real - c.real, img - c.img);
}

bool Complex::operator==(Complex c) {
    return (real == c.real) && (img == c.img);
}

// Time Class
class Time {
    int hr, min, sec;

public:
    Time() : hr(0), min(0), sec(0) {}
    Time(int h, int m, int s) : hr(h), min(m), sec(s) {}

    bool operator>(Time);
    Time operator+(Time);
    void operator++();

    int getHr() { return hr; }
    int getMin() { return min; }
    int getSec() { return sec; }

    void setTime(int h, int m, int s) {
        hr = h;
        min = m;
        sec = s;
    }

    void display() {
        cout << hr << " hr " << min << " min " << sec << " sec" << endl;
    }
};

bool Time::operator>(Time c) {
    int current_sec = hr * 3600 + min * 60 + sec;
    int given_sec = c.getHr() * 3600 + c.getMin() * 60 + c.getSec();
    return current_sec > given_sec;
}

Time Time::operator+(Time t) {
    int total_sec = sec + t.sec;
    int total_min = min + t.min + total_sec / 60;
    int total_hr = hr + t.hr + total_min / 60;
    return Time(total_hr, total_min % 60, total_sec % 60);
}

void Time::operator++() {
    sec++;
    if (sec >= 60) {
        sec = 0;
        min++;
    }
    if (min >= 60) {
        min = 0;
        hr++;
    }
}

// Matrix Class
class Matrix {
    int mat[3][3];

public:
    Matrix() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                mat[i][j] = 0;
    }

    void setMatrix(int m[3][3]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                mat[i][j] = m[i][j];
    }

    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    void display();
};

Matrix Matrix::operator+(Matrix &m) {
    Matrix temp;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.mat[i][j] = mat[i][j] + m.mat[i][j];
    return temp;
}

Matrix Matrix::operator-(Matrix &m) {
    Matrix temp;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.mat[i][j] = mat[i][j] - m.mat[i][j];
    return temp;
}

Matrix Matrix::operator*(Matrix &m) {
    Matrix temp;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            temp.mat[i][j] = 0;
            for (int k = 0; k < 3; k++)
                temp.mat[i][j] += mat[i][k] * m.mat[k][j];
        }
    return temp;
}

void Matrix::display() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

// Main Function
int main() {
    // Complex Number Operations
    Complex c1(3, 2), c2(1, 7);
    Complex sum = c1 + c2;
    Complex prod = c1 * c2;
    Complex diff = c1 - c2;
    bool isEqual = (c1 == c2);

    cout << "Complex Sum: ";
    sum.display();
    cout << "Complex Product: ";
    prod.display();
    cout << "Complex Difference: ";
    diff.display();
    cout << "Are c1 and c2 equal? " << (isEqual ? "Yes" : "No") << endl;

    // Time Operations
    Time t1(2, 45, 30), t2(1, 20, 50);
    Time totalTime = t1 + t2;
    cout << "\nTotal Time: ";
    totalTime.display();

    ++t1;
    cout << "After Increment: ";
    t1.display();

    cout << "Is t1 > t2? " << (t1 > t2 ? "Yes" : "No") << endl;

    // Matrix Operations
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix m1, m2;
    m1.setMatrix(mat1);
    m2.setMatrix(mat2);

    Matrix matSum = m1 + m2;
    Matrix matDiff = m1 - m2;
    Matrix matProd = m1 * m2;

    cout << "\nMatrix Sum:\n";
    matSum.display();

    cout << "\nMatrix Difference:\n";
    matDiff.display();

    cout << "\nMatrix Product:\n";
    matProd.display();

    return 0;
}
