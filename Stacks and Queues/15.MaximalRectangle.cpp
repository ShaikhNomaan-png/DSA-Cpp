#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0); // Sentinel value
    
    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int maxArea = 0;
    vector<int> heights(matrix[0].size(), 0);
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            // Update the heights for the histogram
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0; // Reset height if we encounter '0'
            }
        }
        // Calculate the area for the current row
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'1', '1', '0', '0'}
    };
    
    int result = maximalRectangle(matrix);
    cout << "The area of the largest rectangle is: " << result << endl; // Expected output: 4
    return 0;
}

/* Approach
Transform Rows into Histograms: For each row in the matrix, treat it as the base of a histogram where the height of each column increases by 1 for every consecutive 1 in the matrix above (until a 0 is encountered).

Calculate Maximal Rectangle for Each Row: Using the "Largest Rectangle in Histogram" algorithm, compute the maximal rectangle area for each transformed histogram, updating a maximum area variable as needed. */