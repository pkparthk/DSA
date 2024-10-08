#include<bits/stdc++.h>
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

Node *ReverseLL(Node*head){
    Node *temp = head;
    Node *prev = NULL;
    while (temp!=NULL)
    {
        Node *nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;                
}

Node *getKthNode(Node *temp, int k){
    k -= 1;
    while (temp!=NULL && k>0)    
    {
        k--;
        temp = temp->next;        
    }
    return temp;
}

Node *ReverseNodeByKthGrp(Node *head, int k)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *temp = head;
    Node *prevLast = NULL;
    while (temp != NULL)
    {
        Node *KthNode = getKthNode(temp, k);
        if (KthNode == NULL)
        {
            if (prevLast)
            {
                prevLast->next = temp;                
            }                        
            break;
        }
        Node *nextNode = KthNode->next;
        KthNode->next = NULL;
        ReverseLL(temp);
        if (temp==head){
            head = KthNode;
        }
        else{
            prevLast->next = KthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = ConvertArrToLL(arr);
    print(head);
    head = ReverseNodeByKthGrp(head, 3);
    print(head);
    return 0;
}