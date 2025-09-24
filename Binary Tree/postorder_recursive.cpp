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

// Iterative Postorder Traversal
 void postOrder(Node* root,vector<int> &ans) {
        // code here
       if(!root){
        return;
       }  
       postOrder(root->left,ans);
        postOrder(root->right,ans);
       ans.push_back(root->data);
      
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
     postOrder(root,result);

    cout << "PostOrder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // cleanup allocated memory
    // (optional for this small example)
    return 0;
}
