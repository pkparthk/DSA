#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}    
};

vector<vector<int>> ZigZagLevelOrder(TreeNode *root){
    vector<vector<int>> result;
    if (root==NULL)
    {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> currentLevel(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            int index = leftToRight ? i : (size - 1 - i);
            currentLevel[index] = current->val;
            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }                                                          
        }
        leftToRight = !leftToRight;
        result.push_back(currentLevel);        
    }
    return result;    
}

int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = ZigZagLevelOrder(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}