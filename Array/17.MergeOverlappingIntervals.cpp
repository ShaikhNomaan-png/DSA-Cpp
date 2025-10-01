#include <iostream>
#include <vector>
#include <algorithm> // For sort and max
using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return {};
    
    // Sort intervals based on the first element
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]); // Add the first interval

    for (int i = 1; i < intervals.size(); ++i) {
        auto& last = merged.back(); // Get the last added interval
        if (intervals[i].first <= last.second) { // Check for overlap
            last.second = max(last.second, intervals[i].second); // Merge
        } else {
            merged.push_back(intervals[i]); // No overlap, add interval
        }
    }
    
    return merged;
}

int main() {
    // Fixed syntax error: added a comma between {9, 14} and {15, 18}
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 13}, {9, 14}, {15, 18}};
    auto ans = mergeIntervals(intervals);

    cout << "Merged intervals:\n";
    for (const auto& p : ans) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << "\n";

    return 0;
}
