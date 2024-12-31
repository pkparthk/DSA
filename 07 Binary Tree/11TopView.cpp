#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> topView(Node*root){
    vector<int> result;
    if (root==NULL)
    {
        return result;
    }
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node*current = p.first;
        int line=p.second;
        if (mpp.find(line)==mpp.end())
        {
            mpp[line] = current->data;
        }
        if (current->left)
        {
            q.push({current->left, line-1});
        }
        if (current->right)
        {
            q.push({current->right, line+1});
        }
    }
    for (auto x : mpp)
    {
        result.push_back(x.second);
    }
    return result;
}

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = topView(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}