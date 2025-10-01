/* 🔹 3. Multilevel Inheritance
👉 A derived class becomes the base class for another derived class.   */

#include <iostream>
using namespace std;

class LivingBeing {
public:
    void breathe() {
        cout << "Breathing..." << endl;
    }
};

class Animal : public LivingBeing {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {   // Multilevel Inheritance
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog d;
    d.breathe();
    d.eat();
    d.bark();
    return 0;
}
