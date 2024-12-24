#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            std::vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val); // Collect the value of the current node

                // Add children to the queue
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(level); // Store the current level
        }

        return ans;
    }
};

int main()
{
    // Constructing the example tree: [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    std::vector<std::vector<int>> result = solution.levelOrder(root);

    // Output the result
    std::cout << "Level Order Traversal: \n";
    for (const auto &level : result)
    {
        std::cout << "[ ";
        for (int val : level)
        {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    }

    // Clean up memory
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
