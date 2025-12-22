# Lab 5: Sorting Algorithms & Disjoint Sets

## Objectives

- Understand and implement different sorting algorithms and their trade-offs.
- Learn when to use stable vs unstable sorting algorithms.
- Implement the Union-Find (Disjoint Set Union) data structure.
- Apply disjoint sets to solve connectivity problems.

---

## Problem 1: The Music Streaming Playlist

**File:** `problem1.cpp`

**Scenario:**
You are building the backend for a music streaming service. The product team wants to display songs sorted by their play count (most popular first). However, there's a catch: **songs with the same play count must remain in their original alphabetical order**.

For example, if songs A, B, C all have 100 plays, they should appear as A, B, C (not shuffled).

**Why This Matters:**

- Users complained that the playlist "jumps around" when refreshed.
- Quick Sort and Heap Sort are **not stable** — equal elements may be reordered.
- You need a **stable** sorting algorithm.

**Task:**
Implement **Merge Sort** to sort songs by play count in descending order while maintaining stability.

**Example:**

```
Input:
  Songs: [("A", 100), ("B", 200), ("C", 100), ("D", 150)]

After stable sort by play count (descending):
  [("B", 200), ("D", 150), ("A", 100), ("C", 100)]

Note: "A" comes before "C" because they have the same play count
and "A" appeared before "C" in the original list.
```

**Complexity Requirements:**

- Time: $O(N \log N)$
- Space: $O(N)$ auxiliary space
- Must be stable!

---

## Problem 2: The Social Network

**File:** `problem2.cpp`

**Scenario:**
You are building a social network where users can become friends. The system needs to efficiently:

1. **Connect two users** as friends (Union operation)
2. **Check if two users are in the same friend group** (Find operation)

A "friend group" is defined transitively: if A is friends with B, and B is friends with C, then A, B, and C are all in the same friend group.

**Task:**
Implement a **Union-Find (Disjoint Set Union)** data structure with:

1. `find(x)`: Find the representative (root) of x's set
2. `unite(x, y)`: Merge the sets containing x and y
3. `connected(x, y)`: Check if x and y are in the same set


**Example:**

```
Initial: 5 users (0, 1, 2, 3, 4) - each in their own group

unite(0, 1) -> Users 0 and 1 are now friends
unite(2, 3) -> Users 2 and 3 are now friends
unite(1, 3) -> Now {0,1,2,3} are all connected

connected(0, 3) -> true (same friend group)
connected(0, 4) -> false (different groups)
```

**Complexity Requirements:**

- Nearly $O(1)$ amortized time per operation (with both optimizations)

---

## Problem 3: The Network Infrastructure

**File:** `problem3.cpp`

**Scenario:**
A telecom company has $N$ data centers. Over time, they lay fiber optic cables between pairs of data centers. The network operations team frequently asks:

1. "Can data center X communicate with data center Y?" (directly or through other centers)
2. "How many separate networks do we have?" (isolated groups of data centers)

**Task:**
Using Union-Find, implement a system that processes a sequence of operations:

- `C x y`: Connect data centers x and y with a cable
- `Q x y`: Query if x and y can communicate (print "YES" or "NO")
- `N`: Print the number of separate networks

**Example:**

```
5 data centers (0-4), initially no connections

C 0 1    -> Connect 0 and 1
C 2 3    -> Connect 2 and 3
N        -> Output: 3 (networks: {0,1}, {2,3}, {4})
Q 0 2    -> Output: NO
C 1 2    -> Connect 1 and 2 (merges two networks)
Q 0 3    -> Output: YES
N        -> Output: 2 (networks: {0,1,2,3}, {4})
```

---

## Problem 4: The Database Index Builder

**File:** `problem4.cpp`

**Scenario:**
You are optimizing a database system. The database stores millions of records with integer keys in a known range (e.g., student IDs from 0 to 999,999 or ages from 0 to 150).

Your manager asks: "Can we sort faster than $O(N \log N)$?"

The answer is **YES** — when the range of values is limited, we can use **linear-time sorting algorithms**!

**Task:**
Implement and compare:

1. **Counting Sort**: For sorting ages (range 0-150)

   - Time: $O(N + K)$ where K is the range
   - Not suitable for large ranges

2. **Radix Sort**: For sorting student IDs (range 0-999,999)
   - Time: $O(d \times (N + K))$ where d is number of digits
   - Uses Counting Sort as a subroutine


**Example Output:**

```
=== Database Index Builder Benchmark ===
Data size: 100,000 records

Sorting ages (0-150):
  Counting Sort: 2 ms
  Quick Sort:    15 ms

Sorting IDs (0-999999):
  Radix Sort:    8 ms
  Quick Sort:    18 ms
```

---

## Problem 5: The Maze Generator

**File:** `problem5.cpp`

**Scenario:**
You want to procedurally generate a perfect maze (a maze with no loops and exactly one path between any two points).

A classic way to do this is using **Randomized Kruskal's Algorithm**:

1. Start with a grid where every cell is separated by walls.
2. Consider all possible walls as "edges".
3. Randomly select walls to remove.
4. If the cells separated by a wall are NOT already connected, remove the wall.
5. If they are already connected, keep the wall (removing it would create a cycle/loop).

**Task:**

1. Implement a **Union-Find** data structure.
2. Initialize a grid of size $W \times H$.
3. Generate a maze using Randomized Kruskal's Algorithm.
4. Visualize the maze using ASCII characters.

**Algorithm:**

1. Create a list of all internal walls (vertical and horizontal).
2. Shuffle the list of walls randomly.
3. Iterate through each wall:
   - Identify the two cells separated by this wall.
   - Use `find()` to check if they are already connected.
   - If `find(cell1) != find(cell2)`:
     - `unite(cell1, cell2)`
     - Mark the wall as "removed" (for printing).

**Example Output:**

```
+---+---+---+---+---+
|           |       |
+---+   +   +   +---+
|       |   |       |
+   +---+   +---+   +
|   |       |       |
+   +   +---+   +   +
|       |           |
+---+---+---+---+---+
```

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