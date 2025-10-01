#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i]; // Sentinel value

        while (!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1; // Calculate width
            maxArea = max(maxArea, height * width); // Calculate area
        }
        s.push(i); // Push current index
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout << "The area of the largest rectangle is: " << result << endl; // Expected output: 10
    return 0;
}

/* Approach
1. Initialize a Stack: This stack will hold the indices of the bars in the histogram.
2.  Iterate Through Heights: Traverse each bar in the histogram:
If the current bar's height is greater than or equal to the height of the bar at the index stored at the top of the stack, push the index onto the stack.
If the current bar's height is less than the height of the bar indexed on the top of the stack, pop the index from the stack and calculate the area:
The height of the rectangle is the height of the popped index.
The width of the rectangle is determined by the distance between the current index and the index of the new top element in the stack after popping (or the whole width if the stack is empty).
3.  Flush Remaining Bars: After iterating through all bars, there might be some remaining bars in the stack. Pop these to calculate the area.
4.  Return the Maximum Area: Keep track of the maximum area encountered during these calculations.   */