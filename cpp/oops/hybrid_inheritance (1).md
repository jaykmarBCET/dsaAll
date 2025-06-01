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
