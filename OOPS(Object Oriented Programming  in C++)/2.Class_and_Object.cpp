/*  Class & Object
Class: Blueprint/template defining attributes (variables) and methods (functions).
Object: Instance of a class (real-world representation).
Example analogy:
Class → Blueprint of a car.
Object → Actual car built from the blueprint.
*/
/* ✅ Summary (Interview-Friendly)
Class & Object → Blueprint & instance
Encapsulation → Data hiding
Abstraction → Hiding complexity
Constructor & Destructor → Lifecycle management
this Pointer → Current object reference
Copy Constructor → Copying object
Shallow vs Deep Copy → Memory handling
Inheritance → Reusability
Polymorphism → Compile-time (overloading), Run-time (overriding)
Virtual Functions → Late binding
Abstract Class → Pure virtual functions
Static → Shared data/functions    */
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << endl<< " Age: " << age << endl;
    }
};

int main() {
    Student s1;  // Object creation
    s1.name = "Nomaan Shaikh";
    s1.age = 22;
    s1.display();

    return 0;
}
