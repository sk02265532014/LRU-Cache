/*
    LRU Cache Implementation
    ------------------------
    Time Complexity:
        get()  -> O(1)
        put()  -> O(1)

    Space Complexity:
        O(capacity)

    Approach:
        - Doubly Linked List to maintain usage order
        - HashMap to provide O(1) access to nodes
*/

#include <unordered_map>
using namespace std;

class LRUCache {
public:
    // Doubly Linked List Node
    struct Node {
        int key, value;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    // Constructor
    LRUCache(int capacity) {
        cap = capacity;

        // Dummy head and tail nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from the linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (Most Recently Used)
    void insertFront(Node* node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    // Get value of key
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Move accessed node to front (MRU)
        remove(node);
        insertFront(node);

        return node->value;
    }

    // Put key-value pair
    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insertFront(node);
            return;
        }

        // Cache is full → remove LRU
        if (mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }

        // Insert new node
        Node* node = new Node(key, value);
        mp[key] = node;
        insertFront(node);
    }
};
