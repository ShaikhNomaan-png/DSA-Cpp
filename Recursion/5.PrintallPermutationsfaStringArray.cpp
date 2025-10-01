#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Helper function to generate permutations
void permute(string &str, int l, int r) {
    // If the current position is at the end of the string
    if (l == r) {
        cout << str << endl; // Print the current permutation
    } else {
        // Iterate through each character in the string
        for (int i = l; i <= r; i++) {
            // Swap the current character with the character at position 'l'
            swap(str[l], str[i]);
            // Recur for the rest of the characters
            permute(str, l + 1, r);
            // Backtrack (swap back)
            swap(str[l], str[i]); // This step is crucial for backtracking
        }
    }
}

int main() {
    string str = "ABCd"; // Example string
    int n = str.size();
    cout << "All permutations of the string: " << endl;
    permute(str, 0, n - 1); // Call the function to generate permutations
    return 0;
}
