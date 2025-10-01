/*  Shallow vs Deep Copy
Shallow Copy: Copies values directly → both objects point to the same memory (problematic with pointers).
Deep Copy: Creates a new copy of dynamically allocated memory → independent object.
Shallow copy is default in C++, deep copy must be defined manually.
*/
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char* name;
public:
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    // Deep Copy Constructor
    Person(const Person &p) {
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }
    void show() { cout << "Name: " << name << endl; }
};

int main() {
    Person p1("Rahul");
    Person p2 = p1; // deep copy
    p2.show();
}
