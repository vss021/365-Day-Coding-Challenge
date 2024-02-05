#include <iostream>

// Assuming your Node structure looks like this
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            return head;
        }

        Node* lastNode = head;

        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        // Insert at the beginning
        if (head->data >= data) {
            newNode->next = head;
            lastNode->next = newNode;
            return newNode;
        }

        // Insert in the middle
        Node* curr = head;

        while (curr->next != head) {
            Node* forward = curr->next;

            if (curr->data <= data && forward->data > data) {
                curr->next = newNode;
                newNode->next = forward;
                return head;
            }

            curr = forward;
        }

        // Insert at the end
        if (lastNode->data <= data) {
            lastNode->next = newNode;
            newNode->next = head;
        }

        return head;
    }
};

int main() {
    Solution solution;

    // Test cases
    Node* head = nullptr;

    head = solution.sortedInsert(head, 5);
    head = solution.sortedInsert(head, 3);
    head = solution.sortedInsert(head, 8);
    head = solution.sortedInsert(head, 1);

    // Print the sorted list
    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    return 0;
}
