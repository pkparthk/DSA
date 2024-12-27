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

int maxPathDown(TreeNode *root, int& maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, (left + right + root->val));
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode*root){
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<maxPathSum(root);
    return 0;
}