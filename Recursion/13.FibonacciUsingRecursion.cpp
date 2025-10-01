#include <iostream>
using namespace std;

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) 
        return n;  // Base cases: F(0)=0, F(1)=1
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive relation
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
