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
 vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        stack<Node*> st;
        st.push(node);
        
        while(!st.empty()){
            Node *curr = st.top();
            st.pop();
            
            ans.push_back(curr->data);
            if(curr->left){
                st.push(curr->left);
            }
            if(curr->right){
                st.push(curr->right);
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
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

    vector<int> result = postOrder(root);

    cout << "PostOrder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // cleanup allocated memory
    // (optional for this small example)
    return 0;
}
