
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

bool floydsCycleFindingAlgorithm(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}


int main() {
    // construct list
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 1; i < 10; i++) {
        current->next = new ListNode(i+1);
        current = current->next;
    }
    assert(floydsCycleFindingAlgorithm(head) == false);
    // add loop by connecting end of list to something in the middle
    current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    ListNode* middleIsh = head;
    for (int i = 0; i < 5; i++) {
        middleIsh = middleIsh->next;
    }
    // make a loop
    current->next = middleIsh;

    assert(floydsCycleFindingAlgorithm(head) == true);
    // now run floyds loop detection!
    return 0;
}

// Returns a pointer to the middle of the linked list
