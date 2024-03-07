#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Brute force approach
    ListNode* middleNodeBruteForce(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        int mid = length / 2;
        current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }

        return current;
    }

    // Optimized approach
    ListNode* middleNodeOptimized(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow by one step and fast by two steps
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {
    // Test Solution::middleNodeBruteForce
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* middleBruteForce = sol.middleNodeBruteForce(head);
    cout << "Middle node value (brute force): " << middleBruteForce->val << endl;

    // Test Solution::middleNodeOptimized
    ListNode* middleOptimized = sol.middleNodeOptimized(head);
    cout << "Middle node value (optimized): " << middleOptimized->val << endl;

    return 0;
}
