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

int addHelper(Node*head){
    if(head == nullptr){
        return 1;
    }
    int carry = addHelper(head->next);
    head->data += carry;
    if(head->data<10){
        return 0;
    }
    head->data = 0;
    return 1;
}


Node* Add1ToLL(Node*head){
    int caary = addHelper(head);
    if (caary==1)
    {
        Node *newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;    
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *head = ConvertArrToLL(arr);
    print(head);
    head = Add1ToLL(head);
    print(head);
    return 0;
}