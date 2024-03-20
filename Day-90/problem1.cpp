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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr = list1;
        for (int i = 0; i < a - 1; ++i)
            ptr = ptr->next;
        
        ListNode* qtr = ptr->next;
        for (int i = 0; i < b - a + 1; ++i)
            qtr = qtr->next;
        
        ptr->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = qtr;
        
        return list1;
    }
};

int main() {
    // Example usage for mergeInBetween function
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(10);
    list2->next = new ListNode(11);
    list2->next->next = new ListNode(12);

    Solution solution;
    ListNode* mergedList = solution.mergeInBetween(list1, 2, 4, list2);

    cout << "Merged list: ";
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
