/*  🔹 Problem: Disjoint Set / Union-Find
A Disjoint Set (also called Union-Find) is a data structure to keep track of elements partitioned into disjoint sets.

It supports two main operations efficiently:

Find(u) → Returns the representative (parent) of the set containing u.

Union(u, v) → Merges the sets containing u and v.

🔹 Optimizations

Union by Rank

Attach the smaller rank tree under the larger rank tree.

Rank = height of tree.
Prevents tall trees → faster find operations.
Union by Size
Attach the smaller size tree under the larger size tree.
Size = number of elements in the tree.
Path Compression
During find(u), make all nodes on the path point directly to the root.
Flattens the tree → extremely fast subsequent finds.
✅ With these optimizations, both find and union become almost O(1) (amortized).
🔹 Explanation
Union by Rank
Smaller tree attaches to larger tree based on rank (height).
Path compression flattens the tree.
Union by Size
Smaller tree attaches to larger tree based on size (number of nodes).
Size array updates after union.
Find checks connectivity (whether two nodes are in the same set).
✅ This code covers all three optimizations in one implementation.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1); // initially size of each set = 1
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with Path Compression
    int find(int u) {
        if(parent[u] != u)
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    // Union by Rank
    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    // Display parent array
    void printParents() {
        cout << "Parent of each node:\n";
        for(int i = 0; i < parent.size(); i++)
            cout << i << " -> " << parent[i] << endl;
    }

    // Display size of each set
    void printSizes() {
        cout << "Size of each set:\n";
        for(int i = 0; i < size.size(); i++)
            cout << i << " : " << size[i] << endl;
    }
};

int main() {
    int n = 7; // number of nodes
    DisjointSet ds(n);

    // Using Union by Rank
    cout << "Union by Rank:\n";
    ds.unionByRank(0, 1);
    ds.unionByRank(1, 2);
    ds.unionByRank(3, 4);
    ds.unionByRank(5, 6);
    ds.unionByRank(4, 5);
    ds.printParents();

    // Check connectivity
    cout << (ds.find(2) == ds.find(0) ? "2 and 0 same set\n" : "2 and 0 different set\n");
    cout << (ds.find(2) == ds.find(6) ? "2 and 6 same set\n" : "2 and 6 different set\n");

    // Using Union by Size
    cout << "\nUnion by Size:\n";
    DisjointSet ds2(n);
    ds2.unionBySize(0, 1);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(3, 4);
    ds2.unionBySize(5, 6);
    ds2.unionBySize(4, 5);
    ds2.printParents();
    ds2.printSizes();

    cout << (ds2.find(2) == ds2.find(0) ? "2 and 0 same set\n" : "2 and 0 different set\n");
    cout << (ds2.find(2) == ds2.find(6) ? "2 and 6 same set\n" : "2 and 6 different set\n");

    return 0;
}
