#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};


// Brute Force

// Node *cloneLL(Node *head){
//     Node *temp = head;
//     unordered_map<Node *, Node *> mpp;
//     while (temp!=NULL)
//     {
//         Node *newNode = new Node(temp->data);
//         mpp[temp] = newNode;
//         temp = temp->next;        
//     }
//     temp = head;
//     while (temp!=NULL)
//     {
//         Node *copyNode = mpp[temp];
//         copyNode->next = mpp[temp->next];
//         copyNode->random = mpp[temp->random];
//         temp = temp->next;        
//     }    
//     return mpp[head];
// }


// Optimised 

Node*InsertCopyInBtw(Node*head){
    Node *temp = head;
    while (temp!=NULL)
    {
        Node *newElement = temp->next;
        Node *copy = new Node(temp->data);
        copy->next = newElement;
        temp->next = copy;
        temp = newElement;    
    }    
    return head;    
}

void connectRandom(Node *head){
    Node *temp = head;
    while (temp!=NULL)
    {
        Node *copyNode = temp->next;
        if (temp->random)
        {
            copyNode->random = temp->random->next;
        }
        else
        {
            copyNode->random = NULL;
        }
        temp = copyNode->next;                
    }        
}

Node*getDeepCopyList(Node*head){
    Node *temp = head;
    Node *dummy = new Node(-1);
    Node *res = dummy;
    while (temp!=NULL)
    {
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;                
    }
    return dummy->next;    
}

Node *cloneLL(Node *head){
    if (head==NULL)
    {
        return NULL;
    }
    InsertCopyInBtw(head);
    connectRandom(head);
    return getDeepCopyList(head);
}

void printClonedLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << "Data: " << head->data;
        if (head->random != nullptr)
        {
            cout << ", Random: " << head->random->data;
        }
        else
        {
            cout << ", Random: nullptr";
        }
        cout << endl;
        // Move to the next node
        head = head->next;
    }
}

int main()
{
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node *head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node *clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}