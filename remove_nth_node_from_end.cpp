
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

ListNode* removeNthNodeFromEnd(ListNode* head, int n) {
    // Dummy node takes care of weird cases when the list is
    // either empty or has a single node.
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move the 'first' ahead of 'second' by n places.
    for (int i = 1; i <= n + 1; i++) {
        first = first->next;
    }

    // Now we can simply move both pointers at the same time
    // since second will consistently be n steps behind first.
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    // Important here that we don't return head. It is possible that
    // head was pointing to the node that was removed. 
    return dummy->next;
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
    ListNode* result = removeNthNodeFromEnd(head, 3);
    printList(result);
    return 0;
}
