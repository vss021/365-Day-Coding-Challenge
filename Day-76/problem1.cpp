#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Method 1: Floyd's Tortoise and Hare Algorithm
    // Time Complexity: O(n), where n is the number of nodes in the linked list.
    // Space Complexity: O(1)
    bool hasCycle1(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }

    // Method 2: Hash Set
    // Time Complexity: O(n), where n is the number of nodes in the linked list.
    // Space Complexity: O(n)
    bool hasCycle2(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.find(head) != visited.end()) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }

        return false;
    }

    // Method 3: Two Pointer (Without Modifying the List)
    // Time Complexity: O(n), where n is the number of nodes in the linked list.
    // Space Complexity: O(1)
    bool hasCycle3(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Example usage:
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    cout << "Cycle detection using Floyd's Tortoise and Hare Algorithm: " << solution.hasCycle1(head) << endl;
    cout << "Cycle detection using Hash Set: " << solution.hasCycle2(head) << endl;
    cout << "Cycle detection using Two Pointer (Without Modifying the List): " << solution.hasCycle3(head) << endl;

    // Free memory
    ListNode *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
