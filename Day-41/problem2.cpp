#include <iostream>
#include <string>
using namespace std;

// Definition for a Trie Node.
struct TrieNode {
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isLeaf = false;
    }
};

class Solution {
public:
    // Function to insert a string into the Trie.
    void insert(TrieNode* root, const string& key) {
        // Base case
        if (key.empty()) {
            root->isLeaf = true;
            return;
        }

        int index = key[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) { // Node is present
            child = root->children[index];
        } else { // Node is absent
            child = new TrieNode();
            root->children[index] = child;
        }

        // Recursion
        insert(child, key.substr(1));
    }

    // Function to search for a string in the Trie.
    bool search(TrieNode* root, const string& key) {
        // Base case
        if (key.empty()) {
            return root->isLeaf;
        }

        int index = key[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) { // Node is present
            child = root->children[index];
        } else { // Node is absent
            return false;
        }

        // Recursion
        return search(child, key.substr(1));
    }
};

int main() {
    // Example usage
    Solution solution;
    TrieNode* root = new TrieNode();

    solution.insert(root, "apple");
    cout << "Search for 'app': " << (solution.search(root, "app") ? "Found" : "Not Found") << endl;
    cout << "Search for 'apple': " << (solution.search(root, "apple") ? "Found" : "Not Found") << endl;

    return 0;
}
