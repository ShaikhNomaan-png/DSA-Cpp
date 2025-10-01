#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trapRainwaterStack(const vector<int>& height) {
    stack<int> s;
    int trapped = 0;

    for (int i = 0; i < height.size(); ++i) {
        while (!s.empty() && height[i] > height[s.top()]) {
            int top = s.top(); 
            s.pop();

            if (s.empty()) break; // No left boundary

            int distance = i - s.top() - 1; // Width of the water container
            int bounded_height = min(height[i], height[s.top()]) - height[top]; // Height of the water
            trapped += distance * bounded_height;
        }
        s.push(i); // Push current index
    }

    return trapped;
}

// Main function to demonstrate
int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trapRainwaterStack(height);
    
    cout << "Trapped Rainwater (Stack Approach): " << result << endl; // Expected output: 6

    return 0;
}

/*  Approach 2: Stack-Based Approach
In this method, a stack keeps track of the indices of the bars to determine where the water can be trapped.

Steps:

Initialization:

Create a stack to store indices of the height array.
Initialize trapped to zero.
Iterate Over Heights:

For each bar:
While the stack is not empty and the current bar height is greater than the height of the bar at the index at the top of the stack:
Pop the top of the stack to get the index of a bar that could potentially hold water.
If the stack is empty after popping, break (there’s no bar to the left).
Calculate the trapped water above the popped bar using the difference between the current height and the height at the popped index. The width will be the difference between the current index and the new index at the top of the stack.
Return the Trapped Water: After processing all bars, return the total trapped water.
*/