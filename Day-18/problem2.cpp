#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    // Constructor to initialize Node with data and next pointer
    Node(int val = 0, Node *nextPtr = nullptr) : data(val), next(nextPtr) {}
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;

        while (curr)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    Node *mergeResult(Node *node1, Node *node2)
    {
        if (!node1 && !node2)
            return nullptr;

        Node *head = new Node(); // dummy node to simplify code
        Node *prev = head;

        Node *revNode1 = reverse(node1);
        Node *revNode2 = reverse(node2);

        while (revNode1 && revNode2)
        {
            if (revNode1->data > revNode2->data)
            {
                prev->next = revNode1;
                prev = revNode1;
                revNode1 = revNode1->next;
            }
            else
            {
                prev->next = revNode2;
                prev = revNode2;
                revNode2 = revNode2->next;
            }
        }

        if (revNode1)
            prev->next = revNode1;
        else
            prev->next = revNode2;

        Node *result = head->next;
        delete head; // delete the dummy node

        return result;
    }
};

// Helper function to print linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    // Example usage
    Node *node1 = new Node(1, new Node(3, new Node(5)));
    Node *node2 = new Node(2, new Node(4, new Node(6)));

    cout << "List 1: ";
    printList(node1);

    cout << "List 2: ";
    printList(node2);

    Node *result = solution.mergeResult(node1, node2);

    cout << "Merged List: ";
    printList(result);

    // Don't forget to free memory if dynamic allocation is used
    delete node1;
    delete node2;
    delete result;

    // Case with one empty list
    Node *emptyList = nullptr;
    Node *resultEmpty = solution.mergeResult(emptyList, node2);

    cout << "Merged List with Empty List: ";
    printList(resultEmpty);

    // Don't forget to free memory for the empty list
    delete resultEmpty;

    return 0;
}
