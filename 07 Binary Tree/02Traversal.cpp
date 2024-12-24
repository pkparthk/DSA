#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inOrder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left, result);
    result.push_back(root->data);
    inOrder(root->right, result);
}

void preOrder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
    {
        return;
    }
    result.push_back(root->data);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

void postOrder(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<int> inorderResult;
    vector<int> preorderResult;
    vector<int> postorderResult;

    inOrder(root, inorderResult);
    preOrder(root, preorderResult);
    postOrder(root, postorderResult);

    return {inorderResult, preorderResult, postorderResult};
}

// Example usage
int main()
{
    // Constructing a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Get the traversals
    vector<vector<int>> results = getTreeTraversal(root);

    // Output results
    cout << "In-Order Traversal: ";
    for (int val : results[0])
    {
        cout << val << " ";
    }
    cout << "\nPre-Order Traversal: ";
    for (int val : results[1])
    {
        cout << val << " ";
    }
    cout << "\nPost-Order Traversal: ";
    for (int val : results[2])
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
