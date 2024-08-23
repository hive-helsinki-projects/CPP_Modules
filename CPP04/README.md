# CPP_Module_04 Polymorphism

## Polymorphism
1. Definition: Polymorphism allows objects of different classes to be treated as objects of a common base class. It enables a single interface to represent different underlying forms (data types).
2. Key Concepts:
- Virtual Functions: Functions in a base class that can be overridden in derived classes.
- Pure Virtual Functions: Functions with no implementation in the base class, making the class abstract.
- Dynamic Binding: The process of resolving function calls at runtime.

## Inheritance
1. Definition: Inheritance allows a class (derived class) to inherit attributes and methods from another class (base class).
2. Key Concepts:
- Base Class: The class being inherited from.
- Derived Class: The class that inherits from the base class.
- Access Specifiers: public, protected, and private control the accessibility of base class members in derived classes.
- Constructor and Destructor Calls: Constructors and destructors of base and derived classes are called in a specific order.

## ex01: Memory management

- Definition: Memory management involves the allocation and deallocation of memory during the program's execution.
- Key Concepts:
    - Dynamic Allocation: Using new to allocate memory on the heap.
    - Deallocation: Using delete to free allocated memory.
    - Deep Copy vs. Shallow Copy: Ensuring that copies of objects are independent (deep copy) rather than sharing the same memory (shallow copy).
    - Memory Leaks: Occur when allocated memory is not properly deallocated.

## ex02: Abstract class

- Definition: Abstract classes cannot be instantiated and are designed to be inherited by other classes.
- Key Concepts:
    - Pure Virtual Functions: Functions declared with = 0 in the base class, making the class abstract.
    - Interface: An abstract class that provides a common interface for derived classes.
    - Preventing Instantiation: Ensuring that base classes with pure virtual functions cannot be instantiated.
