#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    Node* insertionSort(Node* head_ref) {
        // Create a dummy node to simplify insertion at the beginning
        Node* result = new Node(-1);
        Node* current = head_ref;

        while (current) {
            // Reset temp to the dummy node for each iteration
            Node* temp = result;

            // Find the correct position to insert the current node
            while (temp->next && current->data >= temp->next->data) {
                temp = temp->next;
            }

            // Insert the current node into the sorted part of the list
            Node* nextNode = temp->next;
            temp->next = current;
            current = current->next;
            temp->next->next = nextNode;
        }

        // Skip the dummy node and return the sorted list
        return result->next;
    }
};


int main() {
    // Create an unsorted linked list: 3 -> 1 -> 4 -> 2
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);

    // Display the original linked list
    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Create an instance of the Solution class
    Solution solution;

    // Sort the linked list using insertion sort
    Node* sortedList = solution.insertionSort(head);

    // Display the sorted linked list
    cout << "Sorted Linked List: ";
    temp = sortedList;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Clean up the allocated memory
    while (head) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}
