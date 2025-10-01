#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to generate permutations
void permute(string str, string current, vector<bool> &used) {
    // If the current permutation length equals the original string length
    if (current.length() == str.length()) {
        cout << current << endl; // Print the valid permutation
        return;
    }

    // Iterate through each character in the string
    for (int i = 0; i < str.size(); i++) {
        if (!used[i]) { // If the character has not been used
            // Mark the character as used
            used[i] = true; 
            // Recur with the current character added to the permutation
            permute(str, current + str[i], used);
            // Backtrack, mark the character as unused again
            used[i] = false; 
        }
    }
}

int main() {
    string str = "ABC"; // Example string
    vector<bool> used(str.length(), false); // Track used characters
    cout << "All permutations of the string: " << endl;
    permute(str, "", used); // Call the function to generate permutations
    return 0;
}
