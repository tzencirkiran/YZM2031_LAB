# YZM2031 - Data Structures and Algorithms

## Lab Assignment 2: Advanced Stack/Queue Applications and String Algorithms

**Duration:** 2 hours  
**Total Points:** 100  
**Covers:** Week 3, Week 4  

---

## Problem 1: Min Stack (20 points)

### Description

Design a stack that supports push, pop, top, and retrieving the minimum element in **constant time** O(1).

Implement the `MinStack` class:
- `MinStack()` initializes the stack object
- `void push(int val)` pushes the element val onto the stack
- `void pop()` removes the element on the top of the stack
- `int top()` gets the top element of the stack
- `int getMin()` retrieves the minimum element in the stack

**Challenge:** All operations must work in O(1) time complexity!

**Hint:** Consider using two stacks - one for values and one for tracking minimums. Or store pairs of (value, current_minimum).

---

## Problem 2: Implement Queue using Two Stacks (20 points)

### Description

Implement a queue data structure using only two stacks. Your queue should support the following operations:
- `enqueue(value)` - Add element to the back of queue
- `dequeue()` - Remove element from front of queue and return it
- `front()` - Get the front element
- `isEmpty()` - Check if queue is empty

You can only use stack operations (push, pop, top, isEmpty).

### Requirements

**Hint:** Use stack1 for enqueue operations. When dequeuing, if stack2 is empty, transfer all elements from stack1 to stack2 (reversing the order).

---

## Problem 3: Sliding Window Maximum (25 points)

### Description

Given an array of integers and a window size k, find the maximum value in each sliding window as it moves from left to right through the array.

Use a **deque** to solve this efficiently in O(n) time complexity.

### Example

```
Array: [1, 3, -1, -3, 5, 3, 6, 7]
Window size k = 3

Windows:
[1  3  -1] -3  5  3  6  7  -> max = 3
 1 [3  -1  -3] 5  3  6  7  -> max = 3
 1  3 [-1  -3  5] 3  6  7  -> max = 5
 1  3  -1 [-3  5  3] 6  7  -> max = 5
 1  3  -1  -3 [5  3  6] 7  -> max = 6
 1  3  -1  -3  5 [3  6  7] -> max = 7

Output: [3, 3, 5, 5, 6, 7]
```

**Hint:** Use a deque to store indices. Keep the deque in decreasing order of values. Remove indices that are out of the current window.

---

## Problem 4: String Compression (20 points)

### Description

Implement a function that compresses a string using the counts of repeated characters. 

- If the compressed string is not shorter than the original, return the original string.
- The compression should be case-sensitive.
- Only compress consecutive repeated characters.

### Examples

```
"aabcccccaaa" -> "a2b1c5a3"
"abc" -> "abc" (compressed would be "a1b1c1", which is longer)
"aabbcc" -> "aabbcc" (compressed would be "a2b2c2", same length)
"aaabbbccc" -> "a3b3c3"
```

**Hint:** Keep track of the current character and its count. Build the compressed string. Compare lengths at the end.

---

## Problem 5: Remove Adjacent Duplicates (15 points)

### Description

Given a string, repeatedly remove adjacent duplicate characters. When two adjacent characters are the same, remove both of them. Continue this process until no more adjacent duplicates can be removed.

Use a **stack** to solve this efficiently in O(n) time.

### Examples

```
Input: "abbaca"
Output: "ca"
Explanation: 
  - Remove "bb" → "aaca"
  - Remove "aa" → "ca"

Input: "azxxzy"  
Output: "ay"
Explanation:
  - Remove "xx" → "azzy"
  - Remove "zz" → "ay"

Input: "aabbcc"
Output: ""
Explanation: All characters cancel out
```

### Algorithm Tip

1. Create an empty stack
2. For each character in the string:
   - If stack is empty OR top of stack != current character: push character
   - If top of stack == current character: pop (they cancel each other)
3. Build result string from remaining characters in stack

**Hint:** The stack automatically handles the cascading effect of removals. When you pop a character, the next comparison might create a new match!

---

## Grading Summary

| Problem | Points | Topic |
|---------|--------|-------|
| Problem 1: Min Stack | 20 | Week 3: Advanced Stack Design |
| Problem 2: Queue Using Stacks | 20 | Week 3: Stack/Queue Relationship |
| Problem 3: Sliding Window Maximum | 25 | Week 3: Deque Applications |
| Problem 4: String Compression | 20 | Week 4: String Processing |
| Problem 5: Remove Duplicates | 15 | Week 3-4: Stack + Strings |
| **Total** | **100** | |

---

## Academic Integrity

- You may use AI tools and resources, but you must understand your code. Randomly selected solutions will be evaluated verbally.
- All submitted code must be your own work.
- Plagiarism will result in zero points and potential disciplinary action.