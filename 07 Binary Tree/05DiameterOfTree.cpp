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

// Brute Force

// int diameter = 0;

// int calculateDiameter(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int leftHeight = calculateDiameter(root->left);
//     int rightHeight = calculateDiameter(root->right);

//     diameter = max(diameter, leftHeight + rightHeight);

//     return 1 + max(leftHeight, rightHeight);
// }

// int diameterOfBT(TreeNode*root){
//     calculateDiameter(root);
//     return diameter;
// }



// Optimized

int height(TreeNode*root, int &diameter){
    if (!root)
    {
        return 0;
    }
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBT(TreeNode*root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << diameterOfBT(root) << endl;
    return 0;
}