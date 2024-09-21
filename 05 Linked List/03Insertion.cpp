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

// Insert at Head (First)
Node* InserHead(Node*head, int val){
    Node *temp = new Node(val, head);
    return temp;
}


// Insert at tail(Last)
Node* InsertTail(Node*head, int val){
    if (head==NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// Insert at K
Node* InsertAtK(Node*head, int ele, int k){
    if (head==NULL)
    {
        if (k==1)
        {
            return new Node(ele);
        }
        return NULL;
    }    
    if (k==1)
    {
        Node *temp = new Node(ele, head);
        return temp;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp!=NULL)
    {
        cnt++;
        if (cnt==k-1)
        {
            Node *newNode = new Node(ele, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;    
}


// Before the value element
Node *InsertBeforeValue(Node *head, int ele, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data==val)
    {
        return new Node(ele, head);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *newNode = new Node(ele, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
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
    Node *head = ConvertArrToLL(arr);
    int val;
    cin >> val;
    
    // Insert at head
    // head = InserHead(head, val);

    // Insert at tail
    // head = InsertTail(head, val);


    // Insert at K
    // int k;
    // cin >> k;
    // head = InsertAtK(head, val, k);    

    // Insert Before Value
    int ele;
    cin >> ele;
    head = InsertBeforeValue(head, ele, val);
    print(head);
    return 0;
} 