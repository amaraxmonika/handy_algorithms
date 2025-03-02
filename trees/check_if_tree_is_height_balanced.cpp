
#include <assert.h>
#include <iostream>

using namespace std;


// Check if a given tree is height balanced
// This algorithm takes advantage of the tree structure.
// For any tree node, if abs(left_depth, right_depth) <= 1 then
// the tree is said to be height balanced.
// I couldn't find a better way to track if a nested subtree is
// balanced, so I'm using an "in" parameter called "is_balanced".
// This can be set by any child node who's subtrees are not balanced.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int check_depth(TreeNode* current, bool* is_balanced) {
    if (current == nullptr) {
        return 0;
    }

    int left_depth = check_depth(current->left, is_balanced);
    int right_depth = check_depth(current->right, is_balanced);

    if (std::abs(left_depth - right_depth) > 1) {
        *is_balanced = false;
    }

    return 1 + std::max(left_depth, right_depth);
}

bool is_balanced(TreeNode* root) {
    bool balanced = true;
    int max_depth = check_depth(root, &balanced);
    return balanced;
}

int main(int argc, char **argv) {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    assert(is_balanced(root) == true);
    return 0;
}
