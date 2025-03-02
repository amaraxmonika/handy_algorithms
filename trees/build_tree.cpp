
#include <assert.h>
#include <iostream>
#include <vector>

// Build a height balanced binary search tree when given a sorted
// array of integers.
// Note: Since the array is sorted, we dont' have to get fancy with
// the tree data structure. We can can balance the height of the tree
// by ensuring that each subtree left subtree contains 1/2 of the available
// elements. If we do the same for the right side, and for all subtrees in the
// tree then we are guaranteed to be height balanced.

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* build_tree(int low, int high, vector<int>& nums) {
    // Base condition for recursive search
    if (low >= high) {
        return nullptr;
    }

    int midpoint = low + ((high - low) / 2);
    TreeNode* current = new TreeNode(nums[midpoint]);

    current->left = build_tree(low, midpoint - 1, nums);
    current->right = build_tree(midpoint + 1, high, nums);

    return current;
}

int main(int argc, char **argv) {

    vector<int> nums{-10, -3, 0, 5, 9};
    TreeNode* tree = build_tree(0, nums.size() - 1, nums);
    return 0;
}
