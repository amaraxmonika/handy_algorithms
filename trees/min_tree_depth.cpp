
#include <assert.h>
#include <iostream>

using namespace std;

// Get the minimum height of a tree where minimum height is defined as -
// The shortest path to a leaf node. 


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (!root->right) {
        return 1 + dfs(root->left);
    } else if (!root->left) {
        return 1 + dfs(root->right);
    }

    return 1 + std::min(dfs(root->left), dfs(root->right));
}

int min_depth(TreeNode* root) {
    return dfs(root);
}

int main(int argc, char **argv) {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    assert(min_depth(root) == 2);
    return 0;
}
