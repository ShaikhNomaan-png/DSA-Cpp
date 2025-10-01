#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);

    // Build graph
    for (auto &pr : prerequisites) {
        int u = pr[1], v = pr[0]; // b → a
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return count == numCourses; // true if all courses can be finished
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}}; // 0→1→2→3

    if (canFinish(numCourses, prerequisites))
        cout << "All courses can be finished" << endl;
    else
        cout << "Cannot finish all courses (cycle exists)" << endl;

    return 0;
}

/*  Sure! Let’s explain the **output of the Course Schedule I problem**.

---

## 🔹 Problem Recap

* Courses: `0` to `3` (`numCourses = 4`)

* Prerequisites: `[[1,0],[2,1],[3,2]]` → meaning:

  * To take course `1`, you must first take `0`
  * To take course `2`, you must first take `1`
  * To take course `3`, you must first take `2`

* **Goal:** Check if all courses can be finished.

---

## 🔹 Graph Representation

* Nodes: `0,1,2,3`
* Directed edges (prerequisites):

```
0 → 1 → 2 → 3
```

* This is a **linear chain**, no cycles.

---

## 🔹 BFS (Topological Sort) Step-by-Step

1. **Compute in-degree of all nodes**:

| Node | In-degree |
| ---- | --------- |
| 0    | 0         |
| 1    | 1         |
| 2    | 1         |
| 3    | 1         |

2. **Initialize queue** with nodes having in-degree `0`: `[0]`

3. **Process queue**:

   * Pop `0` → count = 1 → reduce in-degree of `1` → in-degree of `1` becomes 0 → push `1`
   * Pop `1` → count = 2 → reduce in-degree of `2` → in-degree of `2` becomes 0 → push `2`
   * Pop `2` → count = 3 → reduce in-degree of `3` → in-degree of `3` becomes 0 → push `3`
   * Pop `3` → count = 4 → queue empty

4. **Check processed nodes**: `count = 4` = `numCourses` → all courses can be finished ✅

---

## 🔹 Output

```
All courses can be finished
```

---

## 🔹 Why the Output is Correct

* The graph has **no cycles**
* BFS / topological sort successfully processes **all nodes**
* A valid course order exists: `0 → 1 → 2 → 3`

---

### 🔹 Example with Cycle

Prerequisites: `[[1,0],[0,1]]`

* Graph: `0 → 1 → 0`
* BFS queue initially `[0]`
* Only `0` processed → `count = 1 < numCourses = 2` → cycle exists
* Output:

```
Cannot finish all courses (cycle exists)
```

✅ Shows why cycle prevents finishing all courses.

---

This is exactly how the **BFS-based topological sort** determines if all courses can be finished.

If you want, I can also explain the **DFS-based solution with recursion stack** in short for Course Schedule I, which is commonly asked in interviews.

Do you want me to do that?

*/