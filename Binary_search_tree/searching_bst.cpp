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
//searching in bst //AC: O(log n) , WC: O(n)
bool search(Node *root,int target){
    if(!root){
        return false;
    }
    if(root->data == target){
        return true;
    }
    else if(root->data > target){
        return search(root->left,target);
    }
    else {
        return search(root->right,target);
    }
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





int main(){
    int arr[] = {9,5,4,6,1,5,7,8,2,3};
    Node *root = NULL;
    for(int i=0;i<10;i++){
        root = insert(root,arr[i]);
    }

    cout<<search(root,7);
    cout<<endl;

    return 0;
}