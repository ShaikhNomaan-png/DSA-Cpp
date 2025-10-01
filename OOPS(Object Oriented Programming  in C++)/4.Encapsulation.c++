/* 3. Encapsulation
Notes:
Encapsulation = Wrapping data + methods into a single unit (class).
Ensures data hiding using private.
Definition: Wrapping of data and functions in a single unit (class).
Ensures data hiding → external code can’t directly modify internal variables.
Access is provided via getters and setters.
Improves security, modularity, maintainability.
*/
#include <iostream>
using namespace std;

class Bank {
private:
    int balance;
public:
    Bank(int b) { balance = b; }
    void deposit(int amt) { balance += amt; }
    int getBalance() { return balance; }
};

int main() {
    Bank acc(1000);
    acc.deposit(500);
    cout << "Balance: " << acc.getBalance() << endl;
}
