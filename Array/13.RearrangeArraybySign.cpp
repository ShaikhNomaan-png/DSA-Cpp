#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrange(vector<int>& arr) {
    vector<int> pos, neg, result;
    for (int x : arr) {
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }
    int i = 0, j = 0;
    while (i < pos.size() && j < neg.size()) {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }
    while (i < pos.size()) result.push_back(pos[i++]);
    while (j < neg.size()) result.push_back(neg[j++]);
    return result;
}

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, 9, -9,14, -4};
    vector<int> ans = rearrange(arr);
    cout << "Rearranged Array: ";
    for (int x : ans) cout << x << " ";
    cout << endl;// positive negative repeat
    return 0;
}

/*  Example Input and Breakdown
Input:
cpp

vector<int> arr = {3, 1, -2, -5, 2, 9, -9, 14, -4};
Execution Steps:
Separation:

Positive Numbers: {3, 1, 2, 9, 14}
Negative Numbers: {-2, -5, -9, -4}
Combining:

Alternating Addition:
From pos: 3, and from neg: -2 ⇒ Result: {3, -2}
From pos: 1, and from neg: -5 ⇒ Result: {3, -2, 1, -5}
From pos: 2, and from neg: -9 ⇒ Result: {3, -2, 1, -5, 2, -9}
From pos: 9, and from neg: -4 ⇒ Result: {3, -2, 1, -5, 2, -9, 9, -4}
Now, pos has the elements {14} left, and neg is exhausted.
Adding Remaining Elements:

The remaining positive number 14 is added to the result.
Final result array: {3, -2, 1, -5, 2, -9, 9, -4, 14}
Final Output
When you run the program, the output will be:

text

Rearranged Array: 3 -2 1 -5 2 -9 9 -4 14 
Summary
The output shows the original array rearranged so that positive and negative numbers alternate as much as possible. The remaining positive numbers are added at the end since there are no corresponding negative numbers left to pair with them.
*/