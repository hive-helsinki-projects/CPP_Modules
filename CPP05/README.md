# CPP_Module_05 Repetition and Exceptions
## ex00: Bureaucrat
In this exercise, you will implement a `Bureaucrat class` that represents a bureaucrat with `a name` and `a grade`. The grade must be between `1 (highest)` and `150 (lowest)`. You will also implement exception handling for invalid grades.

### Key Learning Points:

- Understand the basics of class creation in C++.
- Implement constructors, destructors, and member functions.
- Learn to use exception handling with custom exceptions.
- Practice encapsulation and data validation.

## ex01: Form
In this exercise, you will implement a `Form class` that represents a form with `a name`, `a boolean` indicating whether `it is signed`, and `grades required to sign` and `execute it`. The Bureaucrat class will be extended to sign forms.

### Key Learning Points:

- Deepen understanding of class relationships and dependencies.
- Implement more complex constructors and destructors.
- Learn to manage dynamic memory allocation.
- Practice exception handling in a multi-class environment.

## ex02: AForm and Specific Forms
In this exercise, you will create an abstract `base class AForm` and derive specific form classes from it: `ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm`. Each form will have its own specific behavior when executed.

### Key Learning Points:

- Understand abstract classes and pure virtual functions.
- Implement inheritance and polymorphism.
- Create derived classes with specific behaviors.
- Practice advanced exception handling techniques.

## ex03: Intern
In this exercise, you will implement an `Intern clas`s that can create forms based on a given form name. The Intern class will use a factory method to `create instances of the specific form classes`.

### Key Learning Points:
- **Factory Design Pattern**: Learn how to implement the factory design pattern to create objects dynamically based on input parameters.
- **Dynamic Object Creation**: Understand how to create objects at runtime using pointers and dynamic memory allocation.
- **Function Pointers**: Learn to use function pointers to store and call member functions dynamically.
- **Class Integration**: Practice integrating multiple classes (Intern, AForm, ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm) and managing their interactions.
- **Error Handling**: Implement error handling for invalid form names and ensure robust code.
- **Code Organization**: Improve code organization by separating concerns and using arrays of function pointers for cleaner and more maintainable code.
