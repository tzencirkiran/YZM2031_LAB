#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ======================================================================================
// PROBLEM 4: Advanced Challenges
// ======================================================================================

/*
    1. Binary Tree Maximum Path Sum
    
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
    A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
    The path sum is the sum of the node's values in the path.
    Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

int globalMax = INT_MIN;

int maxGain(TreeNode* node) {
    // TODO: Implement this helper function to return the max gain from a node down to a leaf
    
    return 0;
}

int maxPathSum(TreeNode* root) {
    // TODO: Implement this function
    
    return 0;
}

/*
    2. Recover Binary Search Tree
    
    You are given the root of a binary search tree (BST), where the values of exactly two nodes 
    of the tree were swapped by mistake. Recover the tree without changing its structure.
*/

TreeNode* first = nullptr;
TreeNode* second = nullptr;
TreeNode* prevNode = nullptr;

void inorder(TreeNode* root) {
    // TODO: Implement inorder traversal to find the two swapped nodes
}

void recoverTree(TreeNode* root) {
    // TODO: Implement this function
}

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper to print inorder (for verifying recovery)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root1 = new TreeNode(-10);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    cout << "Max Path Sum: " << maxPathSum(root1) << " (Expected: 42)" << endl;
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->left->right = new TreeNode(2);
    
    cout << "Before Recovery (Inorder): ";
    printInorder(root2);
    cout << endl;
    
    recoverTree(root2);
    
    cout << "After Recovery (Inorder):  ";
    printInorder(root2);
    cout << " (Expected: 1 2 3)" << endl;

    deleteTree(root1);
    deleteTree(root2);
    return 0;
}

