#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root->next = head;
        unordered_map<int, ListNode*> um;
        um[0] = root;
        int ac = 0;
        
        while (head != NULL) {
            ac += head->val;
            
            // Found value
            if (um.find(ac) != um.end()) {
                ListNode* prev = um[ac];
                ListNode* start = prev;
                
                // Delete bad references
                int aux = ac;
                while (prev != head) {
                    prev = prev->next;
                    aux += prev->val;
                    if (prev != head) um.erase(aux);
                }
                
                start->next = head->next;
            } else {
                um[ac] = head;
            }
            
            head = head->next;
        }
        
        return root->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);
    ListNode* result = sol.removeZeroSumSublists(head);
    cout << "Result: ";
    printList(result);

    return 0;
}
