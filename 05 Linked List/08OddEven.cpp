#include <bits/stdc++.h>
using namespace std;

class Node
{
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

Node *OddEven(Node *head){
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;
    while(even!=nullptr && even->next!=nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node *head = ConvertArrToLL(arr);
    print(head);
    cout<<endl;
    head = OddEven(head);
    print(head);
    return 0;
}