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

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Brute Force

Node *DeleteMiddle(Node *head){
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp!=NULL)
    {
        cnt++;
        temp = temp->next;        
    }
    int res = cnt / 2;
    temp = head;
    while (temp!=NULL)
    {
        res--;
        if (res == 0)
        {
            Node *middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Optimal Approach
// Tortoise and Hare method
Node *DeleteMiddleNode(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;   // TO skip one step of slow
    while (fast!=NULL && fast->next!=NULL)
    {        
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}


int main(){
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertNode(head, val);
    }
    printList(head);
    // head = DeleteMiddle(head);
    head = DeleteMiddleNode(head);
    printList(head);
    return 0;
}