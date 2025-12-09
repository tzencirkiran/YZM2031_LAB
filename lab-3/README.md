# YZM2031 - Data Structures and Algorithms

## Lab Assignment 3: Trees, BST, and AVL Applications

---

## Overview

In this lab, we will be focusing on **validating tree properties**, **analyzing tree structure**, and **applying BST concepts** to solve algorithmic problems.

### Common Structure

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

---

## Problem 1: Tree Properties

### Description

Implement functions to analyze the structural properties of a binary tree.

1.  **`isComplete(TreeNode* root)`**: Determine if a binary tree is a **Complete Binary Tree**.
    - _Recall:_ In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
2.  **`isBalanced(TreeNode* root)`**: Determine if a binary tree is **height-balanced**.
    - _Definition:_ A binary tree in which the left and right subtrees of _every_ node differ in height by no more than 1.
3.  **`maxWidth(TreeNode* root)`**: Return the **maximum width** of the given tree.
    - The width of a tree is the maximum width among all levels.
    - The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

### Files

- `problem1_tree_properties.cpp`

---

## Problem 2: BST Applications

### Description

Use the properties of a Binary Search Tree to solve these problems efficiently. **Do not iterate over all nodes if you don't have to.**

1.  **`kthSmallest(TreeNode* root, int k)`**: Given the root of a BST and an integer `k`, return the `k`th smallest value (1-indexed) of all the values of the nodes in the tree.
2.  **`LCA(TreeNode* root, TreeNode* p, TreeNode* q)`**: Find the **Lowest Common Ancestor** of two nodes `p` and `q` in a BST.
3.  **`rangeSum(TreeNode* root, int L, int R)`**: Return the sum of values of all nodes with a value in the inclusive range `[L, R]`.
4.  **`invertTree(TreeNode* root)`**: Invert a binary tree.
    - Given the root of a binary tree, invert the tree, and return its root.
    - _Example:_
      ```
           4                 4
         /   \             /   \
        2     7    =>     7     2
       / \   / \         / \   / \
      1   3 6   9       9   6 3   1
      ```

### Files

- `problem2_bst_applications.cpp`

---

## Problem 3: AVL Verification

### Description

Instead of implementing the AVL insertion/deletion from scratch, you will implement a **Validator** for AVL trees. This tests your understanding of the AVL invariant.

Implement **`isValidAVL(TreeNode* root)`** which returns `true` if and only if:

1.  The tree is a valid **Binary Search Tree**.
2.  The tree is **Balanced** (Balance factor of every node is -1, 0, or 1).

You may need helper functions like `getHeight`, `isBSTHelper`, etc.

### Files

- `problem3_avl_verification.cpp`

---

## Problem 4: Advanced Challenges

### Description

These problems are designed to challenge your understanding of recursion and tree properties.

1.  **`maxPathSum(TreeNode* root)`**: Given the root of a binary tree, return the maximum path sum of any non-empty path.

    - A path is defined as any sequence of nodes where each pair of adjacent nodes has an edge connecting them.
    - The path **does not need to pass through the root**.
    - _Hint:_ A path can start at a left child, go up to the parent, and down to the right child.

2.  **`recoverTree(TreeNode* root)`**: You are given the root of a BST where the values of **exactly two nodes** were swapped by mistake. Recover the tree without changing its structure.
    - _Hint:_ Use in-order traversal to find the swapped elements.

### Files

- `problem4_advanced_trees.cpp`

---

## Academic Integrity

- You may use AI tools and resources, but you must understand your code.
- Code failing but written by you >> Successful code written by AI
