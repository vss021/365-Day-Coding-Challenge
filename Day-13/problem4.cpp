#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    int capacity;
    vector<int> data;

public:
    Stack(int capacity) : capacity(capacity) {
        // Initialize the stack with the given capacity
        data.reserve(capacity);
    }

    void push(int num) {
        // Push the given number if the stack is not full
        if (!isFull()) {
            data.push_back(num);
            cout << "Pushed: " << num << endl;
        } else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }

    int pop() {
        // Remove and print the top element from the stack if present, else print -1
        if (!isEmpty()) {
            int topElement = data.back();
            data.pop_back();
            cout << "Popped: " << topElement << endl;
            return topElement;
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
    }

    int top() {
        // Print the top element of the stack if present, else print -1
        if (!isEmpty()) {
            cout << "Top: " << data.back() << endl;
            return data.back();
        } else {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
    }

    int isEmpty() {
        // Print 1 if the stack is empty, else print 0
        cout << "isEmpty: " << (data.empty() ? 1 : 0) << endl;
        return data.empty() ? 1 : 0;
    }

    int isFull() {
        // Print 1 if the stack is full, else print 0
        cout << "isFull: " << (data.size() == capacity ? 1 : 0) << endl;
        return data.size() == capacity ? 1 : 0;
    }
};

int main() {
    // Example usage
    Stack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.top();
    myStack.pop();
    myStack.pop();
    myStack.isEmpty();
    myStack.isFull();

    return 0;
}
