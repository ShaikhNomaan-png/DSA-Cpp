#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Convert k to 0-based index
        k--;

        // Precompute factorials up to n - 1
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        // Create a list of numbers to get permutations from
        vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        string permutation = "";

        // Build the k-th permutation
        for (int i = 0; i < n; ++i) {
            // Determine the index of the number to add to the permutation
            int index = k / factorial[n - 1 - i];
            permutation += to_string(numbers[index]); // Append the number to the permutation
            numbers.erase(numbers.begin() + index); // Remove used number

            // Update k for the next iteration
            k %= factorial[n - 1 - i];
        }

        return permutation;
    }

    void generatePermutations(int n) {
        vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        sort(numbers.begin(), numbers.end()); // Ensure the numbers are in ascending order

        cout << "The permutations of [";
        for (int i = 1; i <= n; ++i) {
            cout << i;
            if (i < n) cout << ", ";
        }
        cout << "] in sorted order are:" << endl;

        int count = 0; // Counter for the number of permutations
        do {
            count++; // Increment the count for each permutation
            cout << count << ": "; // Print the permutation number
            for (int i = 0; i < n; ++i) {
                cout << numbers[i];
            }
            cout << endl;
        } while (next_permutation(numbers.begin(), numbers.end())); // Generate all permutations

        cout << "Total number of permutations: " << count << endl << endl; // Print the count
    }
};

int main() {
    Solution solution;
    int n = 4; // Example input
    int k = 10; // Example input

    // Generate and display all permutations
    solution.generatePermutations(n);

    // Get the k-th permutation
    string result = solution.getPermutation(n, k);
    
    cout << k << "-th permutation is: " << result << " ← " << k << "th permutation" << endl;
    
    return 0;
}


/*  Example
For n = 4 and k = 9:

The permutations of [1, 2, 3, 4] in sorted order are:
1234
1243
1324
1342
1423
1432
2134
2143
2314 ← 9th permutation
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321
Expected Output
For the example inputs provided, the output will be:

text

The 9-th permutation of numbers from 1 to 4 is: 2314
This process efficiently calculates the k-th permutation without generating all permutations, yielding better performance for larger n. If you have any further questions, feel free to ask!

Example
For n = 4 and k = 9:

The permutations of [1, 2, 3, 4] in sorted order are:
1234
1243
1324
1342
1423
1432
2134
2143
2314 ← 9th permutation
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321
Expected Output
For the example inputs provided, the output will be:

text

The 9-th permutation of numbers from 1 to 4 is: 2314
This process efficiently calculates the k-th permutation without generating all permutations, yielding better performance for larger n. If you have any further questions, feel free to ask!
*/