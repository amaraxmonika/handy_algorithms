#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
  ListNode* next;
  int value;
  ListNode(int val) : value(val), next(nullptr) {}
};

class LinkedList {
  ListNode* head;
  int length;

public:
  LinkedList() {
    this->head = nullptr;
    this->length = 0;
  }

  void print() {
    ListNode* current = head;
    while (current != nullptr) {
      std::cout << "[ " << current->value << " ] -> ";
      current = current->next;
    }
    std::cout << "(null)" << std::endl;
  }

  int get(int index) {
    if (index >= length) {
      return -1;
    }
    ListNode* current = head;
    /*for (int i = 0; i < index; i++) {*/
    /*    printf("here\n");*/
    /*    current = current->next;*/
    /*}*/
    return current->value;
  }

  void insertHead(int val) {
    ListNode* new_node = new ListNode(val);
    // Point to the existing start of the list
    new_node->next = head;
    // Point the head of the list to the new node
    head = new_node;
    this->length++;
  }

  void insertTail(int val) {
    if (head == nullptr) {
      head = new ListNode(val);
    } else {
      // Go to end
      ListNode* current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = new ListNode(val);
    }
  }

  bool remove(int index) {
    if (this->length <= index) {
      return false;
    }

    ListNode* current = head;
    // Go to node before index
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    // Want to remove the next node in the list
    // current -> [ keep node ] -> [ node to remove ] -> [ some other node ]
    // current -> [ keep node ] -> -> [ some other node or nullptr ]
    // Could put keep nodes value in to next node 
    ListNode* node_to_delete = current->next;
    if (current->next != nullptr) {
      current->next = current->next->next;
    }
    delete node_to_delete;
    this->length--;
    this->print();
    return true;
  }

  vector<int> getValues() {
    vector<int> results;
    ListNode* current = head;
    while (current != nullptr) {
      results.push_back(current->value);
      current = current->next;
    }
    return results;
  }
};


/*

needs:
* Head pointer to keep track of elements
* No run time constraints
* InsertHead adds new element to head
* Need count to track number of elements

list = head->[0]->[1]->[2]
list = head->[0]->[2]
*/

int main (int argc, char *argv[]) {
  LinkedList list;
  list.insertTail(1);
  list.insertTail(2);
  list.get(1);
  return 0;
}
