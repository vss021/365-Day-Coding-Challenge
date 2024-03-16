#include <iostream>

using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node* del_node) {
        if (del_node == nullptr || del_node->next == nullptr) {
            return;
        }
        Node* temp = del_node->next;
        del_node->data = temp->data;
        del_node->next = temp->next;
        delete temp;
    }
};

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Solution solution;
    Node* del_node = head->next; // Assuming del_node points to the node to be deleted (e.g., 2 in this case)
    solution.deleteNode(del_node);

   
}