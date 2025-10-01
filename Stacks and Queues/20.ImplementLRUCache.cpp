#include <iostream>
#include <unordered_map>

using namespace std;

// Node for doubly linked list
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// LRU Cache Class
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // key to node
    Node* head; // dummy head
    Node* tail; // dummy tail

    void moveToHead(Node* node) {
        // Move the given node to the head (most recently used)
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addNode(node);
    }

    void addNode(Node* node) {
        // Add the node right after head
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        // Remove the given node from the linked list
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* popTail() {
        // Pop the last node (least recently used)
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1; // Not found
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            if (cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }

    ~LRUCache() {
        // Delete nodes to free memory
        for (auto it : cache) {
            delete it.second;
        }
        delete head;
        delete tail;
    }
};

int main() {
    LRUCache lruCache(2);

    lruCache.put(1, 1);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl; // returns 1
    lruCache.put(3, 3); // evicts key 2
    cout << lruCache.get(2) << endl; // returns -1 (not found)
    lruCache.put(4, 4); // evicts key 1
    cout << lruCache.get(1) << endl; // returns -1 (not found)
    cout << lruCache.get(3) << endl; // returns 3
    cout << lruCache.get(4) << endl; // returns 4

    return 0;
}

/*   ### L18. Implement LRU Cache

The Least Recently Used (LRU) Cache is a data structure that removes the least recently used items first when the cache reaches its limit. This is often implemented using a combination of a hash map (or unordered map) and a doubly linked list.

### Problem Statement

The LRU Cache should support the following operations:

1. **Get**: Retrieve an item from the cache. If the item is present, mark it as recently used.
2. **Put**: Add a new item to the cache. If the cache exceeds its limit, remove the least recently used item.

### Example Usage

```plaintext
cache = LRUCache(2) // 2 is the capacity

cache.put(1, 1) // cache is {1=1}
cache.put(2, 2) // cache is {1=1, 2=2}
cache.get(1)    // returns 1, cache is {2=2, 1=1} (1 is recently used)
cache.put(3, 3) // evicts key 2, cache is {1=1, 3=3}
cache.get(2)    // returns -1 (not found)
cache.put(4, 4) // evicts key 1, cache is {3=3, 4=4}
cache.get(1)    // returns -1 (not found)
cache.get(3)    // returns 3, cache is {4=4, 3=3}
cache.get(4)    // returns 4, cache is {3=3, 4=4}
```

### Implementation

Here's a sample implementation of an LRU Cache in C++ using a combination of a hash map and a doubly linked list:

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

// Node for doubly linked list
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// LRU Cache Class
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // key to node
    Node* head; // dummy head
    Node* tail; // dummy tail

    void moveToHead(Node* node) {
        // Move the given node to the head (most recently used)
        node->prev->next = node->next;
        node->next->prev = node->prev;
        addNode(node);
    }

    void addNode(Node* node) {
        // Add the node right after head
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        // Remove the given node from the linked list
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* popTail() {
        // Pop the last node (least recently used)
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1; // Not found
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            if (cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }

    ~LRUCache() {
        // Delete nodes to free memory
        for (auto it : cache) {
            delete it.second;
        }
        delete head;
        delete tail;
    }
};

int main() {
    LRUCache lruCache(2);

    lruCache.put(1, 1);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl; // returns 1
    lruCache.put(3, 3); // evicts key 2
    cout << lruCache.get(2) << endl; // returns -1 (not found)
    lruCache.put(4, 4); // evicts key 1
    cout << lruCache.get(1) << endl; // returns -1 (not found)
    cout << lruCache.get(3) << endl; // returns 3
    cout << lruCache.get(4) << endl; // returns 4

    return 0;
}
```

### Explanation of the Code

1. **Data Structures**:
   - **Doubly Linked List**: Maintains the order of usage. The head is a dummy node representing the most recently used end, and the tail is a dummy node representing the least recently used end.
   - **Hash Map**: Maps keys to their corresponding nodes for O(1) access time.

2. **Core Functions**:
   - **`put(int key, int value)`**: Inserts or updates the value associated with the key.
     - If the key exists, it updates the value and promotes it to the most recently used.
     - If it doesn’t exist, it adds a new node and potentially removes the least recently used node if the capacity is exceeded.
   
   - **`get(int key)`**: Retrieves the value associated with the key and promotes the accessed node.

3. **Memory Management**: Destructor is provided to free allocated memory.

### Complexity Analysis

- **Time Complexity**:
  - `get`: O(1)
  - `put`: O(1)
  
- **Space Complexity**: O(capacity), where capacity is the maximum number of items the cache can hold.

### Conclusion

The LRU Cache implementation effectively combines a doubly linked list and hash map to achieve efficient caching mechanisms suitable for scenarios where past usage patterns dictate future needs. If you have any questions or need further clarification, feel free to ask!
*/