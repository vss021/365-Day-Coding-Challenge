#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Include the Solution class definition here

class Solution {
private:
    // Time Complexity: O(n log n) - sorting the array
    // Space Complexity: O(n) - using extra space for array
    ListNode* naiveApproach(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: empty list or single node
        }

        vector<int> arr;

        // Convert linked list to array
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        // Create a new sorted linked list from the sorted array
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;

        for (int i = 0; i < arr.size(); i++) {
            ListNode* temp = new ListNode(arr[i]);
            tail->next = temp;
            tail = tail->next;
        }

        return newHead->next;
    }

    // Time Complexity: O(n + m), where n and m are the lengths of l1 and l2 respectively
    // Space Complexity: O(1) - using constant extra space
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to hold the merged list
        ListNode* tail = &dummy; // Pointer to the tail of the merged list

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes, if any
        tail->next = l1 ? l1 : l2;
        return dummy.next; // Return the merged list (excluding the dummy node)
    }
    
    // Time Complexity: O(n) - traversing the list to find the middle node
    // Space Complexity: O(1) - using constant extra space
    ListNode* findMiddle(ListNode* front, ListNode* back) {
        if (front == back) {
            return front; // Base case: only one node in the list
        }
        ListNode* slow = front;
        ListNode* fast = front;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // Time Complexity: O(n log n), where n is the number of nodes in the list
    // Space Complexity: O(log n) - recursion stack space
    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return head; // Base case: only one node in the list
        }
        ListNode* mid = findMiddle(head, tail);
        ListNode* sortedSecondHalf = mergeSort(mid->next, tail);
        mid->next = nullptr; // Split the list into two halves
        ListNode* sortedFirstHalf = mergeSort(head, mid);
        return merge(sortedFirstHalf, sortedSecondHalf); // Merge the sorted halves
    }
    
public:
    // Time Complexity: O(n log n), where n is the number of nodes in the list
    // Space Complexity: O(log n) - recursion stack space
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: empty list or single node
        }
        // Find the tail of the list
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        // Perform merge sort on the list
        return mergeSort(head, tail);
    }
};


int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Instantiate the Solution class
    Solution solution;

    // Sort the linked list
    ListNode* sortedList = solution.sortList(head);

    // Print the sorted linked list
    cout << "Sorted Linked List: ";
    ListNode* current = sortedList;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Free memory
    current = sortedList;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
