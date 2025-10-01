/*Abstraction
Abstraction = Hiding implementation details and showing only essential features.
Achieved using abstract classes or interfaces (pure virtual functions).

Definition: Hiding implementation and exposing only the essential details.
Achieved using:
Abstract classes.
Pure virtual functions.
Example: A driver only knows how to operate a car, not how the engine works.
*/
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape {
public:
    void draw() { cout << "Drawing Circle" << endl; }
};

int main() {
    Shape* s = new Circle();
    s->draw();
}
