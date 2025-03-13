
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void level_traversal(TreeNode* root, int level, vector<vector<int>>& result) {
    if (root == nullptr) {
        return;
    }

    // Make sure index exists
    if (result.size() <= level) {
        result.push_back({});
    }
    result[level].push_back(root->val);
    level_traversal(root->left, level + 1, result);
    level_traversal(root->right, level + 1, result);
}

int main() {
    TreeNode* root = new TreeNode(7); 
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(13);
    root->left->right = new TreeNode(15);

    root->right = new TreeNode(11);

    vector<vector<int>> result(0, vector<int>(10));
    level_traversal(root, 0, result);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
