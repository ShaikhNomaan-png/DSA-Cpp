/*  Sure! Let’s cover **Minimum Spanning Tree (MST)** in full detail.

---

# 🔹 What is a Minimum Spanning Tree (MST)?

Given a **connected, weighted, undirected graph**, a **spanning tree** is a subset of edges that:

1. Connects **all vertices** (no vertex is left out).
2. Forms **no cycles** (tree property).

A **Minimum Spanning Tree (MST)** is a spanning tree with **minimum total edge weight** among all possible spanning trees.

---

# 🔹 Key Properties of MST

1. **Number of edges** in MST = V - 1 (V = number of vertices).
2. **No cycles**.
3. **Minimum total weight** among all spanning trees.
4. Multiple MSTs may exist if edges have equal weights.

---

# 🔹 Algorithms to Find MST

1. **Prim’s Algorithm (G-42)**

   * Starts from a vertex and grows MST by **adding minimum weight edge connecting MST to outside**.
   * Good for **dense graphs**.
   * Time Complexity:

     * Using adjacency matrix: O(V²)
     * Using adjacency list + min-heap: O(E log V)

2. **Kruskal’s Algorithm**

   * Sort all edges by weight.
   * Pick edges **smallest to largest** while avoiding cycles (using Union-Find).
   * Good for **sparse graphs**.
   * Time Complexity: O(E log E)

---

# 🔹 Example Graph

```
Vertices = 5
Edges (Undirected, weight):
0 - 1 = 2
0 - 3 = 6
1 - 2 = 3
1 - 3 = 8
1 - 4 = 5
2 - 4 = 7
3 - 4 = 9
```

Graph diagram:

```
      2
  0 ------- 1
  | \       |
 6|  \8     |5
  |   \     |
  3-------4
       9
```

---

# 🔹 MST Using Prim’s Algorithm

### Steps:

1. Start at **vertex 0**.
2. Choose **minimum edge from 0**: 0–1 (2) → include 1.
3. Choose **minimum edge connecting MST to outside**: 1–2 (3) → include 2.
4. Choose next minimum: 1–4 (5) → include 4.
5. Next: 0–3 (6) → include 3.
6. All vertices included → MST complete.

### MST Edges:

```
0–1 (2), 1–2 (3), 1–4 (5), 0–3 (6)
```

### Total weight:

```
2 + 3 + 5 + 6 = 16
```

---

# 🔹 MST Using Kruskal’s Algorithm

### Steps:

1. Sort edges by weight:

```
0–1(2), 1–2(3), 1–4(5), 0–3(6), 2–4(7), 1–3(8), 3–4(9)
```

2. Pick smallest edge: 0–1 (2) → include
3. Pick 1–2 (3) → include
4. Pick 1–4 (5) → include
5. Pick 0–3 (6) → include
6. Remaining edges would form cycles → skip

✅ Total weight = 16 (same as Prim’s)

---

# 🔹 Key Takeaways

* MST connects **all vertices with minimum cost**.
* Both **Prim’s** and **Kruskal’s** can find MST, results may vary if multiple MSTs exist.
* Used in **network design**, **cable laying**, **road construction**, **cluster analysis**.

---

Do you want me to **write the full C++ code for both Prim’s and Kruskal’s MST algorithms** with outputs so you can compare?

*/


