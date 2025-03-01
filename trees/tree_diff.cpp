
#include <iostream>
#include <assert.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

bool compare_trees(TreeNode* a, TreeNode* b) {
    // Base case where both nodes are null then trees match
    if (a == nullptr && b == nullptr) {
        return true;
    }
    // Base case where they dont match
    if (a == nullptr || b == nullptr) {
        return false;
    }

    // Recurse all the way left for prefix tree
    bool left_subtree = compare_trees(a->left, b->left);
    // Compare current values
    bool values_match = a->val == b->val;
    // Recurse all the way left for prefix tree
    bool right_subtree = compare_trees(a->right, b->right);

    return left_subtree && values_match && right_subtree;
}

int main(int argc, char **argv) {
    TreeNode* tree_a = new TreeNode(1);
    tree_a->left = new TreeNode(2);
    tree_a->right = new TreeNode(3);

    TreeNode* tree_b = new TreeNode(1);
    tree_b->left = new TreeNode(2);
    tree_b->right = new TreeNode(3);


    assert(compare_trees(tree_a, tree_b));
    return 0;
}
