#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int num;
    Node *next;
    Node(int a)
    {
        num = a;
        next = NULL;
    }
};


void insertNode(Node *&head, int val)
{
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

void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
    return;
}


// Brute Force
// Node *RotateLL(Node*head, int k){
//     while (head==NULL || head->next==NULL)
//     {
//         return head;
//     }
//     for (int i = 0; i < k; i++)
//     {
//         Node *temp = head;
//         while (temp->next->next!=NULL)
//         {
//             temp = temp->next;
//         }
//         Node *newNode = temp->next;
//         temp->next = NULL;
//         newNode->next = head;
//         head = newNode;            
//     }
//     return head;    
// }


// Optimized

Node *findNthNode(Node*temp, int k){
    int cnt = 1;
    while (temp!=NULL)
    {
        if (cnt==k)
        {
            return temp;
        }
        temp = temp->next;
        cnt++;                
    }
    return temp;    
}

Node *RotateLL(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (k%count==0)
    {
        return head;
    }    
    k = k % count;
    temp->next = head;
    Node *newTail = findNthNode(head, count - k);
    head = newTail->next;
    newTail->next = NULL;    
    return head;
}


int main()
{
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);
    insertNode(head, 9);
    insertNode(head, 10);
    cout << "Before Rotate: " << endl;
    printList(head);    
    head = RotateLL(head, 3);
    cout << "After Rotate: " << endl;
    printList(head);
    return 0;
}