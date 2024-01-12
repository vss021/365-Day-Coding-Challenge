#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to reverse the first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // Add code here.

        // Use a stack to temporarily store the first k elements.
        stack<int> st;

        // Pop the first k elements from the queue and push them onto the stack.
        for (int i = 0; i < k; ++i) {
            st.push(q.front());
            q.pop();
        }

        // Create a new queue to store the reversed elements.
        queue<int> res;

        // Pop elements from the stack and push them into the new queue to reverse them.
        while (!st.empty()) {
            res.push(st.top());
            st.pop();
        }

        // Push the remaining elements from the original queue into the new queue.
        while (!q.empty()) {
            res.push(q.front());
            q.pop();
        }

        // Return the modified queue with the first k elements reversed.
        return res;
    }
};


int main() {
    // Create a queue and populate it with some elements.
    queue<int> myQueue;
    for (int i = 1; i <= 5; ++i) {
        myQueue.push(i);
    }

    // Create an instance of the Solution class.
    Solution solution;

    // Specify the number of elements to reverse (k).
    int k = 3;

    // Call the modifyQueue function to reverse the first k elements.
    queue<int> modifiedQueue = solution.modifyQueue(myQueue, k);

    // Display the original and modified queues.
    cout << "Original Queue: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    cout << "\nModified Queue: ";
    while (!modifiedQueue.empty()) {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }

    return 0;
}
