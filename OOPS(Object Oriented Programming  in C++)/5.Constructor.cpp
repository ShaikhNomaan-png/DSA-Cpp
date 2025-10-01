/*   5. Constructors & Destructors
Notes:
Constructor: Special function called when object is created.
Destructor: Special function called when object is destroyed (~ClassName).

**Constructor used to create a new object as a copy of an existing object.
Syntax: ClassName (const ClassName &obj)
Called:
When an object is initialized from another.
When passed/returned by value.
*/
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    Student(string n) { name = n; } // parameterized constructor
};

int main() {
    Student s("Amit");
    cout << "Student: " << s.name << endl;
}
