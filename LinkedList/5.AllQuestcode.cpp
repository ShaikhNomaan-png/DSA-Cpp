/*
  Striver Linked List Playlist - Full solutions (L1 - L24)
  Language: C++ (modern, compile with C++17 or later)

  Each section contains: problem title, short note, and a standalone solution
  You can copy each section into a separate file or compile together and call specific
  testing functions from main.

  Note: For brevity, helper I/O/testing is minimal — these are focused, clean implementations.
*/

#include <bits/stdc++.h>
using namespace std;

/*************** L1: Introduction to LinkedList | Traversal | Length | Search an Element ***************/
// Simple singly linked list with basic operations
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// create from vector
ListNode* createList(const vector<int>& a) {
    ListNode* head = nullptr; ListNode* tail = nullptr;
    for (int x : a) {
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node; else { tail->next = node; tail = node; }
    }
    return head;
}

int lengthLL(ListNode* head) {
    int cnt = 0; while (head) { cnt++; head = head->next; } return cnt;
}

bool searchLL(ListNode* head, int key) {
    while (head) { if (head->val == key) return true; head = head->next; } return false;
}

void printList(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << " -> "; head = head->next; } cout << '\n';
}

/*************** L2: Deletion and Insertion in LL | 8 Problems ***************/
// Insert at head, tail, at position; delete by value/position
ListNode* insertAtHead(ListNode* head, int val) {
    ListNode* node = new ListNode(val);
    node->next = head; return node;
}

ListNode* insertAtTail(ListNode* head, int val) {
    ListNode* node = new ListNode(val);
    if (!head) return node;
    ListNode* cur = head; while (cur->next) cur = cur->next;
    cur->next = node; return head;
}

ListNode* insertAtPosition(ListNode* head, int pos, int val) {
    // pos: 0-based, insert at pos
    if (pos == 0) return insertAtHead(head, val);
    ListNode* cur = head; int i = 0;
    while (cur && i < pos-1) { cur = cur->next; i++; }
    if (!cur) return head; // invalid position
    ListNode* node = new ListNode(val);
    node->next = cur->next; cur->next = node; return head;
}

ListNode* deleteAtPosition(ListNode* head, int pos) {
    if (!head) return head;
    if (pos == 0) { ListNode* nxt = head->next; delete head; return nxt; }
    ListNode* cur = head; int i = 0;
    while (cur->next && i < pos-1) { cur = cur->next; i++; }
    if (!cur->next) return head;
    ListNode* toDel = cur->next; cur->next = toDel->next; delete toDel; return head;
}

ListNode* deleteByValue(ListNode* head, int val) {
    if (!head) return head;
    // delete first occurrence
    if (head->val == val) { ListNode* nxt = head->next; delete head; return nxt; }
    ListNode* cur = head;
    while (cur->next && cur->next->val != val) cur = cur->next;
    if (cur->next) { ListNode* toDel = cur->next; cur->next = toDel->next; delete toDel; }
    return head;
}

/*************** L3: Introduction to Doubly LinkedList | Insertions and Deletions ***************/
struct DNode {
    int val; DNode* prev; DNode* next; DNode(int x): val(x), prev(nullptr), next(nullptr) {}
};

DNode* insertAtHeadDLL(DNode* head, int val) {
    DNode* node = new DNode(val);
    if (!head) return node;
    node->next = head; head->prev = node; return node;
}

DNode* insertAtTailDLL(DNode* head, int val) {
    DNode* node = new DNode(val);
    if (!head) return node;
    DNode* cur = head; while (cur->next) cur = cur->next;
    cur->next = node; node->prev = cur; return head;
}

DNode* deleteNodeDLL(DNode* head, DNode* toDel) {
    if (!head || !toDel) return head;
    if (head == toDel) head = toDel->next;
    if (toDel->next) toDel->next->prev = toDel->prev;
    if (toDel->prev) toDel->prev->next = toDel->next;
    delete toDel; return head;
}

/*************** L4: Reverse a DLL | Multiple Approaches ***************/
DNode* reverseDLL(DNode* head) {
    DNode* cur = head; DNode* tmp = nullptr;
    while (cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev; // because swapped
    }
    if (tmp) head = tmp->prev;
    return head;
}

/*************** L5: Reverse a Linked List | Iterative and Recursive ***************/
ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = nullptr; ListNode* cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur; cur = nxt;
    }
    return prev;
}

ListNode* reverseRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

/*************** L6: Odd Even Linked List | Multiple Approaches ***************/
ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    ListNode* odd = head; ListNode* even = head->next; ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next; odd = odd->next;
        even->next = odd->next; even = even->next;
    }
    odd->next = evenHead; return head;
}

