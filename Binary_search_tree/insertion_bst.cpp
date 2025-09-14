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

    cout<<"Preorder:\n";
    preorder(root);
    cout<<"\nInorder:\n";
    inorder(root);
    cout<<endl;

    return 0;
}