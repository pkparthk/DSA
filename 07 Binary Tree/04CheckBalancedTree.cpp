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

// class Solution
// {
// public:
//     bool isBalanced(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return true;
//         }

//         int lh = height(root->left);
//         int rh = height(root->right);

//         if (abs(rh-lh)>1)
//         {
//             return false;
//         }

//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);

//         if (!left || !right)
//         {
//             return false;
//         }
//         return true;
//     }

//     int height(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }

//         int lh = height(root->left);
//         int rh = height(root->right);

//         return max(lh, rh) + 1;
//     }
// };


// Optimized

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

    int height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int lh = height(root->left);
        if (lh == -1)
        {
            return -1;
        }

        int rh = height(root->right);
        if (rh == -1)
        {
            return -1;
        }

        if (abs(rh - lh) > 1)
        {
            return -1;
        }

        return max(lh, rh) + 1;
    }
};



int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);

    Solution s;
    cout << s.isBalanced(root) << endl;
    return 0;
}