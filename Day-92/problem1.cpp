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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        if (!head->next) return true;

        while (fast->next && fast->next->next) { // finding middle of linked list 
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr, *curr = slow->next, *temp;

        while (curr != nullptr) { // reversing the linked list after the middle node
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        slow->next = prev; // joining the reversed linked list after the middle node
        ListNode* start = head, *mid = slow->next;

        while (mid) { // values being checked here
            if (start->val != mid->val) return false;
            start = start->next;
            mid = mid->next;
        }
        return true;
    }
};

int main() {
    // Example usage for isPalindrome function
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    bool isPalin = solution.isPalindrome(head);

    if (isPalin) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
