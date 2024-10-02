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

// Brute Force By Mapping hashing

// int LengthOfLoop(Node *head){
//     unordered_map<Node *, int> visitedNodes;
//     Node *temp = head;
//     int timer = 0;
//     while (temp!=NULL)
//     {
//         if (visitedNodes.find(temp)!=visitedNodes.end()){
//             int loopLength = timer - visitedNodes[temp];
//             return loopLength;
//         }
//         visitedNodes[temp] = timer;
//         temp = temp->next;
//         timer++;
//     }    
//     return 0;
// }


// Optimised
// By Tortoise and Hare Method

int LengthOfLoop(Node*head){
    Node *slow = head;
    Node *fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            int LoopLength = 1;
            slow = slow->next;
            while (slow!=fast)
            {
                slow = slow->next;
                LoopLength++;
            }
            return LoopLength;
        }            
    }
    return 0;
}

int main()
{
    // Create a sample linked
    // list with a loop

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // This creates a loop
    fifth->next = second;    

    int loopLength = LengthOfLoop(head);
    if (loopLength > 0)
    {
        cout << "Length of the loop: " << loopLength << endl;
    }
    else
    {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}