# Classes and Objects in C++

## 📌 **Agenda**
1. Encapsulation
2. Implementation of Encapsulation
3. Class
4. Object
5. Example
6. Members
7. Instance Member Variables
8. Instance Member Functions
9. Why Class Was Introduced if Structures Already Exist?

---

## **1️⃣ Encapsulation**
- **Encapsulation** is the process of **combining properties (data) and methods (functions)** related to the same entity into a single unit.
- It helps in **data hiding** and prevents direct access to sensitive information.

### **Example of Encapsulation in Real Life:**
| Entity      | Properties (Data Members) | Methods (Functions) |
|------------|---------------------------|----------------------|
| **Person**  | age, name                 | setAge(), setName()  |
| **Employee** | id, name, salary          | createID(), evaluateSalary() |
| **Book**    | bookID, title, price       | inputBook(), updateBookPrice() |

---

## **2️⃣ How to Implement Encapsulation in C++?**
There are **two ways** to implement encapsulation:
1. **Using `struct`** → By default, members of a structure are **public**.
2. **Using `class`** → By default, members of a class are **private**.

---

## **3️⃣ Class in C++**
- A `class` is a **blueprint** for creating objects.
- It groups **variables, functions, and operators**.
- A `class` is a **description** of an object.
- It is a **way to implement encapsulation**.

### **Syntax of a Class:**
```cpp
class ClassName {
    // Variables (Data Members)
    // Functions (Member Functions)
};
```

---

## **4️⃣ Object in C++**
- An **object** is a **real-world entity**.
- An **object is an instance of a class**.
- An object has **state (data)** and **behavior (actions it can perform)**.

### **Example:**
```cpp
class Book {
public:
    int bookID;
    string title;
    float price;
    
    void inputBook() {
        cout << "Enter Book ID, Title, and Price: ";
        cin >> bookID;
        cin.ignore();
        getline(cin, title);
        cin >> price;
    }
    
    void displayBook() {
        cout << "Book ID: " << bookID << "\nTitle: " << title << "\nPrice: " << price << endl;
    }
};

int main() {
    Book b1;  // Object of class Book
    b1.inputBook();
    b1.displayBook();
    return 0;
}
```
✅ **Objects like `b1` are instances of the class `Book`.**

---

## **5️⃣ Why Was `class` Introduced if `struct` Already Exists?**
Although both `struct` and `class` allow the creation of user-defined data types, `class` was introduced to provide additional features that `struct` lacks.

### **Key Differences: Structure vs. Class in C++**
| Feature | Structure (`struct`) | Class (`class`) |
|---------|----------------|----------------|
| **Default Access Specifier** | `public` | `private` |
| **Encapsulation Support** | Limited (All members public by default) | Full support with private/protected members |
| **Member Functions** | Supported, but primarily used for grouping data | Used for full-fledged object-oriented programming (OOP) |
| **Inheritance** | Supported, but members remain public by default | Fully supports OOP principles like inheritance and polymorphism |
| **Use Cases** | Simple data grouping (like C-style struct) | Complex applications with full OOP support |

### **Why `class` is More Powerful Than `struct`?**
✔ **Encapsulation**: `class` allows data hiding (`private`, `protected` members).  
✔ **Better Code Organization**: Methods and data are kept together.  
✔ **Object-Oriented Features**: Supports **inheritance, polymorphism, abstraction**.  
✔ **Access Control**: Prevents unauthorized modifications using `private` members.  
✔ **More Suitable for Large Projects**: Provides modularity, reusability, and scalability.  

---

## **6️⃣ Summary**
- **Encapsulation** groups related data and functions together.
- **Classes** define a **blueprint** for objects.
- **Objects** are **instances of classes**.
- **Class was introduced to support full OOP features**, which `struct` lacks.
- **Use `class` when building complex applications**, while `struct` is best for simple data grouping.

🚀 **Understanding Classes & Objects is key to mastering OOP in C++!**

# Static Members in C++

## 📚 **Saurabh Shukla (MySirG) - C++ In Depth**

## 📌 **Agenda**
1. `static` Keyword
2. Static Local Variables
3. Class Variables (Static Member Variables)
4. Static Member Functions

---

## **1️⃣ `static` Keyword in C++**
- The `static` keyword can be used in **three main places** in C++:
  - **Static Local Variables** (C/C++)
  - **Static Member Variables** (C++)
  - **Static Member Functions** (C++)

---

## **2️⃣ Static Local Variables**
### 🔹 Definition
- A **static local variable** is a variable **inside a function** but retains its value across function calls.
- **Lifetime**: Until the program ends.
- **Scope**: Limited to the function.
- **Default Value**: **Zero (0)** if not initialized.

### 🔹 Example:
```cpp
#include <iostream>
using namespace std;

void func() {
    static int y = 0;  // Static local variable
    y++;
    cout << "y = " << y << endl;
}

int main() {
    func();  // Output: y = 1
    func();  // Output: y = 2
    func();  // Output: y = 3
    return 0;
}
```
✅ **The value of `y` persists between function calls.**

---

## **3️⃣ Static Member Variables (Class Variables)**
### 🔹 Definition
- A **static member variable** belongs to the **class, not an object**.
- **Only one copy exists** for all objects of the class.
- Must be **defined outside the class**.

