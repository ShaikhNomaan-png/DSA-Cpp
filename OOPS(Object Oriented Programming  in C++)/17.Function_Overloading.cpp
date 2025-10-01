/*   1.Function Overloading
Same function name with different parameters (different type/number).
Resolved at compile-time.
Example: add(int, int) and add(double, double).
*/

#include <iostream>
using namespace std;

class Print {
public:
    void show(int a) { cout << "Integer: " << a << endl; }
    void show(double b) { cout << "Double: " << b << endl; }
};

int main() {
    Print p;
    p.show(5);
    p.show(5.5);
}
