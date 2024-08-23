# CPP_Module_01

## ex00 : Basics syntax and I/O

1. Basic Syntax:
- Understanding the structure of a C++ program.
- Example:
```
#include <iostream>

int main() {
   std::cout << "Hello, World!" << std::endl;
   return 0;
}
```

2. Input and Output:
- Using std::cout for output and std::cin for input.
- Example:
```
int age;
std::cout << "Enter your age: ";
std::cin >> age;
std::cout << "You are " << age << " years old." << std::endl;
```

## ex01 : Memory Management and Arrays

1. Dynamic Memory Allocation:
- Using `new` and `delete` to allocate and deallocate memory.
- Example:
```
int* ptr = new int;
*ptr = 10;
delete ptr;
```

2. Arrays:
- Declaring and using arrays.
- Example:
```
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; ++i) {
   std::cout << arr[i] << std::endl;
}
```

3. Dynamic Arrays:
- Using new to create dynamic arrays.
- Example:
```
int* arr = new int[5];
for (int i = 0; i < 5; ++i) {
   arr[i] = i + 1;
}
delete[] arr;
```
## ex02 : Understanding References and Pointers

1. References vs Pointers:
- References are aliases for existing variables and cannot be null or reassigned.
- Pointers hold memory addresses and can be null or reassigned to point to different variables.

2. Usage:
- References are used when you want to ensure that the reference always points to a valid object.
- Pointers are used when you need to manage dynamic memory or when nullability and reassignment are required.
- Syntax:
  - Reference: `int& ref = var;`
  - Pointer: `int* ptr = &var;`
- Dereferencing:
  - Reference: Directly used as the variable.
  - Pointer: Use `*ptr` to access the value.

## ex03 : Classes and Member Functions

1. Class Definition:
- Classes encapsulate data and functions that operate on that data.
- Example:
```
class MyClass {
public:
    int data;
    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};
```
2. Constructors:
- Special member functions used to initialize objects.
- Can be overloaded to provide multiple ways to initialize an object.
```
class MyClass {
public:
    int data;
    MyClass() : data(0) {} // Default constructor
    MyClass(int val) : data(val) {} // Parameterized constructor
};
```
3. Member Functions:
- Functions defined inside a class to operate on its data members.
- Can be const to indicate they do not modify the object.
```
class MyClass {
public:
    int data;
    void display() const {
        std::cout << "Data: " << data << std::endl;
    }
};
```

4. Encapsulation:
- Use `private` to restrict access to data members.
- Use `public` to allow access to member functions.
```
class MyClass {
private:
    int data;
public:
    void setData(int val) {
        data = val;
    }
    int getData() const {
        return data;
    }
};
```

5. Object Interaction:
- Objects can interact with each other through member functions.
- Example:
```
class MyClass {
private:
    int data;
public:
    void setData(int val) {
        data = val;
    }
    int getData() const {
        return data;
    }
    void copyData(const MyClass& other) {
        data = other.getData();
    }
};
```

## ex04 : File I/O Pperations, String Manipulation, and Basic Error Handling

1. File Handling in C++:
- Opening Files: Use 
  - `std::ifstream` to open and read from files, and 
  - `std::ofstream` to create and write to files.
- Error Handling: Check if files are successfully opened using the `.is_open()` method and handle errors appropriately.

2. String Manipulation:
- Replacing Substrings: Implement a custom function `replaceAll` to find and replace all occurrences of a substring `(s1)` with another substring `(s2)` within a given string.
- Using `std::string::find` and `std::string::append`: These methods are used to locate and modify parts of a string efficiently.

3. Basic Program Structure:
- Function Definition: Define functions to encapsulate specific tasks, such as
  - `replaceAll` for string replacement and 
  - `replaceStringInFile` for handling file processing.
- Main Function: Use the main function to handle command-line arguments and invoke other functions.

4. Command-Line Arguments:
- Usage: Accept command-line arguments to specify the input file and the strings to be replaced, making the program more flexible and reusable.
- Argument Validation: Check the number of arguments and provide usage instructions if the arguments are incorrect.

5. Output File Naming:
- Creating Output Files: Generate a new output file with a modified name (e.g., appending `.replace` to the original filename) to store the results of the string replacement.

## ex05: Harl Class Implementation

1. Class Definition: You learned how to define a class in C++ with private and public members.
2. Member Functions: Implemented various member functions `(debug, info, warning, error)` to handle different levels of logging or complaints.
3. Function Pointers: Utilized function pointers to dynamically call member functions based on a string input.
4. Maps: Used `std::map` to associate string keys with member function pointers, enabling dynamic dispatch based on input strings.
5. Encapsulation: Practiced encapsulation by keeping the member functions private and exposing a single public method (complain) to interact with the class.

## ex06: Advanced Harl Class Usage

1. Iterator Usage: Learned to use iterators to traverse the map and check for valid entries.
2. Member Function Pointer Syntax: Mastered the syntax for calling member functions via pointers stored in a map.
3. Dynamic Dispatch: Enhanced understanding of dynamic dispatch mechanisms in C++ by mapping string keys to member function pointers and invoking them conditionally.
4. Error Handling: Implemented error handling by checking if the iterator points to a valid map entry before attempting to call the member function.
5. Code Organization: Improved code organization and readability by separating class declarations in header files (Harl.hpp) and definitions in source files.