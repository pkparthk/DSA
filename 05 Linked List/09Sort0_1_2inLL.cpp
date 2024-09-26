#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1) : data(data1), next(next1) {}
    Node(int data1) : data(data1), next(nullptr) {}
};

// Converts an array to a linked list
Node *ConvertArrToLL(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Prints the linked list
void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Sorts the linked list containing 0s, 1s, and 2s
Node *Sort0_1_2(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *zeroHead = new Node(-1); // Dummy node for 0s
    Node *oneHead = new Node(-1);  // Dummy node for 1s
    Node *twoHead = new Node(-1);  // Dummy node for 2s

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Connect the three lists
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next; // Connect 0s to 1s or 2s
    one->next = twoHead->next;                                    // Connect 1s to 2s
    two->next = nullptr;                                          // Ensure the last node points to nullptr

    // Clean up dummy nodes
    Node *sortedHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return sortedHead; // Return the new head of the sorted list
}

// Clean up linked list to prevent memory leak
void deleteList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0, 2, 1, 0, 2};
    Node *head = ConvertArrToLL(arr);
    print(head); // Print original list
    head = Sort0_1_2(head);
    print(head); // Print sorted list

    // Clean up the linked list
    deleteList(head);
    return 0;
}
