/*   🔹 5. Hybrid Inheritance
👉 Combination of two or more types of inheritance (e.g., Multiple + Multilevel).
⚠️ Can cause Diamond Problem → resolved using virtual inheritance.    */
#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

class B : virtual public A { };   // virtual inheritance
class C : virtual public A { };

class D : public B, public C {   // Hybrid Inheritance
};

int main() {
    D obj;
    obj.display();   // No ambiguity due to virtual
    return 0;
}

