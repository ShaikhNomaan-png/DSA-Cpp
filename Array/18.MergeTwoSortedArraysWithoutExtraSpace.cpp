// merge_no_extra_space.cpp
#include <iostream>
#include <vector>
#include <algorithm> // For sort and max
using namespace std;

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap + 1) / 2;
}

void mergeGapMethod(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int gap = nextGap(n + m);
    while (gap > 0) {
        int i = 0;
        // compare in A
        for (; i + gap < n; ++i) {
            if (A[i] > A[i+gap]) swap(A[i], A[i+gap]);
        }
        // compare A and B
        int j = gap > n ? gap - n : 0;
        for (; i < n && j < m; ++i, ++j) {
            if (A[i] > B[j]) swap(A[i], B[j]);
        }
        // compare in B
        if (j < m) {
            for (j = 0; j + gap < m; ++j) {
                if (B[j] > B[j+gap]) swap(B[j], B[j+gap]);
            }
        }
        gap = nextGap(gap);
    }
}

int main() {
    vector<int> A = {1, 4, 7, 8, 10};
    vector<int> B = {2, 3,6, 9};
    mergeGapMethod(A, B);
    cout << "After merging (in-place):\nA: ";
    for (int x : A) cout << x << " ";
    cout << "\nB: ";
    for (int x : B) cout << x << " ";
    cout << "\n";
    return 0;
}