### 🔹 Example:
```cpp
#include <iostream>
using namespace std;

class Item {
public:
    int a, b;  // Instance member variables
    static int k;  // Static member variable
};

int Item::k = 0;  // Definition of static member

int main() {
    Item i1, i2;
    i1.k = 5;
    cout << "i1.k = " << i1.k << endl;
    cout << "i2.k = " << i2.k << endl;
    return 0;
}
```
✅ **Static variable `k` is shared between all objects.**

---

## **4️⃣ How to Access Static Member Variables?**
| Access Type | Syntax |
|------------|--------|
| **Using Object** | `objectName.StaticMemberVariable` |
| **Using Class Name** | `ClassName::StaticMemberVariable` |

✅ **Example:**
```cpp
Item::k = 10;  // Accessing static member using class name
cout << Item::k;
```

---

## **5️⃣ Static Member Functions**
### 🔹 Definition
- A **static member function**:
  - Can **only access static members** of the class.
  - Is **shared among all objects**.
  - Does **not operate on a specific object**.

### 🔹 Example:
```cpp
#include <iostream>
using namespace std;

class Account {
private:
    static float roi;

public:
    static void showROI() {  // Static function
        cout << "Rate of Interest: " << roi << "%" << endl;
    }
};

float Account::roi = 7.5;  // Define static variable

int main() {
    Account::showROI();  // Calling static function using class name
    return 0;
}
```
✅ **Static function `showROI()` can be called without an object.**

---

## **6️⃣ Why Use Static Members?**
✔ **Saves Memory:** Only one copy exists for all objects.  
✔ **Shared Data:** Useful for constants and counters.  
✔ **Independent Functions:** Static functions don’t require an object.  

---

## **7️⃣ Summary**
- **Static Local Variables** retain values across function calls.
- **Static Member Variables** are shared across all objects of a class.
- **Static Member Functions** can only access static members.
- **Use static members to store class-wide information efficiently.**

🚀 **Mastering static members helps write efficient C++ programs!**

# Static Members in C++

## 📌 **What are Static Members?**
- **Static members** are shared among all objects of a class.
- **Static variables** belong to the class, not individual objects.
- **Static functions** can only access static variables.

---

## **1️⃣ Static Member Variables (Class Variables)**
### **🔹 Definition**
- Declared using the `static` keyword inside a class.
- Stored in a **single memory location**, shared among all objects.
- Must be **defined outside the class**.

### **🔹 Example**
```cpp
#include<iostream>
using namespace std;

class Item {
private:
    int a, b; // Instance member variables
    static int k; // Static member variable

public:
    void setA(int x) { a = x; }
    void setB(int y) { b = y; }
    int getA() { return a; }
    int getB() { return b; }
    
    static void setK(int z) { k = z; } // Static Member Function
    static int getK() { return k; } // Static Member Function
};

int Item::k; // Static member definition

int main() {
    Item::setK(10); // Accessing static function without object
    cout << "Static k = " << Item::getK() << endl;
    return 0;
}
```

✅ **Output:**
```
Static k = 10
```

---

## **2️⃣ Characteristics of Static Variables**
✔ **Belongs to the class, not an object.**  
✔ **Single copy exists in memory.**  
✔ **Retains value throughout the program.**  
✔ **Declared inside class but defined outside.**  

---

## **3️⃣ Static Member Functions**
### **🔹 Definition**
- Declared using `static` keyword inside a class.
- Can **only access static member variables**.
- Does **not require an object** to be called.

### **🔹 Example**
```cpp
class Test {
private:
    static int count;
public:
    static void showCount() {
        cout << "Count: " << count << endl;
    }
};

int Test::count = 5;

int main() {
    Test::showCount(); // Calling without an object
    return 0;
}
```

✅ **Output:**
```
Count: 5
```

---

## **4️⃣ Why Use Static Members?**
✔ **Saves Memory:** Only one copy exists for all objects.  
✔ **Shared Data:** Useful for constants and counters.  
✔ **Independent Functions:** Static functions don’t require an object.  

---

## **5️⃣ Summary**
- **Static variables** belong to the class, not objects.
- **Static functions** can only access static variables.
- **Use static members to store class-wide information efficiently.**

🚀 **Mastering static members helps write efficient C++ programs!**

# Call by Object & Returning Object in C++

## 📚 **Saurabh Shukla (MySirG) - C++ In Depth**

## 📌 **Agenda**
1. Introduction
2. Call by Object
3. Returning Object
4. Example: Complex Number Addition

---

## **1️⃣ Introduction**
- **Call by Object**: Passing an object as an argument to a function.
- **Returning Object**: A function returning an object after performing some operations.

---

## **2️⃣ Call by Object**
### **🔹 Definition**
- A function that **takes an object as a parameter**.
- Uses **pass-by-reference** or **pass-by-value**.
- Helps in modifying object properties inside the function.

### **🔹 Syntax**
```cpp
ReturnType FunctionName(ClassName object);
```

### **🔹 Example**
```cpp
class Complex {
public:
    int real, imag;
    void setValues(int r, int i) {
        real = r;
        imag = i;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

void showComplex(Complex c) { // Call by Object
    cout << "Complex Number: ";
    c.display();
}
```

---

## **3️⃣ Returning Object**
### **🔹 Definition**
- A function that **returns an object** after performing operations.
- Used in **operator overloading and arithmetic operations**.

### **🔹 Syntax**
```cpp
ClassName FunctionName();
```