/*************** L7: Check if a LinkedList is Palindrome or Not | Multiple Approaches ***************/
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    // find mid
    ListNode* slow = head; ListNode* fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    // reverse second half
    ListNode* second = reverseIterative(slow);
    ListNode* first = head;
    bool ok = true;
    while (second) {
        if (first->val != second->val) { ok = false; break; }
        first = first->next; second = second->next;
    }
    return ok;
}

/*************** L8: Merge Two Sorted Linked Lists ***************/
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode dummy(0); ListNode* tail = &dummy;
    while (A && B) {
        if (A->val <= B->val) { tail->next = A; A = A->next; }
        else { tail->next = B; B = B->next; }
        tail = tail->next;
    }
    tail->next = A ? A : B;
    return dummy.next;
}

/*************** L9: Detect a loop or cycle in LinkedList | With proof and Intuition ***************/
bool hasCycle(ListNode* head) {
    ListNode* slow = head; ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

/*************** L10: Find the starting point of the loop in a LinkedList ***************/
ListNode* detectCycleStart(ListNode* head) {
    ListNode* slow = head; ListNode* fast = head;
    bool found = false;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return nullptr;
    slow = head;
    while (slow != fast) { slow = slow->next; fast = fast->next; }
    return slow;
}

/*************** L11: Remove Nth Node From End of Linked List ***************/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0); dummy.next = head; ListNode* first = &dummy; ListNode* second = &dummy;
    for (int i = 0; i <= n; ++i) first = first->next; // move first n+1 ahead
    while (first) { first = first->next; second = second->next; }
    ListNode* toDel = second->next; second->next = toDel->next; delete toDel; return dummy.next;
}

/*************** L12: Delete Middle Node of a Linked List ***************/
ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) { delete head; return nullptr; }
    ListNode* slow = head; ListNode* fast = head; ListNode* prev = nullptr;
    while (fast && fast->next) { prev = slow; slow = slow->next; fast = fast->next->next; }
    prev->next = slow->next; delete slow; return head;
}

/*************** L13: Intersection Point of Two Linked Lists ***************/
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode* a = headA; ListNode* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

/*************** L14: Add Two Numbers Given as LinkedLists ***************/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); ListNode* tail = &dummy; int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
        carry = sum/10; tail->next = new ListNode(sum%10); tail = tail->next;
        if (l1) l1 = l1->next; if (l2) l2 = l2->next;
    }
    return dummy.next;
}

/*************** L15: Clone a Linked List with next and random pointer (O(N) time O(1) space) ***************/
struct RandNode { int val; RandNode* next; RandNode* random; RandNode(int v): val(v), next(nullptr), random(nullptr) {} };

RandNode* cloneRandomList(RandNode* head) {
    if (!head) return nullptr;
    // step1: interleave cloned nodes
    RandNode* cur = head;
    while (cur) {
        RandNode* node = new RandNode(cur->val);
        node->next = cur->next; cur->next = node; cur = node->next;
    }
    // step2: copy randoms
    cur = head;
    while (cur) {
        if (cur->random) cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
    // step3: separate
    cur = head; RandNode* cloneHead = head->next;
    while (cur) {
        RandNode* tmp = cur->next; cur->next = tmp->next;
        cur = cur->next; if (cur) tmp->next = cur->next;
    }
    return cloneHead;
}

/*************** L16: Rotate a LinkedList ***************/
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    // compute length and tail
    ListNode* tail = head; int n = 1;
    while (tail->next) { tail = tail->next; n++; }
    k %= n; if (k == 0) return head;
    // make circular
    tail->next = head;
    int stepsToNewHead = n - k;
    ListNode* newTail = tail;
    while (stepsToNewHead--) newTail = newTail->next;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

/*************** L17: Reverse Nodes in k-Group ***************/
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;
    ListNode dummy(0); dummy.next = head; ListNode* prev = &dummy;
    ListNode* cur = head;
    int i = 0;
    while (cur) { cur = cur->next; i++; }
    while (i >= k) {
        cur = prev->next; ListNode* nex = cur->next;
        for (int j = 1; j < k; ++j) {
            cur->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = cur->next;
        }
        prev = cur; i -= k;
    }
    return dummy.next;
}

/*************** L18: Sort a Linked List (Merge sort) ***************/
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    // split
    ListNode* slow = head; ListNode* fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode* mid = slow->next; slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return mergeTwoLists(left, right);
}

/*************** L19: Flatten a Multilevel Doubly Linked List ***************/
// Definition reused: DNode with prev & next & we use child pointer here
struct MultiDNode { int val; MultiDNode* prev; MultiDNode* next; MultiDNode* child; MultiDNode(int x): val(x), prev(nullptr), next(nullptr), child(nullptr) {} };

