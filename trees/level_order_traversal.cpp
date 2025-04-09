#include <iostream>
/*#include <deque>*/
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;

struct Node {
  Node* left;
  Node* right;
  int val;
  Node(int value) : val(value) {}
};

vector<vector<Node*>> level_order_traversal(Node* root) {
  if (root == nullptr) {
    return {};
  }

  queue<Node*> q;
  q.push(root);

  vector<vector<Node*>> result;

  while (!q.empty()) {
    int level_size = q.size();
    vector<Node*> level;

    for (int i = 0; i < level_size; i++) {
      auto current = q.front();
      q.pop();
      level.push_back(current);

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
    result.push_back(level);
  }

  return result;
}

int main (int argc, char *argv[]) {

  Node* root = new Node(0);
  root->left = new Node(1);
  root->right = new Node(2);

  root->left->left = new Node(3);
  root->left->right = new Node(4);
  
  root->right->left = new Node(5);
  root->right->right = new Node(6);

  auto result = level_order_traversal(root);

  for (const auto& level : result) {
    for (const auto& node : level) {
      cout << node->val << " " << endl;
    }
  }
  return 0;
}