### **🔹 Example**
```cpp
class Complex {
public:
    int real, imag;
    void setValues(int r, int i) {
        real = r;
        imag = i;
    }
    Complex add(Complex c) { // Returning Object
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
```

---

## **4️⃣ Example: Complex Number Addition**
### **🔹 Complete Program**
```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    void setValues(int r, int i) {
        real = r;
        imag = i;
    }
    Complex add(Complex c) { // Returning Object
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, result;
    c1.setValues(2, 3);
    c2.setValues(4, 5);
    
    result = c1.add(c2); // Returning object from function
    
    cout << "First Complex: "; c1.display();
    cout << "Second Complex: "; c2.display();
    cout << "Sum: "; result.display();
    
    return 0;
}
```
✅ **Output:**
```
First Complex: 2 + 3i
Second Complex: 4 + 5i
Sum: 6 + 8i
```

---

## **5️⃣ Summary**
- **Call by Object**: Pass an object to a function as an argument.
- **Returning Object**: A function returns an object after performing an operation.
- **Used in real-world applications** like **arithmetic operations, data processing, and object transformations**.

# Call by Object & Returning Object in C++

## 📚 **Saurabh Shukla (MySirG) - C++ In Depth**

## 📌 **Agenda**
1. Introduction
2. Call by Object
3. Returning Object
4. Example: Complex Number Addition
5. Explanation of Complex Number Program

---

## **1️⃣ Introduction**
- **Call by Object**: Passing an object as an argument to a function.
- **Returning Object**: A function returning an object after performing some operations.

---

## **2️⃣ Call by Object**
### **🔹 Definition**
- A function that **takes an object as a parameter**.
- Uses **pass-by-reference** or **pass-by-value**.
- Helps in modifying object properties inside the function.

### **🔹 Syntax**
```cpp
ReturnType FunctionName(ClassName object);
```

### **🔹 Example**
```cpp
class Complex {
public:
    int real, imag;
    void setValues(int r, int i) {
        real = r;
        imag = i;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

void showComplex(Complex c) { // Call by Object
    cout << "Complex Number: ";
    c.display();
}
```

---

## **3️⃣ Returning Object**
### **🔹 Definition**
- A function that **returns an object** after performing operations.
- Used in **operator overloading and arithmetic operations**.

### **🔹 Syntax**
```cpp
ClassName FunctionName();
```

### **🔹 Example**
```cpp
class Complex {
public:
    int real, imag;
    void setValues(int r, int i) {
        real = r;
        imag = i;
    }
    Complex add(Complex c) { // Returning Object
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
```

---

## **4️⃣ Example: Complex Number Addition**
### **🔹 Complete Program**
```cpp
#include<iostream>
using namespace std;
class Complex
{
    private:
        int a,b; 
    public:
        void setData(int,int);
        void showData();
        Complex add(Complex);
};

Complex Complex::add(Complex C)
{
    Complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}

void Complex::setData(int x, int y) 
{
    a = x;
    b = y;
}

void Complex::showData()
{
    cout << "a=" << a << " b=" << b << endl;
}

void f1()
{
    Complex c1, c2, c3;   
    c1.setData(3,4);  
    c1.showData();
    c2.setData(5,6);  
    c2.showData();
    c3 = c1.add(c2);
    c3.showData();
}

int main()
{
    f1();
    return 0;
}
```
✅ **Output:**
```
a=3 b=4
a=5 b=6
a=8 b=10
```

---

## **5️⃣ Explanation of Complex Number Program**
### **🔹 Breakdown of the Code**
1. **Class Definition (`Complex`)**
   - `a` and `b` are **private** data members.
   - `setData(int, int)` sets values of `a` and `b`.
   - `showData()` displays the values of `a` and `b`.
   - `add(Complex C)` takes another `Complex` object as a parameter, adds corresponding `a` and `b` values, and returns a new `Complex` object.

2. **Function `f1()`**
   - Creates three `Complex` objects: `c1`, `c2`, and `c3`.
   - Sets values of `c1` and `c2` using `setData()`.
   - Displays their values using `showData()`.
   - Calls `c1.add(c2)`, which **returns a new `Complex` object** that holds the sum.
   - Displays the sum using `c3.showData()`.

3. **Function `main()`**
   - Calls `f1()` to demonstrate the working of the program.

### **🔹 Key Concepts Demonstrated**
✔ **Call by Object**: `add(Complex C)` takes an object as an argument.  
✔ **Returning Object**: `add()` returns a new `Complex` object.  
✔ **Encapsulation**: Uses private data members and public methods.  
✔ **Modularity**: Functions like `setData()`, `showData()`, and `add()` make the program modular.

---

## **6️⃣ Summary**
- **Call by Object**: Pass an object to a function as an argument.
- **Returning Object**: A function returns an object after performing an operation.
- **Used in real-world applications** like **arithmetic operations, data processing, and object transformations**.

🚀 **Mastering these concepts helps in advanced OOP techniques in C++!**

# Constructor

## Saurabh Shukla (MySirG)

### C++ in Depth

## Agenda
1. Constructor
2. Parameterized Constructor
3. Constructor Overloading
4. Default Constructor
5. Copy Constructor
6. Shallow Copy vs Deep Copy

---

## Constructor
- A constructor is a special member of the class where the name is the same as the name of the class.
- A constructor has no return type.
- A constructor is invoked at the time of object creation (automatically).
- A constructor is an instance member.
- Usually, a constructor is defined as a public member, but it can be private as well.
- The programmer has to define a constructor, so they can write any code, but it is useful to initialize the properties of an object.

