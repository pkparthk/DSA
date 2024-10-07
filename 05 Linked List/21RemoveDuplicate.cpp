#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *ConvertArrayToDLL(vector<int> &arr)
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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node*RemoveDuplice(Node*head){
    Node *temp = head;
    while (temp!=NULL && temp->next!=NULL)
    {
        Node *newNode = temp->next;
        while (newNode!=NULL && newNode->data==temp->data)
        {
            newNode = newNode->next;            
        }
        temp->next = newNode;
        if(newNode!=NULL){
            newNode->back = temp;
        }
        temp = temp->next;        
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
    Node *head = ConvertArrayToDLL(arr);
    print(head);
    head = RemoveDuplice(head);
    print(head);
    return 0;
}