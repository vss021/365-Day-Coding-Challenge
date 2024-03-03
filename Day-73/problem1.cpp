#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Brute-force approach
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEndBruteForce(ListNode* head, int n) {
        int length = getLength(head);
        if (n == length) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;
        for (int i = 0; i < length - n; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
        return head;
    }

    // Optimized approach
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i < n + 1; i++) {
            if (fast == nullptr)
                return nullptr; // Handle edge case where n is greater than length
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow points to the node just before the node to be removed
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    // Brute-force approach
    int n1 = 2;
    ListNode* newHead1 = solution.removeNthFromEndBruteForce(head, n1);

    cout << "After removing " << n1 << "th node from the end (Brute-force approach): ";
    ListNode* current1 = newHead1;
    while (current1 != nullptr) {
        cout << current1->val << " ";
        current1 = current1->next;
    }
    cout << endl;

    // Free memory
    current1 = newHead1;
    while (current1 != nullptr) {
        ListNode* temp = current1;
        current1 = current1->next;
        delete temp;
    }

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Optimized approach
    int n2 = 2;
    ListNode* newHead2 = solution.removeNthFromEnd(head, n2);

    cout << "After removing " << n2 << "th node from the end (Optimized approach): ";
    ListNode* current2 = newHead2;
    while (current2 != nullptr) {
        cout << current2->val << " ";
        current2 = current2->next;
    }
    cout << endl;

    // Free memory
    current2 
}