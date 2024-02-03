#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define the Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Solution class definition
class Solution {
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list 
    long long unsigned int decimalValue(Node *head)
    {
       // Your Code Here
       int mod = 1e9+7;
       
       long long unsigned int result = 0;
       
       while(head != NULL)
       {
           result = (result * 2 + head->data) % mod;
           head = head->next;
       }
       
       return result;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create a sample linked list: 1 -> 0 -> 1
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);

    // Call the decimalValue method
    long long unsigned int result = solution.decimalValue(head);

    // Display the result
    cout << "Decimal equivalent modulo 1000000007: " << result << endl;

    // Clean up: delete the linked list nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
