/*  Destructor: Special function called when object is destroyed (~ClassName).
*/
#include <iostream>
using namespace std;

class Student {
public:
    Student() {
        cout << "Constructor called" << endl;
    }
    ~Student() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Student s;
    return 0;
}
