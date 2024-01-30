#include <iostream>
#include <vector>
#include <stack>
#include <string>


using namespace std;

class Solution {
public:
    // Helper function to resolve operations
    long resolve(int a, int b, char op) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '*') return a * b;
        return a / b;
    }

    // Main function to evaluate Reverse Polish Notation (RPN) expression
    int evalRPN(vector<string>& tokens) {
        stack<long> stack;

        for (const string& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                // Operator encountered, pop operands, resolve, and push result
                long operand2 = stack.top(); stack.pop();
                long operand1 = stack.top(); stack.pop();
                char currentOperator = token[0];
                long resolvedResult = resolve(operand1, operand2, currentOperator);
                stack.push(resolvedResult);
            } else {
                // Operand encountered, push onto the stack
                stack.push(stol(token));
            }
        }

        // The final result is on top of the stack
        return stack.top();
    }
};


int main() {
    Solution solution;

    // Example RPN expression: "2 3 * 5 +"
    vector<string> tokens = {"2", "3", "*", "5", "+"};

    int result = solution.evalRPN(tokens);

    // Display the result of the RPN expression
    cout << "Result: " << result << endl;

    return 0;
}