### Why do you need a constructor?
To initialize member variables of an object.

```cpp
void SetData(int x, int y) {
    a = x;
    if (ptr == NULL) {
        ptr = (int*) malloc(4);
    }
    ptr = NULL; 
    *ptr = y;
}
```

---

## Parameterized Constructor
- You can make a constructor with arguments.
- Constructor arguments are passed at the object creation.

---

## Constructor Overloading
- A programmer can provide multiple constructors in the class with different signatures.

---

## Default Constructor
- When a programmer doesn't provide an explicit constructor in the class, the compiler creates an empty body, no-argument constructor in the class.

---

## Copy Constructor
- Either the programmer has to provide a copy constructor in the class or the compiler itself provides a copy constructor.
- A copy constructor is invoked for a newly created object which is initialized with the object of the same class.
- The formal argument of the copy constructor must be a reference variable of the same class.

### Compiler Behavior:
1. When there is no explicit constructor defined in the class, the compiler defines two constructors:
   - Default constructor
   - Copy constructor
2. When there is at least one explicit constructor of any type, the compiler doesn't provide a default constructor.
3. When there is an explicit copy constructor in the class, the compiler defines none.

---
# C++ Concepts: Constructors, Destructors, and Initializers

## Shallow Copy vs Deep Copy
```cpp
className obj2 = obj1;
obj2.a = obj1.a;
ptr = (int*)malloc(4);
*ptr = *(obj.ptr);
```

---

# Explanation of Complex Number Class in C++

## Code Overview
This C++ program defines a `Complex` class to represent complex numbers. It includes multiple constructors (default, parameterized, and copy constructors), along with member functions to set and display data.

## Class Definition
```cpp
class Complex {
    private:
        int a,b;     
    public:
        Complex() {} // Default constructor
        Complex(int x) { a=x; b=0; } // Parameterized constructor (single argument)
        Complex(int x, int y) {  a=x; b=y; } // Parameterized constructor (two arguments)
        Complex(Complex &C) { a=C.a; b=C.b; } // Copy constructor
        void setData(int, int);
        void showData();
};
```

## Member Function Definitions
```cpp
void Complex::setData(int x, int y) {
    a = x;
    b = y;
}

void Complex::showData() {
    cout << "a=" << a << " b=" << b << endl;
}
```

## Function `f1()` Demonstrating Object Creation
```cpp
void f1() {
    Complex c1(3), c2(2,8), c3;
    Complex c4 = c2;   
    
    c4.showData();  
    c2.showData();
}
```

## `main()` Function
```cpp
int main() {
    f1();
    return 0;
}
```

## Expected Output
```
a=2 b=8
a=2 b=8
```

---

# Destructor

## Destructor
- A destructor is a special member of the class whose name is the same as the class name but preceded with a tilde (`~`) symbol.
- A destructor has no return type.
- A destructor takes no arguments; therefore, overloading a destructor is not possible.
- A destructor is invoked implicitly when an object is about to be destroyed.

### Example:
```cpp
class Test {
    int a;
    int *p;
public:
    ~Test() {
        delete p;
    }
};
```

---

# Initializers

## Using Initialization List to Initialize Fields
```cpp
class A {
private:
    int a, b, c;
public:
    A() : a(5), b(6), c(8) {}
    A(int x, int y, int z) : a(x), b(y), c(z) {}
};
```

## Initializing `const` Member
```cpp
class A {
private:
    const int k;
public:
    A() : k(10) {} // Correct way
};
```

## Initializing Reference Variable
```cpp
class A {
private:
    int &x; // Reference variable
public:
    A(int &k) : x(k) {}
};
```

---

# Explanation of C++ Code (Initializer List)

## Example 1: Initializing a `const` Member
```cpp
class Product {
    private:
        int a, b, c;
        const int k;
    public:
        Product(int x, int y, int z, int w) : k(w) {
            a = x;
            b = y;
            c = z;
        }
        void show() {
            cout << "a=" << a << " b=" << b << " c=" << c << endl;
            cout << "k=>" << k << endl;
        }
};
```

## Example 2: Initializing a Reference Variable
```cpp
class Product {
    private:
        int a, b, c;
        int &r;
    public:
        Product(int x, int y, int z, int *ptr) : r(*ptr) {
            a = x;
            b = y;
            c = z;
        }
        void show() {
            cout << "a=" << a << " b=" << b << " c=" << c << endl;
            cout << "r=>" << r << endl;
        }
};
```

## `main()` Function
```cpp
int main() {
    int *ptr = (int*)malloc(4);
    *ptr = 100;
    Product p1 = {10, 20, 30, ptr};
    p1.show();
    cout << endl;
    return 0;
}
```

## Expected Output
```
a=10 b=20 c=30
r=>100
```

# Operator Overloading

## Saurabh Shukla (MySirG)

### C++ in Depth

## Agenda
1. Recall `add` Method
2. Operator Overloading
3. Polymorphism
4. Operators That Cannot Be Overloaded
5. Overloading Binary Operators
6. Overloading Unary Operators

---

## Recall `add` Method
### Traditional Addition Method
```cpp
Complex Complex::add(Complex C) {
    Complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}
```
Usage:
```cpp
C3 = C1.add(C2);
```

