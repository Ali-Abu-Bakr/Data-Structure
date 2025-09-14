#include<iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* right;
     Node *left;
     Node(int value){
        data = value;
        right = NULL;
        left = NULL;
     }
};

//deletion in bst
Node* deletion(Node* root, int target) {
    if (root == NULL) return NULL;

    if (target < root->data) {
        root->left = deletion(root->left, target);
    }
    else if (target > root->data) {
        root->right = deletion(root->right, target);
    }
    else {
        // Node found
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            // Find in-order predecessor (rightmost in left subtree)
            Node* parent = root;
            Node* child = root->left;
            while (child->right) {
                parent = child;
                child = child->right;
            }

            // Copy predecessor value to root
            root->data = child->data;

            // Delete the predecessor node
            if (parent == root)
                root->left = deletion(root->left, child->data);
            else
                parent->right = deletion(parent->right, child->data);
        }
    }
    return root;
}



Node *insert(Node *root,int key){
    if(!root){
        return new Node(key);
    }
    if(key < root->data){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }
    return root;
}
void preorder(Node *root){
    if(!root){
        return;
    }
     cout<<root->data<<",";
    preorder(root->left);
   
    preorder(root->right);
}

void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}





int main(){
    int arr[] = {9,5,4,6,1,5,7,8,2,3};
    Node *root = NULL;
    for(int i=0;i<10;i++){
        root = insert(root,arr[i]);
    }
    cout<<"Before delettion preorder and inorder:\n";
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    
    root = deletion(root,7);
    root = deletion(root,5);
    root = deletion(root,9);

    cout<<"After delettion preorder and inorder:\n";
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;


   
    cout<<endl;

    return 0;
}