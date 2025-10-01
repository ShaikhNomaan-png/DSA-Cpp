#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> taskCount;
    
    // Count the frequency of each task
    for (char task : tasks) {
        taskCount[task]++;
    }
    
    // Find the maximum frequency
    int maxFrequency = 0;
    int maxCount = 0; // Count of tasks with max frequency
    for (const auto& [task, count] : taskCount) {
        if (count > maxFrequency) {
            maxFrequency = count;
            maxCount = 1;
        } else if (count == maxFrequency) {
            maxCount++;
        }
    }
    
    // Calculate the total time:
    // Total slots needed for the max frequency tasks
    int totalSlots = (maxFrequency - 1) * (n + 1) + maxCount;
    
    // Return the maximum of total tasks or the calculated slots
    return max(totalSlots, (int)tasks.size());
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    
    int result = leastInterval(tasks, n);
    cout << "Least interval to complete tasks: " << result << endl; // Output: 8
    
    return 0;
}
/*  To understand the output of the **Task Scheduler** problem, let's walk through the provided example step-by-step.

### Problem Recap
Given:
- **Tasks**: `["A", "A", "A", "B", "B", "B"]`
- **Cooling Time (n)**: `2`

The goal is to find the least number of time units required to complete all tasks, ensuring that the same task is not executed within `n` time units of its last execution.

### Steps to Solve the Problem

1. **Count Frequencies**:
   - Count how often each task appears:
     - `A`: 3 times
     - `B`: 3 times

2. **Determine Maximum Frequency**:
   - Both tasks have the same maximum frequency:
     - `maxFrequency = 3`
     - `maxCount = 2` (two different tasks (`A` and `B`) appear with this max frequency).

3. **Calculate Required Slots**:
   We calculate how many total slots we need to schedule the most frequent tasks, considering the required cooling period.

   - The formula for calculating the number of time slots needed for the most frequent tasks is:
     \[
     \text{totalSlots} = (maxFrequency - 1) \times (n + 1) + maxCount
     \]
   - Substitute in our values:
     \[
     \text{totalSlots} = (3 - 1) \times (2 + 1) + 2
     \]
     \[
     \text{totalSlots} = 2 \times 3 + 2 = 6 + 2 = 8
     \]

4. **Determine Total Time**:
   - The next step is to compare the calculated total slots (which is `8`) to the total number of tasks. 
   - Since `totalTasks = 6`, we take the maximum:
     \[
     \text{result} = \max(8, 6) = 8
     \]

### Understanding the Output
**Output**: `8`

This means that to complete all tasks under the given constraints of cooling time, you need a total of **8 time slots**. 

### Scheduling Example
A possible scheduling sequence with `8` time units could look like this:
1. Time 1: A
2. Time 2: B
3. Time 3: A
4. Time 4: B
5. Time 5: A
6. Time 6: Idle (waiting due to the cooling constraint after `A`)
7. Time 7: B (waiting due to cooling constraint after `B`)
8. Time 8: Idle (last `B` task can be put here)

This respects the rules that:
- You cannot have another `A` within 2 time units of the last `A`.
- You cannot have another `B` within 2 time units of the last `B`.

### Conclusion
The output indicates that you need a total of `8` time units to execute all tasks while adhering to the cooling period required for identical tasks.
*/