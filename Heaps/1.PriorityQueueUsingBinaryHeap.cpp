//Min Heap and Max Heap Implementation
/*  🔹 What is a Priority Queue?
A priority queue is like a queue, but instead of FIFO (first-in, first-out), each element has a priority.
The highest (or lowest) priority element is removed first.
Internally, it is often implemented using a binary heap for efficiency.
🔹 Binary Heap Basics
A Binary Heap is:
A complete binary tree (all levels filled except maybe the last, filled left to right).
Maintains heap property:
Max-Heap: parent ≥ children → root is maximum.
Min-Heap: parent ≤ children → root is minimum.
Operations (all in O(log n) time):
Insert (push element while maintaining heap property).
Get Top (root = max/min, O(1)).
Extract Top (remove root, reheapify).
Key Points for Interviews
STL priority_queue uses a binary heap (usually implemented as a vector + make_heap functions).
Default = Max Heap. For Min Heap, pass greater<T>.
Common applications:
Dijkstra’s Algorithm (shortest path).
Huffman Coding (compression).
Scheduling problems.
Median finding using two heaps.
*/
#include <iostream>
#include <vector>
using namespace std;

// =======================
// Max Heap Functions
// =======================

// Get parent and children indices
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// Heapify Up (for insertion)
void heapifyUpMax(vector<int> &heap, int i) {
    if (i && heap[parent(i)] < heap[i]) {
        swap(heap[i], heap[parent(i)]);
        heapifyUpMax(heap, parent(i));
    }
}

// Heapify Down (for deletion)
void heapifyDownMax(vector<int> &heap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;
    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDownMax(heap, largest);
    }
}

void pushMax(vector<int> &heap, int key) {
    heap.push_back(key);
    heapifyUpMax(heap, heap.size() - 1);
}

void popMax(vector<int> &heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownMax(heap, 0);
}

int topMax(vector<int> &heap) {
    if (heap.empty()) return -1;
    return heap[0];
}

// =======================
// Min Heap Functions
// =======================

void heapifyUpMin(vector<int> &heap, int i) {
    if (i && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        heapifyUpMin(heap, parent(i));
    }
}

void heapifyDownMin(vector<int> &heap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heap.size() && heap[left] < heap[smallest])
        smallest = left;
    if (right < heap.size() && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDownMin(heap, smallest);
    }
}

void pushMin(vector<int> &heap, int key) {
    heap.push_back(key);
    heapifyUpMin(heap, heap.size() - 1);
}

void popMin(vector<int> &heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownMin(heap, 0);
}

int topMin(vector<int> &heap) {
    if (heap.empty()) return -1;
    return heap[0];
}

// =======================
// Main Function
// =======================
int main() {
    // ---------- Max Heap ----------
    cout << "---- Max Heap (Priority Queue) ----" << endl;
    vector<int> maxHeap;

    pushMax(maxHeap, 10);
    pushMax(maxHeap, 30);
    pushMax(maxHeap, 20);
    pushMax(maxHeap, 5);
    pushMin(maxHeap, 40);
    pushMin(maxHeap, 15);


    cout << "Top element: " << topMax(maxHeap) << endl;
    cout << "Heap elements: ";
    while (!maxHeap.empty()) {
        cout << topMax(maxHeap) << " ";
        popMax(maxHeap);
    }
    cout << endl << endl;

    // ---------- Min Heap ----------
    cout << "---- Min Heap (Priority Queue) ----" << endl;
    vector<int> minHeap;

    pushMin(minHeap, 10);
    pushMin(minHeap, 30);
    pushMin(minHeap, 20);
    pushMin(minHeap, 5);
    pushMin(minHeap, 40);
    pushMin(minHeap, 15);


    cout << "Top element: " << topMin(minHeap) << endl;
    cout << "Heap elements: ";
    while (!minHeap.empty()) {
        cout << topMin(minHeap) << " ";
        popMin(minHeap);
    }
    cout << endl;

    return 0;
}
