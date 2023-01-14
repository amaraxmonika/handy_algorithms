#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head=head->next;
    }
    cout << "NULL" << endl;
}

// Returns a pointer to the middle of the linked list
ListNode* middleNode(ListNode* head) {
    ListNode* slowPtr = head;
    int count = 1;
    while (head) {
        if (count % 2 == 0) {
            slowPtr = slowPtr->next;
        } 
        head = head->next;
        count++;
    }

    return slowPtr;
}

int main() {
    // construct list
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 1; i < 10; i++) {
        current->next = new ListNode(i+1);
        current = current->next;
    }
    printList(head);
    ListNode* middle = middleNode(head);
    printList(middle);
    return 0;
}
