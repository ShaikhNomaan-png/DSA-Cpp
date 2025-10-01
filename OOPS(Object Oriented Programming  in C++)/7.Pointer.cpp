/*  this Pointer
A special pointer available inside class functions.
Refers to the current object.
Uses:
Distinguish between class variables and parameters with same name.
Returning the current object (chaining).
Passing the current object to another function.
*/
#include <iostream>
using namespace std;

class Box {
    int length;
public:
    Box(int l) { this->length = l; }
    void show() { cout << "Length: " << this->length << endl; }
};

int main() {
    Box b(20);
    b.show();
}
