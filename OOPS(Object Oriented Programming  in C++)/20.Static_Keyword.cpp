/*  Static Keyword
1. Static Data Members:
Shared among all objects of a class.
One copy exists in memory.
2. Static Member Functions:
Belong to the class, not to objects.
Can be called without creating an object.
Can access only static members.
*/

#include <iostream>
using namespace std;

class Counter {
public:
    static int count;
    Counter() { count++; }
};

int Counter::count = 0;

int main() {
    Counter a, b, c;
    cout << "Count: " << Counter::count << endl;
}