### Using Operator Overloading
```cpp
Complex Complex::operator+(Complex C) {
    Complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}
```
Usage:
```cpp
C3 = C1 + C2;
```

---

## Operator Overloading
- When one operator symbol is overloaded with multiple operations, it is known as **operator overloading**.
- Defining an operator in a class provides a **new behavior** of that operator for specific operand types.
- Operator overloading allows operators to work with user-defined types.

### Example:
```cpp
class Count {
    private:
        int value;
    public:
        Count(int v) : value(v) {}
        Count operator+(Count c) {
            return Count(value + c.value);
        }
};
```

---

## Polymorphism and Operator Overloading
- Operator overloading is a way to implement **polymorphism**.
- Example of polymorphism:
  - `3 + 4` → `int + int`
  - `5.4 + 6.3` → `double + double`
  - `c1 + c2` → `Complex + Complex`
  - `t1 + t2` → `Time + Time`

---

## Operators That Cannot Be Overloaded
Not all operators in C++ can be overloaded. The following cannot be overloaded:
1. `sizeof()`
2. `.` (Member access operator)
3. `->` (Pointer to member operator)
4. `::*` (Pointer to member)
5. `?:` (Conditional operator)
6. `::` (Scope resolution operator)

---

## Overloading Binary Operators
- When a **binary operator** is overloaded in a class as a member function:
  - The **left operand** is the caller object.
  - The **right operand** is passed as an argument.

Example:
```cpp
C3 = C1 + C2; // Here, C1 is the caller object, and C2 is passed as an argument.
```

---

## Overloading Unary Operators
Unary operators can also be overloaded, including:
- `+` (Unary plus)
- `-` (Unary minus)
- `++` (Pre/Post Increment)
- `--` (Pre/Post Decrement)
- `!` (Logical NOT)
- `*` (Dereference operator)
- `[]` (Array subscript operator)

---

This note provides an overview of **operator overloading** in C++, including examples and restrictions.


# Explanation of Friend Functions and Operator Overloading in C++

## Code Overview
This C++ program demonstrates:
1. **Friend functions**
2. **Operator overloading** using friend functions
3. **Friend functions in multiple classes**

---

## Class Definition
### Overloading `+` and `-` Operators Using Friend Functions
```cpp
class Complex {
    private:
        int a, b;     
    public:        
        void setData(int, int);
        void showData();   
        friend Complex operator+(Complex, Complex);   
        friend Complex operator-(Complex);   
};
```
### Explanation
- **Private members:** `a` and `b` store real and imaginary parts of a complex number.
- **Member functions:**
  - `setData(int, int)` → Sets values for `a` and `b`.
  - `showData()` → Displays `a` and `b`.
- **Friend functions:**
  - `operator+` → Adds two `Complex` objects.
  - `operator-` → Negates a `Complex` object.

---

## Overloading `+` Operator
```cpp
Complex operator+(Complex X, Complex Y) {
    Complex temp;
    temp.a = X.a + Y.a;
    temp.b = X.b + Y.b;
    return temp;
}
```
### Explanation
- Takes two `Complex` objects (`X` and `Y`).
- Returns a new `Complex` object with summed values.

---

## Overloading `-` Operator
```cpp
Complex operator-(Complex X) {
    Complex temp;
    temp.a = -X.a;
    temp.b = -X.b;
    return temp;
}
```
### Explanation
- Takes one `Complex` object (`X`).
- Returns a new `Complex` object with negated values.

---

## Member Function Definitions
```cpp
void Complex::setData(int x, int y) {
    a = x;
    b = y;
}
void Complex::showData() {
    cout << "a=" << a << " b=" << b << endl;
}
```
### Explanation
- `setData(int, int)` → Assigns values to `a` and `b`.
- `showData()` → Prints the values of `a` and `b`.

---

## `main()` Function Demonstrating Friend Function Usage
```cpp
int main() {
    Complex c1, c2, c3, c4;
    c1.setData(3, 4);
    c2.setData(5, 6);
    c3 = c1 + c2; // Uses operator+ (friend function)
    c3.showData();
    c4 = -c3; // Uses operator- (friend function)
    cout << endl;
    return 0;
}
```
### Explanation
- Creates `Complex` objects `c1`, `c2`, `c3`, and `c4`.
- Sets values for `c1` and `c2`.
- Uses **operator overloading**:
  - `c3 = c1 + c2;` → Calls `operator+`.
  - `c4 = -c3;` → Calls `operator-`.

---

## Example: Friend Function for Multiple Classes
```cpp
class A {
    friend void f1();
};
class B {
    friend void f1();
};
void f1() {
    // This function is a friend to both classes.
}
```
### Explanation
- `f1()` is declared as a **friend function** in both `A` and `B`.
- It can access private members of both classes.

---

## Example: Friend Function to Modify Private Members
```cpp
class Product {
    private:
        int p1, p2, p3;
        friend void dost(Product &);
    public:
        void show() {
            cout << "p1=" << p1 << " p2=" << p2 << " p3=" << p3 << endl;
        }
};
```
### Explanation
- `dost(Product &)` is a **friend function** that can modify private members.
- `show()` displays `p1`, `p2`, and `p3`.

#### Friend Function Implementation
```cpp
void dost(Product &obj1) {
    obj1.p1 = 10; 
    obj1.p2 = 20;
    obj1.p3 = 30;
}
```
- This function modifies `p1`, `p2`, and `p3` **directly**.

