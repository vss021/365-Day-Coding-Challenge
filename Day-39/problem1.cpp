#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    // Using two stacks to implement a queue
    stack<int> inputStack;  // s1 in the original code
    stack<int> outputStack; // s2 in the original code

public:
    MyQueue() {}

    // Enqueue operation (pushing an element to the back of the queue)
    void push(int x) {
        // Move elements from inputStack to outputStack
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }

        // Push the new element to inputStack
        inputStack.push(x);

        // Move elements back from outputStack to inputStack
        while (!outputStack.empty()) {
            inputStack.push(outputStack.top());
            outputStack.pop();
        }
    }

    // Dequeue operation (removing and returning the front element of the queue)
    int pop() {
        // Retrieve and remove the front element from inputStack
        int temp = inputStack.top();
        inputStack.pop();
        return temp;
    }

    // Peek operation (get the front element without removing it)
    int peek() {
        // Return the front element from inputStack
        return inputStack.top();
    }

    // Check if the queue is empty
    bool empty() {
        return inputStack.empty();
    }
};

int main() {
    // Create a MyQueue object
    MyQueue myQueue;

    // Enqueue some elements
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Print the front element without removing it
    cout << "Front element: " << myQueue.peek() << endl;

    // Dequeue and print the elements
    while (!myQueue.empty()) {
        cout << "Dequeued: " << myQueue.pop() << endl;
    }

    // Check if the queue is empty
    if (myQueue.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
