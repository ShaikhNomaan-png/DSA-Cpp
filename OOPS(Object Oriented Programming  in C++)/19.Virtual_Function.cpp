/*    3.Virtual Function
Declared in base class using virtual keyword.
Ensures correct function is called during runtime (dynamic binding).
Supports runtime polymorphism.
If not virtual → compiler uses compile-time binding.
*/
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base Class" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived Class" << endl; }
};

int main() {
    Base* b = new Derived();
    b->show();
}
