//This is code for create bt using recursion
#include<iostream>
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

Node *create_tree(){
    int x;
    cin>>x;
    if(x == -1){
        return NULL;
    }
    Node* temp = new Node(x);
    temp->left = create_tree();
    temp->right = create_tree();
    return temp;
}

void preorder(Node *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ,";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    //int arr[] = {95,46,15,78,23,87,2,30,58};
    Node *root = create_tree();



    cout<<"Preorder Traversal:\n";
    preorder(root);
    cout<<endl;

    return 0;
}