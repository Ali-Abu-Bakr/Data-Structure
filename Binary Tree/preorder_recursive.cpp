#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Iterative Preorder Traversal
void preOrder(Node* root,vector<int> &ans) {
   
    if (!root) return ;  // handle empty tree
    ans.push_back(root->data);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
   
}

int main() {
    /*
        Construct the following tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Preorder (Root-Left-Right): 1 2 4 5 3 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> result; 
    preOrder(root,result);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // cleanup allocated memory
    // (optional for this small example)
    return 0;
}
