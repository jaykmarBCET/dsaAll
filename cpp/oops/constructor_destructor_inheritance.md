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
