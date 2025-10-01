/*  Access Specifier
Defines visibility and accessibility of class members.
1.Public: Accessible from anywhere.
2.Private: Accessible only within the class.
3.Protected: Accessible within class and derived classes.
*/
#include <iostream>
using namespace std;

class Demo {
private:
    int x = 10; // private
protected:
    int y = 20; // protected
public:
    int z = 30; // public
    void show() {
        cout << "Private: " << x << ", Protected: " << y << ", Public: " << z << endl;
    }
};

int main() {
    Demo d;
    d.show();
    cout << "Public: " << d.z << endl;
}
