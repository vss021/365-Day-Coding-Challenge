#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        
        while (head) {
            Node* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;
        }
        
        return prev;
    }

    Node* mergeTwoLinkLists(Node* head1, Node* head2) {
        if (!head1)
            return head2;

        if (!head2)
            return head1;

        Node* head = new Node(-1);
        Node* tail = head;

        while (head1 && head2) {
            if (head1->data < head2->data) {
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }

        if (!head1 && head2)
            tail->next = head2;

        if (!head2 && head1)
            tail->next = head1;

        return head->next;
    }

    void sort(Node** head) {
        Node* list1 = new Node(-1);
        Node* list1Tail = list1;

        Node* list2 = new Node(-1);
        Node* list2Tail = list2;

        bool isList = true;

        Node* current = *head;

        while (current) {
            if (isList) {
                Node* temp = new Node(current->data);
                list1Tail->next = temp;
                list1Tail = list1Tail->next;
            } else {
                Node* temp = new Node(current->data);
                list2Tail->next = temp;
                list2Tail = list2Tail->next;
            }

            isList = !isList;
            current = current->next;
        }

        list2 = reverse(list2->next);
        *head = mergeTwoLinkLists(list1->next, list2);
    }
};

// Helper function to print the linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create an instance of the Solution class
    Solution sol;

    // Sort the linked list
    sol.sort(&head);

    // Print the sorted linked list
    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
