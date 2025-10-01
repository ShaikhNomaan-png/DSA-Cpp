/*  Inheritance in C++
📘 Notes:
Inheritance is when a class (child/derived class) acquires properties & behaviors of another class (parent/base class).
Reusability of code = main advantage.
Inheritance allows a class (child) to acquire properties/methods of another class (parent).
Types:
Single
Multiple
Multilevel
Hierarchical
Hybrid
📌 Summary Table
| Type         | Structure                                 | Example                      |
| ------------ | ----------------------------------------- | ---------------------------- |
| Single       | One base → One derived                    | `Animal → Dog`               |
| Multiple     | Multiple bases → One derived              | `Engine + Wheels → Car`      |
| Multilevel   | Chain (Base → Derived → Derived)          | `LivingBeing → Animal → Dog` |
| Hierarchical | One base → Multiple derived               | `Shape → Circle, Rectangle`  |
| Hybrid       | Combination (e.g., Multiple + Multilevel) | `Diamond Problem`            |

🔹 1. Single Inheritance
👉 One base class → One derived class.
*/
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {   // Single Inheritance
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog d;
    d.eat();   // from base class
    d.bark();  // from derived class
    return 0;
}
