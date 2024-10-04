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


// Brute Force

// Node* findStartingPtInLoop(Node* head){
//     Node *temp = head;
//     unordered_map<Node *, int> mpp;
//     while (temp!=NULL)
//     {
//         if (mpp.count(temp)!=0)
//         {
//             return temp;
//         }
//         mpp[temp] = 1;
//         temp = temp->next;                
//     }
//     return NULL;
// }


// Optimized Solution
Node* findStartingPtInLoop(Node* head){
    Node *slow = head;
    Node *fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }        
    }
    return NULL;
}


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
    Node *startingPt = findStartingPtInLoop(head);
    if (startingPt)
    {
        cout << "Loop detected in the linked list at " << startingPt->data << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }
    return 0;
}