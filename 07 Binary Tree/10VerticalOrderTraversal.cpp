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

vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while(!todo.empty()){
        auto p= todo.front();
        todo.pop();
        Node *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left){
            todo.push({node->left, {x-1, y+1}});
        }
        if(node->right){
            todo.push({node->right, {x+1, y+1}});
        }        
    }
    vector<vector<int>> result;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        result.push_back(col);
    }
    return result;    
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);
    vector<vector<int>> res = verticalTraversal(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}