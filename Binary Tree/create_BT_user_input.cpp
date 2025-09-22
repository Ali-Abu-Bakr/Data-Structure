//program to take input and create tree
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
     int data;
     Node *left;
     Node *right;
     Node(int value){
        data = value;
        left = NULL;
        right = NULL;
     }
  
};

void preorder(Node *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ,";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int x,left,right;
    queue<Node*> q;
    cout<<"Enter root Node:";
    cin>>x;
    Node *root = new Node(x);
    q.push(root);

    while(!q.empty()){
        Node *node = q.front();
        q.pop();

        cout<<"Enter left node of "<<node->data<<" :";
        cin>>left;
        if(left != -1){
            node->left = new Node(left);
            q.push(node->left);
        }

        cout<<"Enter right node of "<<node->data<<" :";
        cin>>right;
        if(right != -1){
            node->right = new Node(right);
            q.push(node->right);
        }

    }

    cout<<"Preorder Traversal:\n";
    preorder(root);
    cout<<endl;
    return 0;

}