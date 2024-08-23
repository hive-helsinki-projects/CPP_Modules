# CPP_Module_02 Ad-hoc Polymorphism, Operator Overloading & Orthodox Canonical Form

## Orthodox Canonical Form

1. Classes must be designed in the Orthodox Canonical Form

- Default constructor 
- Copy constructor 
- Copy assignment operator
- Destructor
```
class MyClass {
private:
    int* data;
public:
    // Default Constructor
    // Copy Constructor
    // Copy Assignment Operator
    // Destructor
    // Member Functions
```
2. Explanation
- Default Constructor: Initializes the object. Here, it sets the value to 0.
```
// Default Constructor
MyClass() : data(new int(0)) {
    std::cout << "Default Constructor called" << std::endl;
}
```
- Copy Constructor: Initializes a new object as a copy of an existing object. It copies the value from the other object.
```
// Copy Constructor
MyClass(const MyClass& other) : data(new int(*other.data)) {
    std::cout << "Copy Constructor called" << std::endl;
}
```
- Copy Assignment Operator: Assigns the values from one object to another existing object. It checks for self-assignment and then copies the value.
```
// Copy Assignment Operator
MyClass& operator=(const MyClass& other) {
    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &other) { // Check for self-assignment
        *data = *other.data;
    }
    return *this;
}
```
- Destructor: Cleans up resources when the object is destroyed. Here, it simply prints a message.
```
// Destructor
~MyClass() {
    std::cout << "Destructor called" << std::endl;
    delete data;
}
```
- Member Functions: getValue and setValue are example member functions to access and modify the private member value.

```
// Member Functions
int getValue() const {
    return *data;
}

void setValue(int val) {
    *data = val;
}
```
## Ad-hoc Polymorphism

- Also known as function overloading, it allows functions with the same name to operate on different types or numbers of parameters.
- Example:
```
#include <iostream>

void print(int i) {
    std::cout << "Integer: " << i << std::endl;
}

void print(double d) {
    std::cout << "Double: " << d << std::endl;
}

void print(const std::string& s) {
    std::cout << "String: " << s << std::endl;
}

int main() {
    print(10);          // Calls print(int)
    print(3.14);        // Calls print(double)
    print("Hello");     // Calls print(const std::string&)
    return 0;
}
```

## Operator Overloading

In C++ allows you to redefine the way operators work for user-defined types (such as classes). This enables you to use operators like `+, -, *, /, ==`, and others with objects of your classes, making the code more intuitive and easier to read.

1. Define the Operator Overload Function
-  Member Function: If the left operand is an object of the class.

    `return_type operator op (parameter_list);`
    - Example: `Fixed operator+(const Fixed& other) const;`

- Non-Member Function: If the left operand is not an object of the class (e.g., for stream insertion/extraction).

- `return_type operator op (type1, type2);`

    - Example: `std::ostream& operator<<(std::ostream& os, const Fixed& fixed);`

2. Common Operators to Overload
- Arithmetic Operators: `+`, `-`, `*`, `/`
- Comparison Operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Increment/Decrement Operators: `++`, `--`
- Stream Insertion/Extraction Operators: `<<`, `>>`



