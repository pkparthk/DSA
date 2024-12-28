#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node* root){
    return !root->left && !root->right;
}

void addLeftBoundary(Node *root, vector<int> &res){
    Node *curr=root->left;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}

void addRightBoundary(Node*root, vector<int> &res){
    Node *curr=root->right;
    vector<int> temp;
    while(curr!=NULL){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

void addLeaves(Node*root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left){
        addLeaves(root->left, res);
    }
    if(root->right){
        addLeaves(root->right, res);
    }    
}

vector<int> boundaryTraversal(Node*root){
    vector<int> res;
    if(!isLeaf(root)){
        res.push_back(root->data);
    }
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}


int main(){
    Node*root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);
    vector<int> res = boundaryTraversal(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}