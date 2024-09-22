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

Node * ConvertArrayToDLL(vector<int> &arr){
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

void print(Node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node *DeleteHead(Node*head){
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}


Node *DeleteTail(Node*head){
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node *tail = head;    
    while (tail->next!=NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head; 
}


Node *DeleteByK(Node *head, int k){
    if (head==NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *kNode = head;
    while (kNode!=NULL)
    {
        cnt++;
        if (cnt==k)
        {
            break;                        
        }
        kNode = kNode->next;
    }
    Node *prev = kNode->back;
    Node *front = kNode->next;
    if (prev==NULL && front==NULL)
    {
        return NULL;
    }
    else if (prev==NULL)
    {
        return DeleteHead(head);
    }
    else if (front==NULL)
    {
        return DeleteTail(head);
    }
    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}

Node* DeleteByNode(Node*temp){
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front==NULL)
    {
        prev->next = front;
        temp->back = prev;
        free(temp);
        return NULL;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    Node * head = ConvertArrayToDLL(arr);   

    // Delete the head
    // head = DeleteHead(head);

    // Delete the tail
    // head = DeleteTail(head);

    
    // Delete by K
    // int k;
    // cin>>k;
    // head = DeleteByK(head, k);


    // Delete by Node
    DeleteByNode(head);
    
    print(head);
    return 0; 
}