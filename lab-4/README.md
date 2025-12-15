# Lab 4: Heaps & Sorting Algorithms

## Problem 1: The Emergency Room Triage

**File:** `problem1.cpp`

**Scenario:**
You are designing the backend for a hospital's Emergency Room (ER) triage system. Patients arrive with a "Severity Score" (integer).

- **Lower score** = More critical condition (e.g., 1 is a heart attack, 100 is a stubbed toe).
- The system must **always** be able to instantly tell the doctors who the next most critical patient is.
- When a doctor treats a patient, that patient is removed from the system.
- New patients can arrive at any time.

**Task:**
Implement a data structure that efficiently handles:

1.  `insert(severity)`: A new patient arrives.
2.  `extractNext()`: The doctor calls for the most critical patient.
3.  `peekNext()`: The nurse checks who is next without removing them.

**Example:**

```
insert 10 (Stubbed Toe)
insert 1 (Heart Attack)
insert 5 (Broken Arm)
peek -> 1
extract -> 1
peek -> 5
```

---

## Problem 2: The Mars Rover Memory Constraint

**File:** `problem2.cpp`

**Scenario:**
You are writing firmware for a Mars Rover. The rover collects a batch of sensor readings that must be sorted before transmission to Earth to prioritize data compression.
**Constraints:**

1.  **Strict Memory Limit:** The rover has very little RAM. You **cannot** allocate a secondary array (like Merge Sort requires). The sort must be **In-Place**.
2.  **Safety:** The system stack is small. Deep recursion (like Quick Sort's worst case) could cause a Stack Overflow and crash the rover.
3.  **Performance:** You need guaranteed $O(N \log N)$ performance regardless of data distribution.

**Task:**
Implement a sorting algorithm that meets these strict safety and memory criteria.

**Input:** `[12, 11, 13, 5, 6, 7]`
**Output:** `[5, 6, 7, 11, 12, 13]`

---

## Problem 3: The High-Frequency Trading Monitor

**File:** `problem3.cpp`

**Scenario:**
A financial algorithm processes a stream of millions of transaction amounts. The compliance team asks you to identify the **K-th largest transaction** seen so far to set dynamic alert thresholds.

- **Challenge:** You do not need to sort the entire stream (too slow). You only care about the "Top K" largest values.
- **Example:** If $K=3$ and transactions are `[100, 20, 500, 10, 300]`, the top 3 are `[500, 300, 100]`. The 3rd largest is `100`.

**Task:**
Implement a function that finds the K-th largest element efficiently.

**Example:**
Input: `nums = [3, 2, 1, 5, 6, 4], k = 2`
Output: `5`

---

## Problem 4: The Sorting Consultant

**File:** `problem4.cpp`

**Scenario:**
You have started a consulting company specializing in algorithm optimization. Today, three different clients have come to you with sorting problems. Each client has **different constraints**, and you must choose the **right algorithm** for each situation.

### Client 1: The Art Gallery Auction
An auction house needs to sort bids by amount. **Critical requirement:** When two bids have the same amount, the bid that arrived **first** must appear first (legal fairness requirement).

- **Key constraint:** Stability

### Client 2: The Spacecraft Navigation System
A satellite receives sensor readings that are **almost sorted** after each update cycle (only ~5% displaced). Memory is extremely limited.

- **Key constraints:** O(1) extra space, nearly-sorted input

### Client 3: The Student Grade System
Sort 50,000 student grades (integers 0-100). Must be faster than O(n log n).

- **Key constraint:** Known, limited range of integer values
---

## Academic Integrity

- You may use AI tools and resources, but you must understand your code.
- Code failing but written by you >> Successful code written by AI

