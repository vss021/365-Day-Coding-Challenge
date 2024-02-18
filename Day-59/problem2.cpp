#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*You are required to complete below method */
    int sumOfLeafNodes(Node *root ){
         /*Your code here */
         
        int sum=0;
        
        while (root)  
        {  
              
            if (root->left == NULL)  {  
                
                if(root->right==NULL)sum+=root->data;
                root = root->right;  
            }  
            else
            {  
                
                Node* current = root->left;  
                while (current->right && current->right != root)  
                    current = current->right;  
      
                
                if (current->right == root)  
                {  
                    current->right = NULL;  
                    if(current->left==NULL)sum+=current->data;
                    root = root->right;  
                }  
      
                else
                {  
                    current->right = root;  
                    root = root->left;  
                }  
            }  
        }  
    return sum;
    }
};

// Main function
int main() {
    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Create an instance of the Solution class
    Solution solution;

    // Call the sumOfLeafNodes method and print the result
    cout << "Sum of leaf nodes: " << solution.sumOfLeafNodes(root) << endl;

    return 0;
}
