#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data1, Node *next1)
        {
            data = data1;
            next = next1;
        }
        Node(int data1)
        {
            data = data1;
            next = nullptr;
        }
};

void insertNode(Node*&head, int val){
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Better Solution
// By Hashing method mapping

// bool detectLoop(Node *head){
//     Node *temp = head;
//     unordered_map<Node *, int> mpp;
//     while (temp!=NULL)
//     {
//         if (mpp.find(temp)!=mpp.end())
//         {
//             return true;
//         }
//         mpp[temp] = 1;
//         temp = temp->next;
//     }
//     return false;
// }



// Tortoise And Hare Method

bool detectLoop(Node *head){
    Node *slow = head;
    Node *fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}


// int main()
// {
//     Node *head = NULL;
//     int n;
//     cout << "Enter the number of nodes in the linked list: ";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int val;
//         cin >> val;
//         insertNode(head, val);
//     }
//     // creating a loop
//     head->next->next->next->next = head;

//     if (detectLoop(head))
//     {
//         cout << "Loop detected\n";
//     }
//     else
//     {
//         cout << "No loop detected\n";
//     }
//     return 0;
// }

int main()
{
    // Create a sample linked list
    // with a loop for testing

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third;

    // Check if there is a loop
    // n the linked list
    if (detectLoop(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;   
}