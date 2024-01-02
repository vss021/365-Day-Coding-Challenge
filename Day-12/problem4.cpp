#include <iostream>
#include <stack>

using namespace std;

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    // Write your code here.
    vector<int> v;

    // Pop elements from the original stack and store them in a vector
    while (!myStack.empty()) {
        v.push_back(myStack.top());
        myStack.pop();
    }

    // Push the new element to the bottom of the stack
    myStack.push(x);

    // Push the elements from the vector back to the stack
    for (int i = v.size() - 1; i >= 0; i--) {
        myStack.push(v[i]);
    }

    return myStack;
}

int main() {
    // Create a stack
    stack<int> myStack;

    // Push elements to the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Display the original stack
    cout << "Original Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Use pushAtBottom function to add a new element at the bottom
    int x = 5;
    myStack = pushAtBottom(myStack, x);

    // Display the modified stack
    cout << "Modified Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
