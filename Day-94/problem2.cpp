#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> ans;

        // getting a reversed input in the new stack
        while (!st.empty()) {
            int k = st.top();
            st.pop();
            ans.push(k);
        }

        // adding the required element to insert
        st.push(x);

        // pushing the reversed stack and getting the required output
        while (!ans.empty()) {
            int k = ans.top();
            ans.pop();
            st.push(k);
        }

        return st;
    }
};

int main() {
    // Example usage for insertAtBottom function
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    int x = 4; // Element to insert at the bottom

    Solution solution;
    stack<int> modifiedStack = solution.insertAtBottom(st, x);

    cout << "Modified Stack: ";
    while (!modifiedStack.empty()) {
        cout << modifiedStack.top() << " ";
        modifiedStack.pop();
    }
    cout << endl;

    return 0;
}
