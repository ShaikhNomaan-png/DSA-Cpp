#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leaders(vector<int>& arr) {
    vector<int> result;
    int n = arr.size();
    int maxFromRight = arr[n - 1];
    result.push_back(maxFromRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            result.push_back(arr[i]);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {16, 17, 4, 7, 3, 5, 2};
    vector<int> ans = leaders(arr);
    cout << "Leaders: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

/* Execution Steps on Input {16, 17, 4, 3, 5, 2}
Initialization:

Size n = 6 (elements in arr).
maxFromRight initialized to the last element: 2.
result starts with {2} (this will hold the leaders).
Iterate from Right to Left:

i = 4 (element = 5):
5 >= 2 is true. Update maxFromRight to 5 and add 5 to result.
result becomes {2, 5}.
i = 3 (element = 3):
3 >= 5 is false. Do nothing.
i = 2 (element = 4):
4 >= 5 is false. Do nothing.
i = 1 (element = 17):
17 >= 5 is true. Update maxFromRight to 17 and add 17 to result.
result becomes {2, 5, 17}.
i = 0 (element = 16):
16 >= 17 is false. Do nothing.
Final Steps:

Reverse result: {17, 5, 2}.
Final Output
When you run the program, the output will be:

text

Leaders: 17 5 2 
Summary
The code successfully identifies and prints the leaders in the array {16, 17, 4, 3, 5, 2}. The leaders are 17, 5, and 2, as they are greater than all elements to their right.
The approach efficiently uses a single backward pass through the array, maintaining a time complexity of O(n).
*/