#### `main()` Function
```cpp
int main() {
    Product obj;
    dost(obj);
    obj.show();
    cout << endl;
    return 0;
}
```
### Expected Output
```
p1=10 p2=20 p3=30
```

---

## Key Takeaways
1. **Friend functions** allow access to private members without being a member of the class.
2. **Operator overloading** using friend functions enables operations like `+` and `-` for user-defined types.
3. **Multiple classes can share a friend function** to manipulate private data.
4. **Friend functions do not require a caller object**, unlike member functions.

This program demonstrates **friend functions** and **operator overloading** in C++.

# Pointer Problems and Solutions

## Problem 1: Swap Two Numbers Using Pointers
```cpp
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    return 0;
}
```

**Output:**
```
Before swap: x = 10, y = 20
After swap: x = 20, y = 10
```

---

## Problem 2: Find the Largest Element in an Array Using Pointers
```cpp
#include <iostream>
using namespace std;

int findMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int arr[] = {10, 25, 5, 60, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum element: " << findMax(arr, size) << endl;
    return 0;
}
```

**Output:**
```
Maximum element: 60
```

---

## Problem 3: Reverse a String Using Pointers
```cpp
#include <iostream>
using namespace std;

void reverseString(char *str) {
    char *start = str;
    char *end = str;
    while (*end) {
        end++;
    }
    end--;  // Move to last character

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Pointer";
    cout << "Original string: " << str << endl;
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}
```

**Output:**
```
Original string: Pointer
Reversed string: retnioP
```

---

## Problem 4: Dynamic Memory Allocation for an Array
```cpp
#include <iostream>
using namespace std;

int main() {
    int *arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
```

**Example Output:**
```
Enter number of elements: 3
Enter 3 elements: 5 10 15
You entered: 5 10 15
```

---

## Problem 5: Pointer to Pointer
```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 100;
    int *ptr = &num;
    int **pptr = &ptr;

    cout << "Value of num: " << num << endl;
    cout << "Value using single pointer: " << *ptr << endl;
    cout << "Value using double pointer: " << **pptr << endl;

    return 0;
}
```

**Output:**
```
Value of num: 100
Value using single pointer: 100
Value using double pointer: 100
```

# Pointers and Dynamic Memory Allocation (DMA)

## **1. Introduction to Pointers**
- A **pointer** is a variable that stores the address of another variable.
- Declared using `*` symbol.
- Pointers contain addresses of variables of the same type as the pointer.
- The **size of a pointer** depends on the OS and computer architecture.

## **2. Object Pointer**
- A pointer of class type that stores the address of an object is an **object pointer**.

```cpp
class Complex {
    int a, b;
public:
    void setData(int x, int y) { a = x; b = y; }
    void showData() { cout << a << " " << b << endl; }
};

int main() {
    Complex c1;
    c1.setData(10, 20);
    Complex *ptr = &c1;
    ptr->showData();
    return 0;
}
```

## **3. `this` Pointer**
- `this` is a keyword and a local object pointer in every instance member function.
- It holds the address of the current object.
- `this` pointer **cannot be modified**.

### **When to use `this`?**
1. When there is a **name conflict** between instance variables and local variables.
2. When we need to represent the **current object** in instance member functions.

```cpp
class Example {
    int a;
public:
    void setA(int a) { this->a = a; }
    void showA() { cout << "Value of a: " << a << endl; }
};
```

## **4. Types of Variables in C++**
### **Based on Scope and Lifetime:**
1. **Global Variable** - Exists throughout the program.
2. **Local Variable** - Defined within a function.
3. **Instance Variable** - Defined inside a class (for objects).
4. **Static Member Variable** - Belongs to the class, not instances.
5. **Static Local Variable** - Retains value across function calls.

## **5. Dynamic Memory Allocation (DMA)**
### **Types of Memory Allocation:**
- **Static Memory Allocation (SMA):** Memory is allocated at compile time.
- **Dynamic Memory Allocation (DMA):** Memory is allocated at runtime (heap memory).

### **C vs C++ Memory Management:**
| C Functions  | C++ Equivalent |
|-------------|---------------|
| `malloc()`  | `new`         |
| `calloc()`  | `new`         |
| `free()`    | `delete`      |

### **Example of DMA in C++**
```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int;    // Allocate memory for an integer
    *p = 100;
    cout << "Value: " << *p << endl;
    delete p;            // Free the memory
    return 0;
}
```

### **DMA for Arrays**
```cpp
int *arr = new int[5];
delete[] arr;
```

## **6. Memory Management Issues**
### **Common Problems:**
1. **Memory Leak** - Allocated memory is not freed.
2. **Null Pointer Dereferencing** - Accessing memory through a NULL pointer.

```cpp
int *ptr = NULL;
*ptr = 10;  // Error: Dereferencing NULL pointer
```

## **7. Summary**
- Use **pointers** to access memory dynamically.
- `this` pointer refers to the current object.
- Use `new` and `delete` for **memory management** in C++.
- Avoid memory leaks by properly deallocating memory with `delete` or `delete[]`.

---
This note summarizes **pointers and dynamic memory allocation** concepts in C++. 🚀

# Complex Number Operations in C++

## **Introduction**
This markdown document explains the implementation of complex number operations in C++ using **operator overloading** and **dynamic memory allocation**.

---

## **1. Class Definition**
The class `Complex` represents a complex number with two private attributes:
- `a` (real part)
- `b` (imaginary part)

