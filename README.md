# LRU Cache Implementation in C++

This repository contains an efficient implementation of the **Least Recently Used (LRU) Cache**
using **C++**, designed to support `get` and `put` operations in **O(1) time**.

---

## 📌 Problem Statement

Design a data structure that follows the constraints of an **LRU Cache**:
- `get(key)` → Returns the value if the key exists, otherwise `-1`
- `put(key, value)` → Inserts or updates the value
- When capacity is exceeded, the **least recently used** item is evicted

---

## 🧠 Approach

To achieve constant time operations:
- **Doubly Linked List**
  - Maintains usage order
  - Most recently used item at the front
  - Least recently used item at the back
- **Hash Map**
  - Provides O(1) access to cache nodes

---

## ⏱️ Complexity Analysis

| Operation | Time | Space |
|----------|------|-------|
| get()    | O(1) | O(n)  |
| put()    | O(1) | O(n)  |

---

## 🚀 Key Highlights

- Uses dummy head and tail nodes to simplify edge cases
- Clean memory management
- Industry-standard cache design
- Frequently asked in system design interviews

---

## ✍️ Author

Sachin  
B.Tech Computer Science  
