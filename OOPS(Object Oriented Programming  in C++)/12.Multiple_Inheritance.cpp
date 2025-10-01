// 2. Multiple Inheritance
//👉 One derived class inherits from two or more base classes.

#include <iostream>
using namespace std;

class Engine {
public:
    void showPower() {
        cout << "Engine Power: 500HP" << endl;
    }
};

class Wheels {
public:
    void showWheels() {
        cout << "Car has 4 wheels" << endl;
    }
};

class Car : public Engine, public Wheels {   // Multiple Inheritance
public:
    void showCar() {
        cout << "This is a Car" << endl;
    }
};

int main() {
    Car c;
    c.showCar();
    c.showPower();
    c.showWheels();
    return 0;
}
