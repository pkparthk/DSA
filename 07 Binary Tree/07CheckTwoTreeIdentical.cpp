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

bool CheckIdentical(TreeNode*p, TreeNode *q){
    if (p==NULL || q==NULL)
    {
        return (p==q);
    }
    return (p->val == q->val) && CheckIdentical(p->left, q->left) && CheckIdentical(p->right, q->right);
}


int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode*root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout<<CheckIdentical(root, root2);
    return 0;
}