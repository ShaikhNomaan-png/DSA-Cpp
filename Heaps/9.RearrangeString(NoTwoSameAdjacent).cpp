#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

string rearrangeString(const string& str) {
    // Step 1: Count frequencies of each character
    unordered_map<char, int> freqMap;
    for (char ch : str) {
        freqMap[ch]++;
    }

    // Step 2: Create a max-heap based on character frequencies
    priority_queue<pair<int, char>> maxHeap;
    for (const auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
    }
    
    string result;
    pair<int, char> prev {-1, '#'}; // Keep track of the previous character and its frequency

    // Step 3: Build the result string
    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top();
        maxHeap.pop();
        
        // Add the previous character back to the heap if it still has a frequency
        if (prev.first > 0) {
            maxHeap.push(prev);
        }

        // Append the current character to the result
        result += ch;
        prev = {count - 1, ch}; // Decrease frequency and set as the previous character
    }

    // Step 4: Check if the rearrangement is valid
    if (result.size() != str.size()) {
        return ""; // Not possible to rearrange
    }

    return result;
}

int main() {
    string input = "aaabc";
    string result = rearrangeString(input);
    
    if (result.empty()) {
        cout << "Not possible to rearrange the string." << endl;
    } else {
        cout << "Rearranged string: " << result << endl;
    }

    return 0;
}
