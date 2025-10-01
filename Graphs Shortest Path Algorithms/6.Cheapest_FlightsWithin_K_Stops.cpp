/* 0 --100--> 1 --100--> 2 --100--> 3
    \                              
     \--------500----------------->

 Direct path: 0 → 3 = cost 500 (0 stops).

Path with 1 stop: 0 → 1 → 2 is not valid (2 stops).

Cheapest valid = 0 → 1 → 3 doesn’t exist.

✅ Answer = 500 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Flight {
    int city, cost, stops;
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    // Build adjacency list
    vector<vector<pair<int,int>>> adj(n);
    for (auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]}); // {to, price}
    }

    // Min-heap: {cost, city, stops}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0});

    // Distance array to track min cost with stops
    vector<vector<int>> dist(n, vector<int>(K+2, INT_MAX));
    dist[src][0] = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top[0], city = top[1], stops = top[2];

        if (city == dst) return cost;  // reached destination

        if (stops > K) continue; // can't take more than K stops

        for (auto &[next, price] : adj[city]) {
            int newCost = cost + price;
            if (newCost < dist[next][stops+1]) {
                dist[next][stops+1] = newCost;
                pq.push({newCost, next, stops+1});
            }
        }
    }
    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,3,100}, {0,3,500}
    };
    int src = 0, dst = 3, K = 1;

    int ans = findCheapestPrice(n, flights, src, dst, K);
    cout << "Cheapest Price = " << ans << endl;
    return 0;
}

/*  Alright 👍 let’s carefully **explain the output** of **Cheapest Flights Within K Stops** step by step.

---

## 🔹 Input Recap

```
n = 4
flights = [[0,1,100],[1,2,100],[2,3,100],[0,3,500]]
src = 0, dst = 3, K = 1
```

Graph representation:

```
0 --100--> 1 --100--> 2 --100--> 3
 \                                
  \--------500-------------------> 3
```

* Start city = `0`
* End city = `3`
* Allowed stops = **1**

---

## 🔹 Possible Paths

### Path 1: Direct Route

```
0 → 3
Cost = 500
Stops = 0 (✅ allowed since K = 1)
```

---

### Path 2: Via City 1

```
0 → 1 → 2 → 3
Cost = 100 + 100 + 100 = 300
Stops = 2 (❌ not allowed, because K = 1)
```

---

### Path 3: 0 → 1 → 3 ?

* This edge does **not exist** in the flights list ❌.

---

## 🔹 Cheapest Valid Path

* Path 1 works → cost = **500**.
* Path 2 is cheaper (300), but requires 2 stops, which is **more than K=1**, so invalid.

✅ Therefore, the **minimum valid cost** is **500**.

---

## 🔹 Program Output

```
Cheapest Price = 500
```

---

⚡ In short:
Even though a cheaper route exists (`0 → 1 → 2 → 3` with cost 300), it is not allowed because it has **2 stops**, but we are restricted to **at most 1 stop**. Hence, the algorithm correctly outputs **500**.

---

Do you want me to also run the **same example with K = 2** and explain how the output changes to **300**?

*/
