#include <iostream>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;
        }

        return prev;
    }
};

int main() {
    // Example usage for reverseList function
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedList = solution.reverseList(head);

    cout << "Reversed list: ";
    while (reversedList) {
        cout << reversedList->val << " ";
        reversedList = reversedList->next;
    }
    cout << endl;

    return 0;
}
