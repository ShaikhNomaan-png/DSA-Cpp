#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // Required for std::reverse

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;

    for (int asteroid : asteroids) {
        // Handle collisions
        bool destroyed = false;

        while (asteroid < 0 && !s.empty() && s.top() > 0) {
            if (s.top() < -asteroid) {
                // Right asteroid destroyed, continue checking
                s.pop();
                continue;
            } else if (s.top() == -asteroid) {
                // Both destroy each other
                s.pop();
            }
            destroyed = true; // Collision occurred
            break; // Exit the loop
        }

        if (!destroyed) {
            s.push(asteroid); // If not destroyed, push the asteroid
        }
    }

    // Prepare result
    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    // Reverse to restore order
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> result = asteroidCollision(asteroids);

    cout << "Asteroids after collision: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl; // Expected output: 4 17

    return 0;
}
