#include<iostream>
using namespace std;
class Node{
    public:
     int data;
     Node *left;
     Node *right;
     int height;
     Node(int value){
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
     }
};
int getheight(Node *root){
    if(!root){
        return 0;
    }
    return root->height;
}
int getbalance(Node *root){
    int bf = getheight(root->left) - getheight(root->right);
    return bf;
    
}
Node* right_rotation(Node *root){
    Node *child = root->left;
    Node *childright = child->right;
    child->right = root;
    root->left = childright;
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    child->height = 1 + max(getheight(child->left),getheight(child->right));
    return child; 
}
Node* left_rotation(Node *root){
    Node *child = root->right;
    Node *childleft = child->left;
    child->left = root;
    root->right = childleft;
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    child->height = 1 + max(getheight(child->left),getheight(child->right));
    return child;
    

}
Node* insertToAVL(Node *root,int key){

    //root doesn't exist
    if(!root){
        return new Node(key);
    }

    //root exist
    //1.left side
    if(root->data > key){
        root->left = insertToAVL(root->left,key);
    }
    //2. right side 
    else if(root->data < key){
        root->right = insertToAVL(root->right,key);
    }
    else{//3. agar (root->data == key) ka hua toh hum duplicate value insert nahi kareyenge root return kar denge
        return root;
    }


    //insert hone ke baad root ke height ko update kar denge
    root->height = 1 + max(getheight(root->left),getheight(root->right));

    //ab balance factor nikalna hoga har node ka ki balance hai ya nahi
    int balance = getbalance(root);

    //ab dekhna hai unbalance hai ya nahi
    //1. LL case
    //2. LR case
    //3. RR case
    //4. RL case
    //5. balance
    
    //agar balance > 1 => left side unbalance
    //  left left(LL) => balance > 1 && key < root->left->data;
    //  left right(LR)=> balance > 1 && key > root->left->data

    
    //LL case =>jab LL case hoga => right rotation karenge (top) per
    if(balance > 1 && key < root->left->data){ 
       return right_rotation(root);
    }
    //LR case =>jab LR case hoga => 1. left roation karenge middle per ,
                                    //2. right rotation karenge (top) per
    else if(balance > 1 && key > root->left->data)
    {                                                                          
        root->left = left_rotation(root->left);
        return right_rotation(root);                                                                      
    }
    //RR case =>jab RR case hoga => left rotation karenge (top) per
    else if(balance < -1 && key > root->right->data){ 
       return left_rotation(root);
    }
    //RL case =>jab RL case hoga => 1. right roation karenge middle per ,
                                  //2. left rotation karenge (top) per
    else if(balance < -1 && key < root->right->data)
    {                                                                         
        root->right =  right_rotation(root->right);
        return left_rotation(root);                                                                      
    }
    else{
        return root;
    }


}

void preorder(Node *root){
   if(!root){
    return;
   }   
   cout<<root->data<<" , ";
   preorder(root->left);
   preorder(root->right);
}

void inorder(Node *root){
   if(!root){
    return;
   }   
   
   inorder(root->left);
   cout<<root->data<<" , ";
   inorder(root->right);
}


int main(){
    //duplicate elements are not allowed
    Node *root = NULL;
    root = insertToAVL(root,21);
    root = insertToAVL(root,26);
    root = insertToAVL(root,30);
    root = insertToAVL(root,9);
    root = insertToAVL(root,4);
    root = insertToAVL(root,14);
    root = insertToAVL(root,28);
    root = insertToAVL(root,18);
    root = insertToAVL(root,15);
    root = insertToAVL(root,10);

    preorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;






    return 0;
}