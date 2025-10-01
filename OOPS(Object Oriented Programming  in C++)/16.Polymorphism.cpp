/* Polymorphism
Definition: Ability of one function/operator to behave differently.
Definition: "Many forms" — ability of functions or objects to behave differently depending on the context.
Types:
1. Compile-time (Static Polymorphism): Function overloading, operator overloading.
2. Run-time (Dynamic Polymorphism): Virtual functions, achieved via late binding.
Benefits: Flexibility and reusability.
 */

 #include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { cout << "Animal sound" << endl; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Bark" << endl; }
};

int main() {
    Animal* a = new Dog();
    a->sound();
}
