## CPP_Module_01

###ex00 : Basics syntax and I/O

```
#include <iostream>

int main() {
   std::cout << "Hello, World!" << std::endl;
   return 0;
}
```

###ex01 : Memory Management and Arrays

###ex02 : Understanding References and Pointers

1. References vs Pointers:
- References are aliases for existing variables and cannot be null or reassigned.
- Pointers hold memory addresses and can be null or reassigned to point to different variables.

2. Usage:
- References are used when you want to ensure that the reference always points to a valid object.
- Pointers are used when you need to manage dynamic memory or when nullability and reassignment are required.
- Syntax:
  - Reference: int& ref = var;
  - Pointer: int* ptr = &var;
- Dereferencing:
  - Reference: Directly used as the variable.
  - Pointer: Use *ptr to access the value.

###ex03 : Classes and Member Functions

