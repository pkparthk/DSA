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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Brute Force
// Node *RemoveNodeFromEnd(Node*head, int n){
//     if(head == nullptr){
//         return nullptr;
//     }
//     int cnt = 0;
//     Node *temp = head;
//     while(temp!=nullptr){
//         cnt++;
//         temp = temp->next;
//     }
//     if(cnt==n){
//         Node *newHead = head->next;
//         delete head;
//         return newHead;
//     }
//     int res = cnt - n;
//     temp = head;
//     while (temp!=NULL)
//     {
//         res--;
//         if(res==0){
//             break;
//         }
//         temp = temp->next;
//     }
//     Node *delNode = temp->next;
//     temp->next = delNode->next;
//     delete delNode;
//     return head;    
// }


// Optimized

Node *RemoveNodeFromEnd(Node *head, int n)
{
    if (head == nullptr){
        return nullptr;
    }
    Node *fast = head;
    for (int i = 0; i < n; i++)
    {
        
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        return head->next;
    }
    Node *slow = head;
    while (fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;        
    }
    Node *delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = ConvertArrToLL(arr);
    print(head);
    head = RemoveNodeFromEnd(head, 2);
    print(head);
    return 0;
}