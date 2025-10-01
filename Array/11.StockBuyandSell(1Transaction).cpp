#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0], maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}

/*  Sure! Let's clarify the output by breaking down the example provided in the code.

### Example Prices
The input stock prices array is:
```cpp
std::vector<int> stockPrices = {7, 1, 5, 3, 6, 4};
```

### Explanation of the Process
1. **Initialization**:
   - `minPrice`: Set to a very high value (`INT_MAX`), so that any stock price will be lower than this on the first comparison.
   - `maxProfit`: Initialized to 0.

2. **Iterating through the Prices**:
   - For each stock price, we perform the following steps:

   | Day | Price | minPrice | Potential Profit (Price - minPrice) | maxProfit |
   |-----|-------|----------|--------------------------------------|-----------|
   |  0  |  7    |   7      |                0                     |     0     |
   |  1  |  1    |   1      |                0                     |     0     |
   |  2  |  5    |   1      |                4 (5 - 1)             |     4     |
   |  3  |  3    |   1      |                2 (3 - 1)             |     4     |
   |  4  |  6    |   1      |                5 (6 - 1)             |     5     |
   |  5  |  4    |   1      |                3 (4 - 1)             |     5     |

### Explanation of the Table:
- **Day**: The index in the prices array.
- **Price**: The stock price on that day.
- **minPrice**: The minimum price found so far (updated at Day 1).
- **Potential Profit**: The profit you could make by selling the stock on that day after buying it at `minPrice`.
- **maxProfit**: The maximum profit calculated up to that day.

### Detailed Iteration Walkthrough:
- **Day 0 (Price 7)**: `minPrice` is updated to 7, but no profit since there's no earlier day to sell.
- **Day 1 (Price 1)**: `minPrice` is updated to 1. Maximum profit remains 0.
- **Day 2 (Price 5)**: 
  - `minPrice` is still 1.
  - Profit = 5 - 1 = **4**. Update `maxProfit` to 4.
- **Day 3 (Price 3)**: 
  - Profit = 3 - 1 = **2**. `maxProfit` remains 4.
- **Day 4 (Price 6)**: 
  - Profit = 6 - 1 = **5**. Update `maxProfit` to 5.
- **Day 5 (Price 4)**: 
  - Profit = 4 - 1 = **3**. `maxProfit` remains 5.

### Final Output
At the end of the iteration, the `maxProfit` variable holds the value **5**, which indicates the maximum profit obtainable from a single transaction where you buy at the lowest price of **1** (Day 1) and sell at the highest price of **6** (Day 4).

### Result Displayed
The output from the program will be:
```
Maximum profit from a single transaction: 5
```

This means the best strategy is to buy the stock at a price of 1 on Day 1 and sell it at a price of 6 on Day 4, resulting in a profit of **5**.
*/