MultiDNode* flattenMultiDLL(MultiDNode* head) {
    if (!head) return head;
    MultiDNode* cur = head;
    stack<MultiDNode*> st;
    while (cur) {
        if (cur->child) {
            if (cur->next) st.push(cur->next);
            cur->next = cur->child;
            cur->next->prev = cur;
            cur->child = nullptr;
        }
        if (!cur->next && !st.empty()) {
            cur->next = st.top(); st.pop(); cur->next->prev = cur;
        }
        cur = cur->next;
    }
    return head;
}

/*************** L20: Flatten a Linked List (list of lists where each node has next and bottom pointers) ***************/
// We'll assume typical "flatten linked list" where each node has next and bottom pointers and bottom lists are sorted
struct BNode { int val; BNode* next; BNode* bottom; BNode(int x): val(x), next(nullptr), bottom(nullptr) {} };

BNode* mergeBottom(BNode* a, BNode* b) {
    BNode dummy(0); BNode* tail = &dummy;
    while (a && b) {
        if (a->val < b->val) { tail->bottom = a; a = a->bottom; }
        else { tail->bottom = b; b = b->bottom; }
        tail = tail->bottom;
    }
    tail->bottom = a ? a : b;
    return dummy.bottom;
}

BNode* flattenLinkedList(BNode* root) {
    if (!root || !root->next) return root;
    root->next = flattenLinkedList(root->next);
    root = mergeBottom(root, root->next);
    return root;
}

/*************** L21: Merge K Sorted Lists (using min-heap) ***************/
struct Cmp {
    bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for (auto l : lists) if (l) pq.push(l);
    ListNode dummy(0); ListNode* tail = &dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop(); tail->next = node; tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

/*************** L22: Design a Browser History ***************/
class BrowserHistory {
    vector<string> history; int cur = -1;
public:
    BrowserHistory(string homepage) { history.push_back(homepage); cur = 0; }
    void visit(string url) {
        history.resize(cur+1); history.push_back(url); cur = history.size()-1;
    }
    string back(int steps) {
        cur = max(0, cur - steps); return history[cur];
    }
    string forward(int steps) {
        cur = min((int)history.size()-1, cur + steps); return history[cur];
    }
};

/*************** L23: LRU Cache Implementation ***************/
class LRUCache {
    int cap;
    list<pair<int,int>> dq; // key,val front is most recent
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity): cap(capacity) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        auto nodeIt = it->second;
        int val = nodeIt->second;
        dq.erase(nodeIt);
        dq.push_front({key,val}); mp[key] = dq.begin();
        return val;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dq.erase(mp[key]); mp.erase(key);
        }
        if ((int)dq.size() == cap) {
            auto last = dq.back(); mp.erase(last.first); dq.pop_back();
        }
        dq.push_front({key,value}); mp[key] = dq.begin();
    }
};

/*************** L24: LFU Cache Implementation ***************/
class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int,int>> valFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqList; // freq -> list of keys (LRU in that freq)
    unordered_map<int, list<int>::iterator> iterMap; // key -> iterator in freqList[f]
public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}
    int get(int key) {
        if (capacity == 0) return -1;
        if (!valFreq.count(key)) return -1;
        int value = valFreq[key].first; int f = valFreq[key].second;
        // remove from current freq list
        freqList[f].erase(iterMap[key]);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }
        // add to f+1
        valFreq[key].second = f+1;
        freqList[f+1].push_front(key);
        iterMap[key] = freqList[f+1].begin();
        return value;
    }
    void put(int key, int value) {
        if (capacity == 0) return;
        if (valFreq.count(key)) {
            valFreq[key].first = value; get(key); return;
        }
        if ((int)valFreq.size() == capacity) {
            // evict least frequently used: minFreq, last element in list
            int evictKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            valFreq.erase(evictKey); iterMap.erase(evictKey);
        }
        valFreq[key] = {value,1};
        freqList[1].push_front(key);
        iterMap[key] = freqList[1].begin();
        minFreq = 1;
    }
};


// Main is left as a small driver to demonstrate usage for testing. Uncomment to run small tests.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example usage: create list and print
    ListNode* head = createList({1,2,3,4,5});
    cout << "L1 example list: "; printList(head);
    cout << "Length: " << lengthLL(head) << '\n';
    cout << "Search 3? " << (searchLL(head,3)?"Yes":"No") << '\n';

    // Reverse iterative
    ListNode* rev = reverseIterative(head);
    cout << "Reversed: "; printList(rev);

    // Cleanup omitted for brevity
    return 0;
}
