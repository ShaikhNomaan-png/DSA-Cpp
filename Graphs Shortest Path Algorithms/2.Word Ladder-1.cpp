#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

// Function to generate all possible words by changing one letter
vector<string> generateNeighbors(const string& word, const unordered_set<string>& wordSet) {
    vector<string> neighbors;
    string current = word;

    for (int i = 0; i < word.length(); i++) {
        char originalChar = current[i]; // Store the original character
        for (char c = 'a'; c <= 'z'; c++) { // Try all letters from 'a' to 'z'
            if (c == originalChar) continue; // Skip the original character

            current[i] = c; // Change one letter
            if (wordSet.find(current) != wordSet.end()) { // If it's in the dictionary
                neighbors.push_back(current); // Add to the neighbors list
            }
        }
        current[i] = originalChar; // Restore the original character
    }
    return neighbors;
}

// Function to find the shortest transformation sequence length
int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0; // End word must be in list

    queue<pair<string, int>> q; // Queue of words along with the length of the transformation
    q.push({beginWord, 1}); // Start with the beginWord and depth 1

    while (!q.empty()) {
        auto [currentWord, level] = q.front();
        q.pop();

        // If we reach the end word, return the level/count
        if (currentWord == endWord) {
            return level;
        }

        // Generate all potential neighbors
        for (const string& neighbor : generateNeighbors(currentWord, wordSet)) {
            q.push({neighbor, level + 1}); // Enqueue the new word with level incremented
            wordSet.erase(neighbor); // Remove to prevent processing the same word
        }
    }

    return 0; // If there's no valid transformation
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = wordLadderLength(beginWord, endWord, wordList);
    if (result) {
        cout << "Length of shortest transformation sequence: " << result << endl;
    } else {
        cout << "No transformation sequence available from " << beginWord << " to " << endWord << endl;
    }

    return 0;
}

/*  Perfect 👍 let’s explain the **output** of the Word Ladder – I code step by step.

---

### **Input**

* `beginWord = "hit"`
* `endWord = "cog"`
* `wordList = {"hot", "dot", "dog", "lot", "log", "cog"}`

We need the **shortest transformation sequence** from `hit` to `cog` by changing **one character at a time**, where each intermediate word must be in the dictionary.

---

### **BFS Expansion (Level by Level)**

We start BFS from `"hit"` with step = 1.

---

**Step 1 (start):**
Queue = {`hit`}

* Neighbors of `"hit"` = `"hot"` (only valid dictionary word).
* Push `"hot"` with step = 2.

Queue = {`hot`}

---

**Step 2:**
Process `"hot"` → step = 2

* Neighbors = `"dot"`, `"lot"` (valid words in dict).
* Push both with step = 3.

Queue = {`dot`, `lot`}

---

**Step 3:**
Process `"dot"` → step = 3

* Neighbors = `"dog"` (valid).
* Push `"dog"` with step = 4.

Process `"lot"` → step = 3

* Neighbors = `"log"` (valid).
* Push `"log"` with step = 4.

Queue = {`dog`, `log`}

---

**Step 4:**
Process `"dog"` → step = 4

* Neighbors = `"cog"` ✅ (endWord found).
* Push `"cog"` with step = 5.

At this point, BFS stops because we found the **shortest path**.

---

### **Shortest Path Found**

`hit → hot → dot → dog → cog`

or
`hit → hot → lot → log → cog`

Both have length **5**.

---

### **Final Output**

```
Shortest transformation sequence length = 5
```

---

👉 The output is **5** because BFS guarantees the shortest path in an unweighted graph (each word transformation = 1 edge).

Would you like me to also **draw the graph structure** showing all connections (`hit-hot-dot-dog-cog` etc.) so you can visualize the path better?

*/