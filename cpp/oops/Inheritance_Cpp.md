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
