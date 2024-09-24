#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *back;

        Node(int data1, Node *next1, Node *back1)
        {
            data = data1;
            next = next1;
            back = back1;
        }
        Node(int data1)
        {
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node *convertArr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != nullptr)
    {    
        cout << head->data << " ";
        head = head->next;
    }
}

Node *Sum2No(Node *head1, Node *head2){
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int carry = 0;
    while (temp1!=NULL || temp2!=NULL)
    {
        int sum = carry + (temp1!=NULL?temp1->data:0) + (temp2!=NULL?temp2->data:0);
        carry = sum/10;
        sum = sum%10;
        Node *newNode = new Node(sum);
        curr->next = newNode;
        curr = curr->next;
        if (temp1!=NULL)
        {
            temp1 = temp1->next;
        }
        if (temp2!=NULL)
        {
            temp2 = temp2->next;
        }
    }
    if (carry>0)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
        curr = curr->next;
    }
    return dummy->next;
}


int main()
{
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5};
    Node *head1 = convertArr2DLL(arr1);
    Node *head2 = convertArr2DLL(arr2);
    Node *head = Sum2No(head1, head2);
    print(head);
    return 0;
}