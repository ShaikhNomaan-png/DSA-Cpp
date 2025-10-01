/*  Abstract Class
A class containing at least one pure virtual function (=0).
Cannot be instantiated directly.
Acts as a blueprint for derived classes.
Used to enforce implementation of certain methods.
*/

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() = 0; // pure virtual function
};

class Dog : public Animal {
public:
    void sound() { cout << "Bark" << endl; }
};

int main() {
    Dog d;
    d.sound();
}
