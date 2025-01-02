#include <bits/stdc++.h>
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

// Brute Force Approach

// Function prototypes
// vector<vector<int>> levelOrder(Node *root);

// vector<int> rightView(Node *root)
// {
//     vector<int> result;
//     vector<vector<int>> levelTraversal = levelOrder(root);
//     for (auto x : levelTraversal)
//     {
//         result.push_back(x.back()); // Add the last element of each level
//     }
//     return result;
// }

// vector<int> leftView(Node *root)
// {
//     vector<int> result;
//     vector<vector<int>> levelTraversal = levelOrder(root);
//     for (auto x : levelTraversal)
//     {
//         result.push_back(x.front()); // Add the first element of each level
//     }
//     return result;
// }

// vector<vector<int>> levelOrder(Node *root)
// {
//     vector<vector<int>> result;
//     if (root == NULL)
//     {
//         return result;
//     }
//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> level;
//         for (int i = 0; i < size; i++)
//         {
//             Node *current = q.front();
//             q.pop();
//             level.push_back(current->data);
//             if (current->left != NULL)
//             {
//                 q.push(current->left);
//             }
//             if (current->right != NULL)
//             {
//                 q.push(current->right);
//             }
//         }
//         result.push_back(level);
//     }
//     return result;
// }



// Optimized Approach
void recursionRight(Node *root, int level, vector<int> &res);
void recursionLeft(Node *root, int level, vector<int> &res);
vector<int> rightView(Node *root)
{
    vector<int> res;
    recursionRight(root, 0, res);
    return res;
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    recursionLeft(root, 0, res);
    return res;
}

void recursionLeft(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    recursionLeft(root->left, level + 1, res);
    recursionLeft(root->right, level + 1, res);
}

void recursionRight(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    recursionRight(root->right, level + 1, res); // Right child first
    recursionRight(root->left, level + 1, res);  // Then left child
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Right View
    vector<int> result = rightView(root);
    cout << "Right View: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Left View
    result = leftView(root);
    cout << "Left View: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}