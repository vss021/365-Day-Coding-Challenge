#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove leading zeroes from a linked list
Node* removeLeadingZeroes(Node* head) {
    Node* temp = head;

    while (temp != nullptr && temp->data == 0) {
        temp = temp->next;
        head = temp;
    }

    return head;
}

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to determine which linked list has a bigger number
Node* findBigger(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data > temp2->data) {
            return head1;
        } else if (temp2->data > temp1->data) {
            return head2;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return (temp1 == nullptr) ? head2 : head1;
}

// Function to perform subtraction of two linked lists
Node* subtractLinkedLists(Node* head1, Node* head2) {
    head1 = removeLeadingZeroes(head1);
    head2 = removeLeadingZeroes(head2);

    if (head1 == nullptr && head2 == nullptr) {
        // If both linked lists contain only zeroes
        return new Node(0);
    }

    Node* result = nullptr;
    Node* biggerList = findBigger(head1, head2);

    if (biggerList == head1) {
        result = subtract(head1, head2);
    } else {
        result = subtract(head2, head1);
    }

    result = reverseLinkedList(result);
    result = removeLeadingZeroes(result);

    if (result == nullptr) {
        // If both numbers are the same
        return new Node(0);
    }

    return result;
}

// Function to perform subtraction of two linked lists with the assumption that the first list is bigger
Node* subtract(Node* head1, Node* head2) {
    Node* temp1 = reverseLinkedList(head1);
    Node* temp2 = reverseLinkedList(head2);
    int carry = 0;

    Node* result = new Node(-1);
    Node* finalResult = result;

    while (temp1 != nullptr && temp2 != nullptr) {
        int val1 = temp1->data - carry;
        carry = 0;
        int val2 = temp2->data;

        if (val1 >= val2) {
            result->next = new Node(val1 - val2);
        } else {
            result->next = new Node(val1 + 10 - val2);
            carry = 1;
        }

        result = result->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != nullptr) {
        int digit = temp1->data - carry;
        carry = (digit < 0) ? 1 : 0;
        digit = (digit < 0) ? digit + 10 : digit;

        result->next = new Node(digit);
        result = result->next;
        temp1 = temp1->next;
    }

    return finalResult->next;
}

// Function to print a linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    Node* l1 = new Node(7);
    l1->next = new Node(2);
    l1->next->next = new Node(4);

    Node* l2 = new Node(3);
    l2->next = new Node(2);

    Node* result = subtractLinkedLists(l1, l2);

    printLinkedList(result);

    return 0;
}
