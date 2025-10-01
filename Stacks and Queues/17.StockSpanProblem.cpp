#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateStockSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> s; // Stack to store indices

    for (int i = 0; i < n; i++) {
        // Calculate span
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }

        if (s.empty()) {
            span[i] = i + 1; // Price is greater than all previous prices
        } else {
            span[i] = i - s.top(); // Current index - index at the top of the stack
        }
        
        s.push(i); // Push current index onto the stack
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateStockSpan(prices);
    
    cout << "Stock spans are: ";
    for (int s : span) {
        cout << s << " ";
    }
    cout << endl; // Expected output: 1 1 1 2 1 4 6
    return 0;
}

/*### L15. Stock Span Problem | Stack and Queue Playlist

The "Stock Span Problem" is a classic problem that involves calculating the span of stock prices using a stack data structure. The span of a stock's price on a given day is defined as the number of consecutive days (including the current day) for which the price has been less than or equal to the price on that day.

### Problem Statement

Given an array where each element represents the price of a stock on the corresponding day, calculate the span of the stock prices for each day. For example, if the price on day `i` is greater than the price on day `j` for all days `j < i`, the span on day `i` is `i - j`.

### Example

For the stock prices:

```
prices = [100, 80, 60, 70, 60, 75, 85]
```

The span of stock prices would be:

```
span = [1, 1, 1, 2, 1, 4, 6]
```

### Approach

1. **Use a Stack**: We will use a stack to store indices of the stock prices. The stack will help us keep track of the days for which the prices are less than or equal to the current day's price.
  
2. **Iterate Through Prices**: For each price, we will:
   - While the stack is not empty and the current price is greater than or equal to the price at the index stored at the top of the stack, we will pop from the stack.
   - If the stack becomes empty, it means the current price is higher than all previous prices, so the span is the current index + 1.
   - If the stack is not empty, the span for the current day is the difference between the current index and the index at the top of the stack.

3. **Store Results**: We will store the calculated spans in an array and return this array as the result.

### Explanation of the Code

1. **Stack Usage**: The stack stores indices of the days in order to reference the prices.

2. **Span Calculation**:
   - For each price, we pop from the stack until we find a day with a higher price. This helps us determine how many days back the current price is greater than or equal to the previous prices.
   - If the stack is empty after popping, it indicates that there’s no previous day with a higher price, so the span is the index + 1.
   - Otherwise, the span is calculated as the difference between the current index (today) and the index at the top of the stack (most recent day with a higher price).

3. **Result Compilation**: The results are stored in the `span` vector, which is returned once all prices have been processed.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of days (or prices). Each price is pushed and popped from the stack at most once.
- **Space Complexity**: O(n) in the worst case, as we could store all indices in the stack.

### Conclusion

The "Stock Span Problem" effectively demonstrates how stacks can be utilized to maintain important information about previous stock prices, allowing for efficient computation of spans. If you have further questions or need clarification on any specific part, feel free to ask!
*/