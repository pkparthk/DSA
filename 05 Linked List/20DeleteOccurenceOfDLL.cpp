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

Node *DeleteOccurenceOfDLL(Node*head, int key){
    Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        if (temp->data == key){
            if (temp==head)
            {
                head = head->next;
            }
            Node *prevNode = temp->back;
            Node *nextNode = temp->next;
            if (prevNode)
            {
                prevNode->next = nextNode;                
            }
            if (nextNode)
            {
                nextNode->back = prevNode;                
            }
            delete temp;
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }                
    }        
    return head;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *head = ConvertArrayToDLL(arr);
    int key;
    cin >> key;
    head = DeleteOccurenceOfDLL(head, key);
    print(head);
    return 0;
}