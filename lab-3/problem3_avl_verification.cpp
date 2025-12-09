#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ======================================================================================
// PROBLEM 3: AVL Verification
// ======================================================================================

/*
    isValidAVL(TreeNode* root)
    
    Check if the given binary tree is a valid AVL tree.
*/

bool isValidAVL(TreeNode* root) {
    // TODO: Implement this function
    
    return false;
}

// Helper to delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Tree 1 (AVL) - Is Valid? " << (isValidAVL(root1) ? "Yes" : "No") << " (Expected: Yes)" << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);

    cout << "Tree 2 (Skewed) - Is Valid? " << (isValidAVL(root2) ? "Yes" : "No") << " (Expected: No)" << endl;

    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(1);

    cout << "Tree 3 (Not BST) - Is Valid? " << (isValidAVL(root3) ? "Yes" : "No") << " (Expected: No)" << endl;

    deleteTree(root1);
    deleteTree(root2);
    deleteTree(root3);

    return 0;
}

