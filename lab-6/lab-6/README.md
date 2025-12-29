# Lab 6: Hash Tables

## Objectives

- Understand and implement hash tables with different collision resolution strategies.
- Learn to design good hash functions for different data types.
- Apply hash tables to solve real-world problems efficiently.
- Understand the trade-offs between separate chaining and open addressing.

---

## Problem 1 - The URL Shortener

**File:** `problem1.cpp`

**Scenario:**
You are building a URL shortening service (like bit.ly or tinyurl.com). The service needs to:

1. **Shorten:** Given a long URL, generate a short code and store the mapping.
2. **Expand:** Given a short code, retrieve the original URL.

Both operations must be **O(1)** on average.

**Task:**
Implement a Hash Table with **Separate Chaining** to store URL mappings.

- Implement a hash function for strings.
- Handle collisions using linked lists.
- Support `insert`, `find`, and `remove` operations.

**Example:**

```
shorten("https://www.example.com/very/long/path") -> "abc123"
expand("abc123") -> "https://www.example.com/very/long/path"
expand("xyz999") -> "NOT FOUND"
```

**Complexity Requirements:**

- Average Time: $O(1)$ for all operations
- Worst Case: $O(N)$ if all keys hash to the same bucket

---

## Problem 2 - The Student Record System

**File:** `problem2.cpp`

**Scenario:**
A university needs a fast lookup system for student records. Each student has a unique **Student ID** (integer) and associated data (name, GPA).

The system must handle:

1. **Insert:** Add a new student record.
2. **Find:** Retrieve a student's data by ID.
3. **Delete:** Remove a student record.

**Task:**
Implement a Hash Table with **Linear Probing** (Open Addressing).

- Use the modulo hash function: `h(key) = key % tableSize`
- Implement lazy deletion (mark deleted slots with a special flag).
- Handle the probe sequence correctly.

**Example:**

```
insert(12345, "Alice", 3.8)
insert(67890, "Bob", 3.5)
find(12345) -> ("Alice", 3.8)
remove(12345)
find(12345) -> NOT FOUND
```

**Complexity Requirements:**

- Average Time: $O(1)$ when load factor < 0.5
- Must handle deletions correctly without breaking probe chains

---

## Problem 3 - The Duplicate File Detector

**File:** `problem3.cpp`

**Scenario:**
You are building a tool to find duplicate files on a computer. Two files are considered duplicates if they have **identical content**, even if they have different names.

Comparing files byte-by-byte is slow ($O(N^2 \times \text{FileSize})$). Instead, you can:

1. Compute a **hash** of each file's content.
2. Files with the same hash are _likely_ duplicates.
3. Only compare actual content for files with matching hashes.

**Task:**
Implement a system that:

1. Computes a simple hash of file content (sum of ASCII values mod a large prime).
2. Groups files by their hash.
3. Reports groups of potential duplicates.

**Example:**

```
Files:
  file1.txt: "hello world"
  file2.txt: "goodbye"
  file3.txt: "hello world"  (duplicate of file1)
  file4.txt: "hello world!" (different)

Output:
  Potential duplicates:
    Group 1: file1.txt, file3.txt
```

**Note:** This demonstrates how hashing enables **fast approximate matching** before doing expensive exact comparisons.

---

## Problem 4 - The Two Sum Problem

**File:** `problem4.cpp`

**Scenario:**
This is a classic coding interview problem:

Given an array of integers and a target sum, find two numbers that add up to the target. Return their indices.

**Naive approach:** Check all pairs - $O(N^2)$
**Optimal approach:** Use a hash table - $O(N)$

**Task:**
Implement the optimal $O(N)$ solution using a hash table:

1. For each number `x` in the array:
   - Calculate `complement = target - x`
   - Check if `complement` is already in the hash table
   - If yes, return the indices
   - If no, add `x` and its index to the hash table

**Example:**

```
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]  (because nums[0] + nums[1] = 2 + 7 = 9)

Input: nums = [3, 2, 4], target = 6
Output: [1, 2]  (because nums[1] + nums[2] = 2 + 4 = 6)
```

**Complexity Requirements:**

- Time: $O(N)$
- Space: $O(N)$

---

## Problem 5 - The Anagram Grouper

**File:** `problem5.cpp`

**Scenario:**
You are building a word game that needs to group anagrams together. Two words are **anagrams** if they contain the exact same letters in a different order.

Examples: "listen" and "silent", "eat", "tea", and "ate"

**The Hashing Insight:**
Instead of sorting each word ($O(K \log K)$ per word), we can create a **hash key** based on character counts:

- "eat" -> "a1e1t1"
- "tea" -> "a1e1t1" (same key!)
- "listen" -> "e1i1l1n1s1t1"
- "silent" -> "e1i1l1n1s1t1" (same key!)

**Task:**
Implement a function that groups anagrams using a hash table:

1. For each word, generate a "signature" (sorted letters or character count).
2. Use this signature as a key in a hash table.
3. Words with the same signature are anagrams.

**Example:**

```
Input: ["eat", "tea", "tan", "ate", "nat", "bat"]

Output:
  Group 1: ["eat", "tea", "ate"]
  Group 2: ["tan", "nat"]
  Group 3: ["bat"]
```

**Complexity Requirements:**

- Time: $O(N \times K)$ where K is the average word length
- Space: $O(N \times K)$

---

## Compilation

Use the provided `Makefile` to compile the solutions.

```bash
make
./problem1
./problem2
./problem3
./problem4
./problem5
```