```cpp
class Complex
{
    private:
        int a, b;     
    public:
        void setData(int, int);
        void showData();   
        Complex operator+(Complex);   
        Complex operator-();   
};
```

### **Key Features:**
- `setData(int, int)`: Sets values for real and imaginary parts.
- `showData()`: Displays the complex number.
- `operator+`: Overloads `+` to add two complex numbers.
- `operator-`: Overloads `-` to negate a complex number.

---

## **2. Operator Overloading**
### **Addition Operator (`+`)**
```cpp
Complex Complex::operator+(Complex C)
{
    Complex temp;
    temp.a = a + C.a;
    temp.b = b + C.b;
    return temp;
}
```
**Explanation:**
- Adds the real and imaginary parts of two complex numbers.
- Returns a new `Complex` object.

### **Negation Operator (`-`)**
```cpp
Complex Complex::operator-()
{
    Complex temp;
    temp.a = -a;
    temp.b = -b;
    return temp;
}
```
**Explanation:**
- Negates both real and imaginary parts of a complex number.

---

## **3. Dynamic Memory Allocation**
```cpp
void f1()
{
    Complex *p1, *p2, *p3 = nullptr, *p4 = nullptr;
    p1 = new Complex();
    p2 = new Complex(); 
    p1->setData(3,4);  
    p2->setData(5,6);

    p3 = new Complex();
    if (p3 != nullptr)
        *p3 = *p1 + *p2;
    p3->showData();

    p4 = new Complex();
    if (p4 != nullptr)
        *p4 = -*p3;
    p4->showData();

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}
```

**Explanation:**
- `new Complex()` dynamically allocates memory.
- `*p3 = *p1 + *p2;` performs addition using overloaded `+`.
- `*p4 = -*p3;` negates the result using overloaded `-`.
- `delete` releases allocated memory to prevent memory leaks.

---

## **4. Main Function**
```cpp
int main()
{
    f1();
    cout << "Last Line";
    return 0;
}
```
**Purpose:** Calls `f1()` to demonstrate complex number operations.

---

## **5. Expected Output**
```
a = 8, b = 10
a = -8, b = -10
Last Line
```

---

## **6. Summary**
- Implemented complex number addition and negation using **operator overloading**.
- Used **dynamic memory allocation** for object management.
- Ensured **proper memory deallocation** using `delete` to avoid memory leaks.

This implementation showcases C++'s power with **object-oriented programming** and **memory management**! 🚀

# **Inheritance in C++**

## **Agenda**
1. Introduction to Inheritance
2. Implementation in C++
3. Types of Inheritance
4. Visibility Modes

---

## **Introduction to Inheritance**
Inheritance allows a new class to **reuse** properties and methods from an existing class.

Example:
- A **Car** class has `properties` and `methods`.
- A **SportsCar** class can inherit from **Car**, extending its functionality.

---

## **Implementation of Inheritance in C++**
```cpp
class BaseClass {  
   // Properties and Methods  
};  

class DerivedClass : VisibilityMode BaseClass {  
   // Additional Properties and Methods  
};  
```

---

## **Types of Inheritance**
### **1. Single Inheritance**  
A derived class inherits from a single base class.
```cpp
class A {
    // Base class
};

class B : public A {
    // Derived class
};
```

### **2. Multilevel Inheritance**  
A class is derived from another derived class.
```cpp
class A { };

class B : public A { };

class C : public B { };
```

### **3. Multiple Inheritance**  
A class inherits from multiple base classes.
```cpp
class A { };

class B { };

class C : public A, public B { };
```

### **4. Hierarchical Inheritance**  
Multiple classes inherit from the same base class.
```cpp
class A { };

class B : public A { };

class C : public A { };
```

### **5. Hybrid Inheritance**  
A combination of multiple inheritance types.
```cpp
class A { };

class B1 : public A { };

class B2 : public A { };

class C : public B1, public B2 { };
```

---

## **Visibility Modes**
Visibility modes define how members of the base class are inherited in the derived class.

| Base Class Members | `private` Inheritance | `protected` Inheritance | `public` Inheritance |
|--------------------|----------------------|------------------------|----------------------|
| `private` members | Not accessible | Not accessible | Not accessible |
| `protected` members | Private in derived class | Protected in derived class | Protected in derived class |
| `public` members | Private in derived class | Protected in derived class | Public in derived class |

### **Example**
```cpp
class A {
protected:
    int x;
public:
    int y;
};

class B : private A {  // `protected` and `public` members of A become `private` in B
};
```

---

## **Conclusion**
- Inheritance promotes **code reusability**.
- Different types of inheritance suit different **design needs**.
- Visibility modes control how data is inherited and accessed.

---

*Prepared by: MySirG (Saurabh Shukla)*

# Constructor & Destructor in Inheritance  

### Author: Saurabh Shukla (MySirG)  
### Subject: C++ in Depth  

## Agenda  
1. Constructor in Inheritance  
2. Destructor in Inheritance  

## Constructor in Inheritance  

### Purpose of Constructor  
- Initializes properties of a newly created object.  
- Constructors never inherit.  
- A child class constructor implicitly or explicitly invokes the constructor of the parent class.  

### Cases in Constructor Inheritance  

#### **Case 1: No Explicit Constructor in Parent Class**  
- If no constructor is explicitly defined in class A (parent) and class B (child), then:  
  ```cpp
  class B : public A { };
  B obj;  // Calls constructor of B, which implicitly calls constructor of A
  ```
