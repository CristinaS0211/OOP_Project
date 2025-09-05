This C++ project demonstrates the principles of object-oriented programming (OOP) through the simulation of a fictional dress store. It implements a comprehensive class hierarchy with both abstract and concrete classes, illustrating key OOP concepts such as inheritance, encapsulation, polymorphism, and composition.

The program revolves around a base abstract class detalii_rochii, which defines a common interface for dress objects. The Rochie class models individual dresses, managing attributes such as color, material, quantity, and sizes, and implements all constructors, destructors, and operators, including copy, assignment, arithmetic, comparison, and stream operators.

The project demonstrates “is-a” relationships through the derived class rochiecocktail, which inherits from Rochie and extends it with additional properties like occasion type, washing temperature, and dress length. It also demonstrates “has-a” relationships through the magazin class, which contains an array of Rochie objects along with store attributes such as name, address, number of employees, and their ages.

All classes implement virtual functions, file I/O operations, and operator overloading, making this project a complete application of OOP concepts in C++, combining theory with practical functionality for managing a fictional dress store
