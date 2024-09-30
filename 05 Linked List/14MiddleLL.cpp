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


// Node*findMiddle(Node*head){
//     if (head==NULL || head->next==NULL)
//     {
//         return head;
//     }
//     Node *temp = head;
//     int cnt = 0;
//     while (temp!=NULL)
//     {
//         cnt++;
//         temp = temp->next;
//     }
//     int mid = cnt / 2 + 1;
//     temp = head;
//     while (temp!=NULL)
//     {
//         mid = mid - 1;
//         if (mid==0)
//         {
//             break;
//         }
//         temp = temp->next;
//     }
//     return temp;
// }


// Tortoise and Hare Method

Node*findMiddle(Node*head){
    Node *slow = head;
    Node *fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    Node *mid = findMiddle(head);
    cout << mid->data << endl;
    return 0;
}