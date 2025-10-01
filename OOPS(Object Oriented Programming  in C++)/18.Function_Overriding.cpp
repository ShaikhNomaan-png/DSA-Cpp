/* 2.Function Overriding
Redefining a base class function in a derived class with the same signature.
Achieved at runtime (requires inheritance).
Often used with virtual functions.  */

#include <iostream>
using namespace std;

class Base {
public:
    void display() { cout << "Base Function" << endl; }
};

class Derived : public Base {
public:
    void display() { cout << "Derived Function" << endl; }
};

int main() {
    Derived d;
    d.display();
}
