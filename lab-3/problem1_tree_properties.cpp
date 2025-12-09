#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ======================================================================================
// PROBLEM 1: Tree Properties
// ======================================================================================

/*
    1. isComplete(TreeNode* root)
    
    Check if the binary tree is a complete binary tree.
*/
bool isComplete(TreeNode* root) {
    // TODO: Implement this function
    
    return false;
}

/*
    2. isBalanced(TreeNode* root)
    
    Check if the binary tree is height-balanced.
*/

// Helper function to calculate height. You may or may not need this.
int height(TreeNode* node) {
    // TODO: Implement this function (optional helper)
    
    return 0;
}

bool isBalanced(TreeNode* root) {
    // TODO: Implement this function
    
    return false;
}

/*
    3. maxWidth(TreeNode* root)
    
    Given the root of a binary tree, return the maximum width of the given tree.
*/
int maxWidth(TreeNode* root) {
    // TODO: Implement this function
    
    return 0;
}

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Test Case 1: Complete and Balanced Tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);

    cout << "Tree 1 - Is Complete? " << (isComplete(root1) ? "Yes" : "No") << " (Expected: Yes)" << endl;
    cout << "Tree 1 - Is Balanced? " << (isBalanced(root1) ? "Yes" : "No") << " (Expected: Yes)" << endl;
    cout << "Tree 1 - Max Width? " << maxWidth(root1) << " (Expected: 3)" << endl;

    // Test Case 2: Skewed Tree (Not Balanced, Not Complete)
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);

    cout << "\nTree 2 - Is Complete? " << (isComplete(root2) ? "Yes" : "No") << " (Expected: No)" << endl;
    cout << "Tree 2 - Is Balanced? " << (isBalanced(root2) ? "Yes" : "No") << " (Expected: No)" << endl;
    cout << "Tree 2 - Max Width? " << maxWidth(root2) << " (Expected: 1)" << endl;

    deleteTree(root1);
    deleteTree(root2);
    
    return 0;
}