- Order of constructor calls: **B() → A()**  
- Order of execution: **A() → B()**  

#### **Case 2: Parent Class Has a Non-Parameterized Constructor**  
- If class A explicitly defines a non-parameterized constructor and class B does not define one:  
  ```cpp
  class A { public: A() { } };
  class B : public A { };
  B obj;
  ```
- Order of constructor calls: **B() → A()**  
- Order of execution: **A() → B()**  

#### **Case 3: Parent Class Has a Parameterized Constructor**  
- If class A has a parameterized constructor but no default constructor:  
  ```cpp
  class A { public: A(int a) { } };
  class B : public A { public: B() { } };
  B obj;  // ERROR: No default constructor in A
  ```
- Since class A does not have a non-parameterized constructor, the child class must explicitly call the parent constructor.  

#### **Case 4: Parent Class Has Only a Parameterized Constructor**  
- If class A only has a parameterized constructor and B does not explicitly call it:  
  ```cpp
  class A { public: A(int a) { } };
  class B : public A { public: B() { } };
  B obj;  // ERROR: No matching constructor in A
  ```
- The child class constructor must explicitly call the parent constructor:  
  ```cpp
  class B : public A { public: B() : A(5) { } };
  B obj;  // Correct
  ```

#### **Case 5: Parent Class Has Multiple Constructors**  
- If class A has multiple constructors, including a default one:  
  ```cpp
  class A { public: A() { }, A(int a) { } };
  class B : public A { public: B(int x, int y) : A(x) { } };
  B obj(5, 4);
  ```
- The programmer can choose which constructor to invoke in the child class.  

## Destructor in Inheritance  

- Destructors never inherit.  
- There is no need to explicitly call the parent's destructor.  
- Order of destructor calls: **Child → Parent**  

```cpp
class A { public: ~A() { } };
class B : public A { public: ~B() { } };
B obj;  // Calls ~B() → ~A()
```

# Hybrid Inheritance  

### Author: Saurabh Shukla (MySirG)  
### Subject: C++ in Depth  

## Agenda  
1. Hybrid Inheritance  
2. Diamond Problem  
3. Virtual Base Class  

## Hybrid Inheritance  

Hybrid inheritance is a combination of multiple types of inheritance (single, multiple, hierarchical, or multilevel).  

### Example Structure  

```cpp
class A { public: void func1() { } };
class B1 : public A { public: void func2() { } };
class B2 : public A { public: void func3() { } };
class C : public B1, public B2 { public: void func4() { } };
```

- This creates the **Diamond Problem** due to multiple inheritance.  

## Diamond Problem  

The **Diamond Problem** occurs when a class inherits from two classes that both inherit from the same base class.  
- Leads to **ambiguity** in calling the base class methods.  
- Example:  

```cpp
class A { public: void show() { } };
class B1 : public A { };
class B2 : public A { };
class C : public B1, public B2 { };
C obj;
obj.show();  // ERROR: Ambiguous call to 'show' from class A
```

## Virtual Base Class Solution  

To resolve the Diamond Problem, we use **virtual inheritance**:  

```cpp
class A { public: void show() { } };
class B1 : virtual public A { };
class B2 : virtual public A { };
class C : public B1, public B2 { };
C obj;
obj.show();  // Works fine
```

- `virtual public A` ensures only **one instance** of A is inherited, preventing ambiguity.  

## Summary  
- **Hybrid inheritance** combines multiple types of inheritance.  
- The **Diamond Problem** arises due to multiple inheritance.  
- **Virtual Base Classes** solve this issue by ensuring a single instance of the base class exists in the hierarchy.  

# Hybrid Inheritance  

### Author: Saurabh Shukla (MySirG)  
### Subject: C++ in Depth  

## Agenda  
1. Hybrid Inheritance  
2. Diamond Problem  
3. Virtual Base Class  

## Hybrid Inheritance  

Hybrid inheritance is a combination of multiple types of inheritance (single, multiple, hierarchical, or multilevel).  

### Example Structure  

```cpp
class A { public: void func1() { } };
class B1 : public A { public: void func2() { } };
class B2 : public A { public: void func3() { } };
class C : public B1, public B2 { public: void func4() { } };
```

- This creates the **Diamond Problem** due to multiple inheritance.  

## Diamond Problem  

The **Diamond Problem** occurs when a class inherits from two classes that both inherit from the same base class.  
- Leads to **ambiguity** in calling the base class methods.  
- Example:  

```cpp
class A { public: void show() { } };
class B1 : public A { };
class B2 : public A { };
class C : public B1, public B2 { };
C obj;
obj.show();  // ERROR: Ambiguous call to 'show' from class A
```

## Virtual Base Class Solution  

To resolve the Diamond Problem, we use **virtual inheritance**:  

```cpp
class A { public: void show() { } };
class B1 : virtual public A { };
class B2 : virtual public A { };
class C : public B1, public B2 { };
C obj;
obj.show();  // Works fine
```

- `virtual public A` ensures only **one instance** of A is inherited, preventing ambiguity.  

## Summary  
- **Hybrid inheritance** combines multiple types of inheritance.  
- The **Diamond Problem** arises due to multiple inheritance.  
- **Virtual Base Classes** solve this issue by ensuring a single instance of the base class exists in the hierarchy.  
