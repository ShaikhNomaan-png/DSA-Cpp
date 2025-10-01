/* 🔹 4. Hierarchical Inheritance
👉 Multiple derived classes inherit from one base class.   */

#include <iostream>
using namespace std;

class Shape {
public:
    void draw() {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void area() {
        cout << "Area of Circle: πr²" << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() {
        cout << "Area of Rectangle: l × b" << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;

    c.draw();
    c.area();

    r.draw();
    r.area();

    return 0;
}

